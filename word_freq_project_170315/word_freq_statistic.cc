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
using std::cout;
using std::endl;
using std::map;
using std::ifstream;
using std::string;
using std::set;
using std::vector;
using std::istringstream;
using std::stringstream;

bool isnum(string s)
{
	stringstream sin(s);
	double t;
	char p;
	if(!(sin>>t))
		return false;
	else
		if(sin>>p)
			return false;
		else
			return true;
}

class TextQuery{
public:
	void readFile(const string filename);
	void query(const string & word);
	void display();
private:
	vector<string> _vecLines;
	map<string, set<int> > _mapWord2Line;
	map<string, int> _mapWordFreq;
};

void TextQuery::readFile(const string filename)
{
	ifstream ifs(filename);
		if(!ifs.good()){
			cout<<"ifstream open error!"<<endl;
			return;
		}
	string word;
	while(ifs >> word){
		bool flag=true;
		for(auto & ele:_mapWordFreq)
			if(word==ele.first)
			{
				flag=false;
				++ele.second;
				break;
			}
		if(flag && !isnum(word))
			_mapWordFreq[word]=1;
	

	ifs.close();

	ifstream ifs2(filename);
	string line;
	int count=1;
	while(getline(ifs2,line)){
		_vecLines.push_back(line);
		istringstream iss(line);
		while(iss>>word)
		{
			for(auto & ele:_mapWord2Line)
				if(word==ele.first){
					ele.second.insert(count);
					break;
				}
			if(!isnum(word))
				_mapWord2Line[word].insert(count);
		}
		++count;
	}
	ifs2.close();
}

void TextQuery::query(const string & word)
{
	cout<<"word:"<<word<<" all:"<<_mapWordFreq[word]<<endl;
	for(auto & ele:_mapWord2Line[word])		
		cout<<ele<<" "<<_vecLines[ele-1]<<endl;
	cout<<endl;
}

void TextQuery::display()
{
	for(auto &ele:_mapWordFreq)
		cout<<ele.first<<" "<<ele.second<<endl;
	cout<<endl;
}

int main(int argc,char** argv)
{
	if(2!=argc)
		printf("error argv!\n");
	string s1="will";
	TextQuery tq;
	tq.readFile(argv[1]);
	tq.query(s1);
	tq.display();
	
	return 0;
}
