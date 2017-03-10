#include <queue>
#include <iostream>
#include <stack>
#include <list>
#include <algorithm>
using std::cout;
using std::endl;
using std::stack;
using std::list;
using std::queue;

//stack,queue没有capacity()
int main(void)
{
	stack<int,list<int> > istack;
	istack.push(1);
	istack.push(3);
	istack.push(5);
	istack.push(7);

	cout << istack.size() << endl;
	cout << istack.top() << endl;

	istack.pop(); 
	cout<<istack.top() << endl;
	istack.pop(); 
	cout<<istack.top() << endl;
	istack.pop(); 
	cout <<istack.top() << endl;
	cout << "size:"<<istack.size()<<endl<<endl;


	queue<int,list<int>>iqueue;
	iqueue.push(1);
	iqueue.push(3);
	iqueue.push(5);
	iqueue.push(7);

	cout << "size:"<<iqueue.size() << endl;
	cout << iqueue.front() << endl;

	iqueue.pop(); 
	cout <<iqueue.front()<<endl;
	iqueue.pop();
	cout <<iqueue.front()<<endl;
	iqueue.pop(); 
	cout <<iqueue.front()<<endl;
	cout<<"size:"<<iqueue.size()<<endl<<endl;
	
	return 0;
}
