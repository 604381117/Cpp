#include <iostream>
#include <queue>
#include <vector>
using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;


//1.priority底层采用堆排序
//2.基础容器是vector，堆的下标与vector非常吻合，可以O(1)时间访问到元素
//3.比较函数默认使用std::less
//4.降序排列
//5.如果有新的元素添加，堆顶与新元素进行比较，true则替换为新堆顶
int main(void)
{
	int arr[10]={234,23546,57,658,6798790,345,234,23,42,3};
	
	//降序排列
	//priority_queue<int> priqueue;
	
	//升序排列
	priority_queue<int,vector<int>,std::greater<int>> priqueue;
	for(size_t i=0;i!=10;++i)
	{
		priqueue.push(arr[i]);
		cout<<"当前最高优先级元素:"<<priqueue.top()<<endl;
	}
	cout<<endl;
	
	while(!priqueue.empty()){	
		cout<<priqueue.top()<<" ";
		priqueue.pop();
	}

#if 0
	for(auto & ele:priqueue)
		cout<<ele<<" ";
	cout<<endl;
#endif

	while(!priqueue.empty())
	{
		cout<<priqueue.top()<<" ";
		priqueue.pop();
	}
	cout<<endl;
	return 0;

}
