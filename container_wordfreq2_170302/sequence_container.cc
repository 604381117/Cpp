#include <iostream>
#include <deque>
#include <vector>
#include <list>
using std::cout;
using std::endl;
using std::deque;
using std::list;
using std::vector;

template<typename container>
void printcontainer(container &c)
{
	typename container::iterator cit;
	for(cit=c.begin();cit!=c.end();++cit)
		cout<<*cit<<" ";
	cout<<endl;
}

//vector内部是数组/向量
//list是链表,双向循环串行前开后闭,deque即非链表又非数组
//dequeue内部由多段连续的线性空间拼接，中控器采用游标管理，（cur 1st 2nd node）
//end总是指向最后一个元素的下一个位置
int main(void)
{
	double a[5]={1,3,7,9,56};
	deque<double> dq1(a,a+5);
	printcontainer(dq1);

	deque<double> dq={34,-4,6,23,78,234,987786};//-std=c++11
	printcontainer(dq);
	
	for(size_t i=0;i!=dq.size();++i)
		cout<<dq[i]<<" ";
	cout<<endl;
	
	deque<double>::iterator it;
	for(it=dq.begin();it!=dq.end();++it)
		cout<<*it<<" ";
	cout<<endl<<endl;
	
	//list底层采用链表实现，未重载下标运算符
	//只支持双向迭代器
	list<float> lf={3,345,345,567,345,234,568};
	printcontainer(lf);
	list<float>::iterator lt;
	for(lt=lf.begin();lt!=lf.end();++lt)
		cout<<*lt<<" ";
	cout<<endl;
	
	list<float> lf2={-9,876,5,567,455,-234,-90};
	lf.swap(lf2);//指针交换，非数据交换
	printcontainer(lf);
	printcontainer(lf2);
	lf.pop_front();
	printcontainer(lf);
	cout<<endl<<endl;;

	//vector“单向”开口连续线性表，无pop_front
	vector<int>vi={234,456,678,345,345};
	printcontainer(vi);
	vi.pop_back();
	printcontainer(vi);
	cout<<"capacity:"<<vi.capacity()<<endl;
	
	//clear只是清空数据，内存空间未作任何变动
	vi.clear();
	printcontainer(vi);
	cout<<"capacity:"<<vi.capacity()<<endl;
	vi.shrink_to_fit();//回收多余无用的空间
	cout<<"capacity:"<<vi.capacity()<<endl;
	return 0;
}
