#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>
using std::cout;
using std::endl;
using std::vector;
using std::string;

void print(int num)
{
	cout<<num<<" ";
}

bool func(int num)
{
	return (num==888);
}

class comp{
public:
	bool operator()(int num)
	{
		return (num==999);
	}
};

int fun(int x,int y)
{
	return x*y;		
}

void f5(int n1,int n2,int n3,const int &n4,int n5)
{
	cout<<n1<<" "<<n2<<" "<<n3<<" "<<n4<<" "<<n5<<endl;
}

int main(void)
{
	//bind同样可绑定到成员函数上
	auto f1=std::bind(fun,45,-45);//返回一个函数
	cout<<f1()<<endl;
	auto f2=std::bind(fun,-45,std::placeholders::_1);//占位符_1, _2, ..._n
	cout<<f2(10)<<endl<<endl;

	vector<int>test;
	cout<<test.capacity()<<" "<<test.size()<<endl;
	vector<int> vecint={1,23,235,345,567,567,567,567};
	for_each(vecint.begin(),vecint.end(),print);
	cout<<endl;

	//反向迭代器
	vector<int>::reverse_iterator rit;
	for(rit=vecint.rbegin();rit!=vecint.rend();++rit)
		cout<<*rit<<" ";
	cout<<endl;
	
	std::less<int> lt;//less比较
	std::greater<int> gt;//greater比较
	replace_if(vecint.begin(),vecint.end(),bind2nd(gt,235),888);//bind2nd gt>345替换
	for_each(vecint.begin(),vecint.end(),print);
	cout<<endl;
	
	replace_if(vecint.begin(),vecint.end(),func,666);	
	for_each(vecint.begin(),vecint.end(),print);
	cout<<endl;

	replace_if(vecint.begin(),vecint.end(),bind1st(lt,560),999);//bind1st lt>500替换
	for_each(vecint.begin(),vecint.end(),print);
	cout<<endl;
	
	replace_if(vecint.begin(),vecint.end(),comp(),333);
	for_each(vecint.begin(),vecint.end(),print);
	cout<<"capacity:"<<vecint.capacity()<<endl;
	
	vecint[1]=vecint[2]=vecint[6]=110;
	for(auto & ele:vecint)
		cout<<ele<<" ";
	cout<<"capacity:"<<vecint.capacity()<<endl;
	
	//remove返回的是一个删除的起始位置，从此位置往后的全是应该删除的数据
	//遍历过程中并未作删除操作，目的为了防止迭代器失效,真正实现删除需调用erase
	//erase后容量未做改变？
	vecint.erase(remove(vecint.begin(),vecint.end(),110),vecint.end());
	for_each(vecint.begin(),vecint.end(),print);
	cout<<"capacity:"<<vecint.capacity()<<endl<<endl;
	
#if 1
	bool flag=true;
	vector<string> vecstr;
	vecstr.push_back("aaaaaaaaaa");
	vector<string>::iterator it;
	for(it=vecstr.begin();it!=vecstr.end();++it)
	{
		cout<<"size:"<<vecstr.size()<<" "<<*it<<endl;
		if(flag)
		{
			//段错误
			//容器遍历过程中添加或删除数据，会导致内存空间重新分配，
			//原来的it指向已经被释放掉，要想重新访问需要重新遍历
			vecstr.push_back("bbbbbbbbbb");
			for_each(vecstr.begin(),vecstr.end(),print);
			cout<<"capacity:"<<vecstr.capacity()<<" "<<*it<<endl;
			flag=false;
		}
	}
#endif

	return 0;
}

