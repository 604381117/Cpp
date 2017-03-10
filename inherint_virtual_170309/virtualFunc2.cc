#include <iostream>
using std::cout;
using std::endl;


class Base
{
public:
	virtual
	void display()
	{
		cout << "Base::display()" << endl;
	}
private:
	double _d0;
};

class Child1 : public Base
{
public:
#if 1
	//virtual 
	void display()
	{
		cout << "Child1::display()" << endl;
	}
#endif
private:
	double _d1;
};

class Child2 : public Base
{
public:
	//virtual 
	void display()
	{
		cout << "Child2::display()" << endl;
	}
private:
	double _d2;
};


//虚函数机制发生的条件:
//1. 基类定义了虚函数,派生类覆盖了基类的虚函数
//2. 基类的指针或引用指向派生类对象
//3. 基类的指针或引用调用虚函数
//中间多了一张虚表, 多了一层间接性

void display(Base * pb)
{
	pb->display();
}


int main(void)
{
	Base base;
	Child1 child1;//直接通过对象名进行调用, 并不涉及到虚函数的特性,直接到方法区找相应的函数
	Child2 child2;
#if 1
	base.display();
	child1.display();//发生的是隐藏
	child2.display();
#endif

	cout<<"sizeof(double=)"<<sizeof(double)<<endl;
	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(Child1) = " << sizeof(Child1) << endl;
	cout << "sizeof(Child2) = " << sizeof(Child2) << endl;

	display(&base);
	display(&child1);
	display(&child2);

	return 0;
}
