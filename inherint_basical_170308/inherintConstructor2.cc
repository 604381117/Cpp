#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
#if 1
	Base()
	{
		cout << "Base()" << endl;
	}
#endif

	//当基类提供有参构造函数时，系统就不会再提供默认构造函数

	Base(int i)
	{
		cout << "Base(int)" << endl;
	}
};


class Derived 
: public Base
{
public:
	//当基类有显式定义构造函数时，派生类没有显式定义，
	//则创建派生类对象时，一定会调用基类的默认构造函数，
	//所以必须会基类显式提供一个默认构造函数
#if 0
	Derived()
	{
		cout << "Derived()" << endl;
	}

	Derived(int i)
	{
		cout << "Derived(int)" << endl;
	}
#endif
};

int main(void)
{
	Derived d1;

	return 0;
}
