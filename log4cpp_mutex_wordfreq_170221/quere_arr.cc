#include <iostream>
using std::cout;
using std::endl;
#define MAXSIZE 10

class Queue{
public:
	Queue()
	{
		_front=_rear=0;
	}
	
	bool push(int num)
	{
		if(full())
			return false;
		_data[_rear]=num;
		_rear=(_rear+1)%MAXSIZE;
		return true;
	}	

	void pop()
	{
		if(empty())
			return;
		_front=(_front+1)%MAXSIZE;
	}
	
	int front()
	{
		if(empty())
			return -1;
		return _data[_front];
	}

	int back()
	{
		if(empty())
			return -1;
		return _data[(_rear+MAXSIZE-1)%MAXSIZE];
	}

	bool empty()
	{
		if(_front==_rear)
			return true;
		else 
			return false;
	}
	
	bool full()
	{
		if((_rear+1)%MAXSIZE==_front)
			return true;
		else
			return false;
	}
private:
	int _data[MAXSIZE];
	int _front,_rear;
};

int main(void)
{
	Queue st;
	st.push(10);
	st.push(12);
	st.push(14);
	cout << "队头="<<st.front()<< " 队尾="<<st.back()<<endl;
	st.pop();
	cout << "队头="<<st.front()<< " 队尾="<<st.back()<<endl;
	return 0;
}
