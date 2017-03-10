#include <iostream>
using std::cout;
using std::endl;
#define MAXSIZE 10

class Stack{
public:
	Stack()
	{
		_top=-1;
	}
	
	bool push(int num)
	{
		if(full())
			return false;
		_data[++_top]=num;
			return true;
	}	

	bool pop(int &num)
	{
		if(empty())
			return false;
		num=_data[_top--];
			return true;
	}
	
	int top()
	{
		if(empty())
			return false;
		return _data[_top];
	}
	
	bool empty()
	{
		if(-1==_top)
			return true;
		else 
			return false;
	}
	
	bool full()
	{
		if(MAXSIZE-1==_top)
			return true;
		else
			return false;
	}
private:
	int _data[MAXSIZE];
	int _top;
};

int main(void)
{
	Stack st;
	st.push(10);
	st.push(12);
	st.push(14);
	int num;
	cout << "栈顶="<<st.top()<<endl;
	st.pop(num);
	cout << "栈顶="<<st.top()<<endl;
	return 0;
}
