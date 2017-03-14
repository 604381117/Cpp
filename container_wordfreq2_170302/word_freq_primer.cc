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
			auto & lines = wm[word];//lines为一个指向set<line_no>的shared_ptr
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

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	while(1){
		cout<<"enter word you find,or q to quit:";
		string s;
		if(!(cin >> s || s == "q"))	break;
		print(cout,tq.query(s));//   重载输出运算符
	}
}

int main(int argc,char** argv)
{
	if(2 != argc)
		printf("error argv!\n");
	ifstream ifs(argv[1]);
	if(!ifs){
		cout << "ifstream open error!" << endl;
		return -1;
	}
	
	runQueries(ifs);

}
