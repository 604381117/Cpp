#pragma comment(lib,"json_mtd.lib")

#include "json/json.h"
#include <cassert>
#include <fstream>
#include <iterator>
#include <vector>
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::string;
using std::iterator;
using std::vector;

int main(void)
{
	Json::Value root;
	Json::FastWriter writer;
	Json::Value temp[6];
	temp[0]["title"]="周末小结--重点:";
	temp[1]["A"]="STL中几种容器的使用";
	temp[2]["B"]="bind函数适配器";
	temp[3]["C"]="理解std::allocator的内存池模型";
	temp[4]["D"]="理解移动语义";
	temp[5]["E"]="理解RAII技术的原理,熟悉unique_ptr/shared_ptr/weak_ptr的使用";
	
	ofstream ofs("json.json",std::ios::app);
	if(!ofs.good()){
		cout<<"ofs open failed!"<<endl;
		return -1;
	}
	
	for(int idx=0;idx<6;++idx)
		root.append(temp[idx]);
	string json_file=writer.write(root);
	ofs<<json_file;
	ofs.close();
	
	ifstream ifs("json.json");
	if(!ifs.good()){
		cout << "ifsopen error" << endl;
		return -1;
	}

	Json::Reader reader;
	Json::Value tmp[6];
	vector<Json::Value> vstr;
	for(int idx=0;idx<6;++idx)
		if (!reader.parse(ifs, tmp[idx], false))
			return -1;
		else
			cout<<tmp[idx]<<" ";
	
	return 0;
}
