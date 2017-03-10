#include <json/json.h>
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::ofstream;


int main(void)
{
	Json::Value root;
	Json::Value arr;

	Json::Value elem;
	elem["title"] = "百度";
	elem["url"] = "www.baidu.com";
	elem["abstract"] = "王道";

	arr.append(elem);
	elem["title"] = "阿里巴巴";
	elem["url"] = "www.1688.com";
	elem["abstract"] = "批发商";
	arr.append(elem);

	elem["title"] = "腾讯";
	elem["url"] = "www.qq.com";
	elem["abstract"] = "社交";
	arr.append(elem);

	root["BAT"] = arr;

	Json::FastWriter writer;
	//Json::StyledWriter writer;
	string msg = writer.write(root);
	cout << msg << endl;

	ofstream ofs("bat.json");
	ofs << msg;
	ofs.close();

	return 0;
}
