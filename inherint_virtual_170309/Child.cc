#include <iostream>
using std::cout;
using std::endl;


class Base 
{
public:
	virtual void display()
	{
		cout << "Base::display()" << endl;
	}

	void print()
	{
		cout << "Base::print()" << endl;
	}
};


class Child : public Base
{
public:
	void display()
	{
		cout << "Child::display()" << endl;
	}

	void print()
	{
		cout << "Child::print()" << endl;
	}
};


int main(void)
{

	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(Child) = " << sizeof(Child) << endl;

	Base base;
	Base * pbase = &base;
	pbase->display();

	Child child;
	Child * pChild = &child;
	pChild->display();
	cout << endl;


	pbase = & child;
	pbase->display();
	pbase->print();
	cout << endl;


	pChild = (Child*)&base;//pChild本身的类型是Child类型,打印的结果是基类的display()
	pChild->display();
	pChild->print();

	return 0;
}


int test()
{
	Base base;
	Child child;

	Base & ref1 = base;
	ref1.display();
	ref1.print();
	cout << endl;

	Base & ref2 = child;
	ref2.display();//Child::display()
	ref2.print();//Base::print();

}
