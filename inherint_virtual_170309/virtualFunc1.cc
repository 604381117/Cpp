#include <iostream>
using std::cout;
using std::endl;


class Base
{
public:
	virtual
	int func(int x)
	{
		cout << "Base::func(int)" << endl;
		return x;
	}
};


class Sub
: public Base
{
public:
	//virtual
	int func(int x)
	{
		cout << "Sub::func(int)" << endl;
		//return (float)x;
		return x;
	}
};

int main(void)
{
	
	return 0;
}
