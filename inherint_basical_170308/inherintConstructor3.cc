#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:

	Base()
	{ cout << "Base()" << endl;	}

	Base(int base)
	: _base(base)
	{
		cout << "Base(int)" << endl;
	}
private:
	int _base;
};

class Derived 
: public Base
{
public:
	//当基类没有显式定义构造函数时，创建派生类对象时，
	//会自动调用基类的默认构造函数
	Derived()
	: Base() //显式调用基类的无参构造函数
	{
		cout << "Derived()" << endl;
	}

	Derived(int i, int j)
	: Base(i) // 一定要显式调用基类的有参构造函数
	, _drived(j)
	{
		cout << "Derived(int)" << endl;
	}
private:
	int _drived;
};

int main(void)
{
	Derived d1(1, 2);


	return 0;
}
