#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

template <typename T,int size=10>
class Stack{
public:
	Stack();
	~Stack()
	{}
	bool empty();
	bool full();
	void push(const T&);
	T pop();
	
private:
	int _top;
	T _arr[size];
};

template<typename T,int size>
Stack<T,size>::Stack()
:_top(-1)
{}

template<typename T,int size>
bool Stack<T,size>::empty()
{
	return _top==-1;
}

template<typename T,int size>
bool Stack<T,size>::full()
{
	return _top==size-1;
}

template<typename T,int size>
void Stack<T,size>::push(const T& ele)
{
	if(!full())
		_arr[++_top]=ele;
	else
		cout<<"栈满"<<endl;
}

template<typename T,int size>
T Stack<T,size>::pop()
{
	if(!empty())
		return _arr[_top--];
	else
		cout<<"栈空"<<endl;
}

int main(void)
{
	Stack<string> st;
	cout<<st.empty()<<endl;
	for(int i=4;i<14;++i)
	{
		char ch=i+'A';
		string s(5,ch);
		st.push(s);
	}
	cout<<st.full()<<endl;
	for(int i=0;i<10;i++)
		cout<<st.pop()<<" ";
	cout<<endl<<st.empty()<<endl;
	return 0;
}

