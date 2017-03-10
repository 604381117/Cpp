#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

template <typename T,int size=10>
class Queue{
public:
	Queue();
	~Queue()
	{}
	bool empty();
	bool full();
	void push(const T&);
	T pop();
	T front();
	T rear();
private:
	int _front,_rear;
	T _arr[size];
};

template<typename T,int size>
Queue<T,size>::Queue()
{
	_front=_rear=0;
}

template<typename T,int size>
bool Queue<T,size>::empty()
{
	return _front==_rear;
}

template<typename T,int size>
bool Queue<T,size>::full()
{
	return ((_rear+1)%size==_front);
}

template<typename T,int size>
void Queue<T,size>::push(const T& ele)
{
	if(!full()){
		_arr[_rear]=ele;
		_rear=(_rear+1)%size;
	}else
		cout<<"队满"<<endl;
}

template<typename T,int size>
T Queue<T,size>::pop()
{
	if(!empty()){
		T temp=_arr[_front];
		_front=(_front+1)%size;
		return temp;
	}else{
		cout<<"队空"<<endl;
	}
}

template<typename T,int size>
T Queue<T,size>::front()
{
	if(!empty())
		return _arr[_front];
	else
		cout<<"队空"<<endl;
}

template<typename T,int size>
T Queue<T,size>::rear()
{
	if(!empty())
		return _arr[(_rear+size-1)%size];
	else
		cout<<"队空"<<endl;
}

int main(void)
{
	Queue<string> qu;
	cout<<qu.empty()<<endl;
	for(int i=0;i<10;++i)
	{
		char ch=i+'A';
		string s(5,ch);
		qu.push(s);
	}
//	for(int i=0;i<10;i++)
//		cout<<qu.front()<<" ";
	for(int i=0;i<9;i++)
		cout<<qu.pop()<<" ";
	cout<<qu.empty()<<endl;
	return 0;
}

