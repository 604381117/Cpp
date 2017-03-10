#include <string.h>
#include <strings.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <algorithm>
#include <cmath>
#include <sstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using std::stringstream;

typedef struct wordstatic{
	string words;
	int count;
}word;

bool compare(word &a,word &b)
{
	return a.words<b.words;
}

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

class WordStatistic{
public:
	WordStatistic()
	{
		vecword.reserve(1000);
	}

#if 0
	bool compare(vector<word> &a,vector<word> &b)
	{
		return (int)a.words>(int)b.words;
	}
#endif
	void readFile(const char *filename)
	{
		string str;
		ifstream ifs(filename);
		if(!ifs.good()){
			cout<<"ifstream open error!"<<endl;
			return;
		}
		while(ifs>>str){
			int i;
			for(i=0;i!=vecword.size();++i)
			{
				if(str==vecword[i].words)
				{
					++vecword[i].count;
					break;
				}
			}

			if(i==vecword.size()){
				if(!isnum(str)){
				word _word;
				_word.words=str;
				_word.count=1;
				vecword.push_back(_word);
				}
			}
		}
		ifs.close();
		sort(vecword.begin(),vecword.end(),compare);
	}
	
	void writeFile()
	{
		ofstream ofs("word_freq_statistic.txt");
		if(!ofs.good()){
			cout<<"_ofstream open error!"<<endl;
			return;
		}
		cout<<vecword.size()<<endl;
		for(auto & elem : vecword){
			ofs << elem.words << " "<< elem.count <<endl;	
		}
	}
private:
	vector<word> vecword;
};

int main(int argc,char** argv)
{
	if(2!=argc){
		cout<<"input absolutely path filename!"<<endl;
		return -1;
	}
	WordStatistic W;
	W.readFile(argv[1]);
	W.writeFile();
	return 0;
}
