#include <iterator>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using std::cout;
using std::endl;
using std::set;
using std::string;
using std::multiset;
using std::map;
using std::pair;
using std::ostream_iterator;
using std::istream_iterator;
using std::cin;
using std::vector;

//set,map可保证查找，添加，删除元素时，时间复杂度为O(logn),二分查找
template<typename container>
void printcontainer(container &c)
{
	typename container::iterator it;
	for(it=c.begin();it!=c.end();++it)
		cout<<*it<<" ";
	cout<<endl;
}

int main(void)
{
	//set默认从小到大排列less，不可存放相同关键字
	//set底层实现为一棵红黑树，也是平衡二叉树，可实现二分查找
	//自定义类型实现排序，必须重载 < 或 > 符号
	set<int>si2={-34,456,678,234,345,457,68,68};
	printcontainer(si2);
	cout<<endl;
	
	set<int,std::greater<int>> si={-34,456,678,234,345,457,68,68};
	printcontainer(si);
	cout<<endl;

	set<string> ss={"sdgfg","qwetgh","yhgetry654,/.","54wersxc","aaadfg"};
	printcontainer(ss);
	cout<<endl;

	set<string,std::greater<string>> ss2={"sdgfg","qwetgh","yhgetry654,/.","54wersxc","aaadfg"};
	printcontainer(ss2);
	cout<<endl;
	

	//multiset可存放相同的关键字，默认升序排列
	multiset<int>si3={-34,456,678,234,345,457,68,68};
	printcontainer(si3);
	cout<<endl;

	multiset<int,std::greater<int>> si4={-34,456,678,234,345,457,68,68};
	printcontainer(si4);
	cout<<endl;


	//map内部也为红黑树，不支持随机访问，可访问下标
	//map不可存放相同关键字的值，multimap可以
	pair<int,string> t(600036,"zhaohang");
	cout<<t.first<<"--"<<t.second<<endl;
	
	//降序排列形式map<int,string,greater<int/关键字>>
	map<int,string> ms/* pair<int,string> ist[4]= */={ pair<int,string>(1,"wangdap"),pair<int,string>(2,"akhsdlgjh"),
					 	 pair<int,string>(5,"wangdap"),
					  	 pair<int,string>(2,"linux")};
	pair<int,string> ist(3,"ahdklf");
	pair<map<int,string>::iterator,bool>ret=ms.insert(ist);
	if(ret.second)
		cout<<"insert success"<<endl;
	else
		cout<<"原容器中已有关键字相同的元素，插入失败"<<endl;
	map<int,string>::iterator mt;
	for(mt=ms.begin();mt!=ms.end();++mt)
	{
		cout<<mt->first<<"--"<<mt->second<<endl;
		cout<<(*mt).first<<"--"<<(*mt).second<<endl;
	}
	cout<<endl;
	cout<<"size:"<<ms.size()<<endl;
	
	//支持关键字访问,而不是下标遍历
	//可存放自定义类型，但同样需重载 > 或 < 符号
	for(int i=1;i<=ms.size();++i)
		cout<<"-"<<ms[i]<<"-"<<endl;
	cout<<endl;
	
	for(auto &ele:ms)//ele代表的是pair对象
		cout<<ele.first<<"--"<<ele.second<<endl;
	cout<<endl;
	
	ostream_iterator<int> os(cout," ");
	std::copy(si3.begin(),si3.end(),os);
	cout<<endl;

	vector<int> vit;
	istream_iterator<int> isi(cin);//输入完后按ctrl+d结束输入
	std::copy(isi,istream_iterator<int>(),back_inserter(vit));
	printcontainer(vit);
	return 0;
}
