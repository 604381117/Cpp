#include <iostream>
using std::cout;
using std::endl;


class A
{
public:
	//声明了纯虚函数的类称为抽象类, 不能实例化对象
	virtual void display()=0;//纯虚函数,没有实现,只有声明

	virtual void print()=0;
};
class B : public A
{//B没有重定义纯虚函数print,它也成为一个抽象类
public:
	virtual void display()
	{
		cout << "B::display()" << endl;
	}
};

class C : public B
{
public:
	virtual void  print()
	{
		cout << "C::print()" << endl;
	}
};

int main(void)
{
	//A a;//Error
	A * p = new C;
	p->display();
	p->print();
	
	cout<<"sizeof(A)="<<sizeof(A)<<endl;
	cout<<"sizeof(B)="<<sizeof(B)<<endl;
	cout<<"sizeof(C)="<<sizeof(C)<<endl;
	return 0;
}
