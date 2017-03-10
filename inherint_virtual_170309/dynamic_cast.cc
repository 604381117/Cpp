#include <iostream>
using std::cout;
using std::endl;


class Base
{
public:
	Base(double d1)
	: _d1(d1)
	{
	}

	void display()
	{
		cout << "Base::_d1 = " << _d1 << endl;
	}
private:
	double _d1;
};


class Derived 
: public Base
{
public:
	Derived(double d1, double d2)
	: Base(d1)
	, _d2(d2)
	{
	
	}

	void display()
	{
		Base::display();
		cout<< "Derived:_d2 = " << _d2 << endl;
	}

private:
	double _d2;
};


int main(void)
{
	Base base(1.1);
	Base base2 = base;
	base2.display();

	Base base3(2.2);
	base = base3;
	base.display();

#if 0

	base.display();

	Derived derived(2.2, 3.3);
	derived.display();
	cout << endl;

	Base * p1 = &base;
	
	Derived * p2 = (Derived *) p1;//不安全的转换
	p2->display();

#endif


#if 0

	Derived * p3 = dynamic_cast<Derived*>(p1);
	if(p3){
		p3->display();
	}else
	{
		cout << "类型转换不安全" << endl;
	}
#endif


	return 0;
}





