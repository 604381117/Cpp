 ///
 /// @file    json.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-08 10:34:20
 ///
 
#include <json/json.h>
#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main(void)
{
	ifstream ifs("test.json");
	if(!ifs.good())
	{	cout << "ifstream open error!" << endl; return -1;}
	
	Json::Reader reader;
	Json::Value root;

	if(!reader.parse(ifs, root, false))
	{
		cout << "json parse error!" << endl;
		ifs.close();
		return -1;
	}

	string title;
	string url;
	string abstract;
	Json::Value arr = root["BAT"];
	for(size_t idx = 0; idx != arr.size(); ++ idx)
	{
		title = arr[idx]["title"].asString();
		url = arr[idx]["url"].asString();
		abstract = arr[idx]["abstract"].asString();
		cout << "title:" << title << endl;
		cout << "url:" << url << endl;
		cout << "abstract:" << abstract << endl;
		cout << endl;
	}

	return 0;
}
