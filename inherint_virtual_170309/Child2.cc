#include <iostream>
using std::cout;
using std::endl;


class Base 
{
public:
	//virtual
	Base()
	{
	
	}


	virtual void display()
	{
		cout << "Base::display()" << endl;
	}

	void callBase1()
	{
		//this->display();
		display();//也表现出多态性
	}

	void callBase2()
	{
		Base::display();//直接去方法区找函数
	}
};


class Child : public Base
{
public:
	void display()
	{
		cout << "Child::display()" << endl;
	}

	void callChild1()
	{
		display();
	}
};


int main(void)
{
	Base base;
	Child child;


	base.callBase1();
	child.callChild1();

	Base * p1 = &base;
	p1->callBase1();
	p1->callBase2();
	cout << endl;

	Base * p2 = &child;
	p2->callBase1();
	p2->callBase2();

	return 0;
}

