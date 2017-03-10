#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}
};

class Derived 
: public Base
{
public:
	//当基类没有显式定义构造函数时，创建派生类对象时，
	//会自动调用基类的默认构造函数
	Derived()
	{
		cout << "Derived()" << endl;
	}

	Derived(int i)
	{
		cout << "Derived(int)" << endl;
	}
};

int main(void)
{
	Derived d1;


	return 0;
}
