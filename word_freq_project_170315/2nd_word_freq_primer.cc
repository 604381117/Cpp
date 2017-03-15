 ///
 /// @file    txtquery.cc
 /// @author  yy(jobyang@163.com)
 /// @date    2017-03-09 20:21:19
 ///
#include <string.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <stack>
#include <memory>
using std::cout;
using std::endl;
using std::map;
using std::ifstream;
using std::string;
using std::set;
using std::vector;
using std::istringstream;
using std::stringstream;
using std::shared_ptr;
using std::cin;
using std::set_intersection;
using std::make_shared;
using std::pair;
using std::stack;

class QueryResult;

using line_no = vector<string>::size_type;

string make_plural(size_t ctr,const string word, const string ending)
{
	return (ctr > 1) ? word + ending : word;
}

class TextQuery{
public:
//	using line_no = vector<string>::size_type;
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is)
: file(new vector<string>)
{
	string text;
	while(getline(is, text)){
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while(line >> word){
			auto & lines = wm[word];
			if(!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

class QueryResult{
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<set<line_no>> p,
						  shared_ptr<vector<string>> f)
						  :sought(s),lines(p),file(f){ }

	set<line_no>::iterator begin()
	{	return lines->begin();	}
	
	set<line_no>::iterator end()
	{	return lines->end();	}
	
	shared_ptr<vector<string>> get_file()
	{	return file;	}

private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
};

QueryResult
TextQuery::query(const string &sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

std::ostream & print(std::ostream & os, const QueryResult & qr)
{
	os << qr.sought << " occurs " <<qr.lines->size() <<" "
	   << make_plural(qr.lines->size(), "times", "s") <<endl;
	for(auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") "
		   <<*(qr.file->begin() + num) <<endl;
	return os;
}

class Query_base{
	friend class Query;
protected:
	//using line_no=TextQuery::line_no;
	virtual ~Query_base()=default;
private:
	virtual QueryResult eval(const TextQuery&) const =0;
	virtual string rep() const =0;
};

class Query{
	friend Query operator ~(const Query&);
	friend Query operator |(const Query&,const Query&);
	friend Query operator &(const Query&,const Query&);
public:
	Query(const string&);
	
	QueryResult eval(const TextQuery &t) const
	{ return q->eval(t); }

	string rep() const
	{ return q->rep(); }

private:
	Query(shared_ptr<Query_base> query)
	:q(query)
	{ }

	shared_ptr<Query_base> q;
};

std::ostream & operator<<(std::ostream &os,const Query &query)
{
	return os<<query.rep();
}


class WordQuery:public Query_base
{
	friend class Query;
	
	WordQuery(const string &s)
	:query_word(s)
	{ }
	
	QueryResult eval(const TextQuery &t) const
	{ return t.query(query_word); }
	
	string rep() const
	{ return query_word; }

	string query_word;
};

inline Query::Query(const string &s)
:q(new WordQuery(s))
{ }


class NotQuery:public Query_base
{
	friend Query operator~(const Query&);
	
	NotQuery(const Query &q)
	:query(q)
	{ }

	string rep() const
	{ return "~(" + query.rep() + ")"; }

	QueryResult eval(const TextQuery&) const;

	Query query;
};


inline Query operator~(const Query &operand)
{
	return shared_ptr<Query_base> (new NotQuery(operand));
}

class BinaryQuery:public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, string s)
	:lhs(l)
	,rhs(r)
	,opSym(s)
	{ }

	string rep() const
	{
		return "("+lhs.rep()+" "+opSym+" "+rhs.rep()+")";
	}

	Query lhs,rhs;
	string opSym;
};

class AndQuery:public BinaryQuery
{
	friend Query operator&(const Query&,const Query&);

	AndQuery(const Query &left,const Query &right)
	:BinaryQuery(left,right,"&")
	{ }
	
	QueryResult eval(const TextQuery&) const;
};

inline Query operator &(const Query & lhs,const Query & rhs)
{
	return shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}

class OrQuery:public BinaryQuery
{
	friend Query operator|(const Query&,const Query&);

	OrQuery(const Query &left,const Query &right)
	:BinaryQuery(left,right,"|")
	{ }

	QueryResult eval(const TextQuery&)const;
};

inline Query operator|(const Query & lhs,const Query & rhs)
{
	return shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}

QueryResult 
OrQuery::eval(const TextQuery & text)const
{
	auto right=rhs.eval(text),left=lhs.eval(text);

	auto ret_lines=make_shared<set<line_no>>(left.begin(),left.end());

	ret_lines->insert(right.begin(),right.end());
	return QueryResult(rep(),ret_lines,left.get_file());
}

QueryResult AndQuery::eval(const TextQuery & text)const
{
	auto left=lhs.eval(text),right=rhs.eval(text);
	auto ret_lines=make_shared<set<line_no>>();
	set_intersection(left.begin(),left.end(),right.begin(),right.end(),
							      inserter(*ret_lines,ret_lines->begin()));
	return QueryResult(rep(),ret_lines,left.get_file());
}

QueryResult NotQuery::eval(const TextQuery & text)const
{
	auto result =query.eval(text);
	auto ret_lines=make_shared<set<line_no>>();
	auto beg=result.begin(),end=result.end();
	auto sz=result.get_file()->size();
	for(size_t n=0;n!=sz;++n){
		if(beg==end||*beg!=n)
			ret_lines->insert(n);
		else if(beg!=end)
			++beg;
	}
	
	return QueryResult(rep(),ret_lines,result.get_file());
};

class Parse{
public:
	Parse();
	void doParse(TextQuery &tq);
	void writePost(const  string & rhs);
public:
	enum Priority{
	STR=0,
	RIGHTBRACKET=1,
	OR=2,
	AND=3,
	NEGATION=4,
	LEFTBRACKET=5
	};
	pair<Priority,string> convert(const string & rhs);
	shared_ptr<vector<pair<Priority,string> > >	 _postExpresion;
};

Parse::Parse()
:_postExpresion(new vector<pair<Priority,string> >)
{ }

pair<Parse::Priority,string> Parse::convert(const string & word)
{
	switch(word[0])
	{
		cout<<word[0]<<endl;
		case ')':return make_pair(RIGHTBRACKET,word);break;
		case '|':return make_pair(OR,word);break;
		case '&':return make_pair(AND,word);break;
		case '(':return make_pair(LEFTBRACKET,word);
		case '~':return make_pair(NEGATION,word);break;
		default:break;
	}
	return make_pair(STR,word);
}

void Parse::writePost(const string & rhs)
{
	istringstream iss(rhs);
	string word;
	stack<pair<Parse::Priority,string>> _stack;
	while(iss>>word)
	{
		pair<Parse::Priority,string> tmp=convert(word);
		if(tmp.first==STR)
		{
			_postExpresion->push_back(tmp);
		}else if(tmp.first==RIGHTBRACKET){
			while(!_stack.empty()&&_stack.top().first!=LEFTBRACKET)
			{
				_postExpresion->push_back(_stack.top());
				_stack.pop();
			}
			if(_stack.top().first==LEFTBRACKET)
			{
				_stack.pop();
			}
		}else if(tmp.first==LEFTBRACKET){
			_stack.push(tmp);
		}else if(_stack.empty()||tmp.first > _stack.top().first){
			_stack.push(tmp);
		}else{
			while(!_stack.empty()&&tmp.first < _stack.top().first)
			{
				_postExpresion->push_back(_stack.top());
				_stack.pop();
			}
			_stack.push(tmp);
		}
	}
	while(!_stack.empty())
	{
		_postExpresion->push_back(_stack.top());
		_stack.pop();
	}
}

void Parse::doParse(TextQuery &tq)
{
	stack<Query> result;
	for(auto & elem : *(_postExpresion))
	{
		if(elem.first==STR)
		{
			result.push(Query(elem.second));
		}else{
			switch(elem.second[0])
			{
				case '~':
					{
						result.push(~result.top());
						result.pop();
						break;
					}
				case '&':
					{
						Query right=result.top();
						result.pop();
						Query left=result.top();
						result.pop();
						result.push(right & left);
						break;
					}
				case '|':
					{
						Query right=result.top();
						result.pop();
						Query left=result.top();
						result.pop();
						result.push(right | left);
						break;
					}
			}
		}
	}
	//while(10);
	print(cout,result.top().eval(tq));
}

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
#if 0
	Query q=~Query("fiery")&Query("and")&Query("i");
	//Query q=~Query("i");
	print(cout,q.eval(tq));
#endif
	Parse p;
	while(1){
		cout<<"enter word you find,or q to quit:";
		string s;
		cin >> s;
		p.writePost(s);
		p.doParse(tq);
		//print(cout,p.doParse().eval(tq));
	}
}

int main(void)
{
	ifstream ifs("/home/xy/The_Holy_Bible.txt");
	if(!ifs){
		cout << "ifstream open error!" << endl;
		return -1;
	}
	
	runQueries(ifs);
	return 0;
}

