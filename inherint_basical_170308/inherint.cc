#include <iostream>
using std::cout;
using std::endl;

class A{
public:
	A(int ix=0)
	:_ix(ix)
	{
		cout<<"A(int)"<<endl;
	}

	~A()
	{
		cout<<"~A()"<<endl;
	}
private:
	int _ix;
};

class B{
public:
	B(int iy)
	:_iy(iy)
	{
		cout<<"B(int)"<<endl;
	}
	
	~B()
	{
		cout<<"~B()"<<endl;
	}
private:
	int _iy;
};

class C:public A
{
public:
	C(int ix,int iy,int iz)
	:A(ix) //以类名的方式构造
	,_iz(iz)
	,b(iy) //以对象的方式构造
	{
		cout<<"C(int int int)"<<endl;
	}
	
	~C()
	{
		cout<<"~C()"<<endl;
	}
private:
	B b;
	int _iz;
};


class Base{
public:
	int func(int ix)
	{
		cout<<"Base::_ix="<<_ix<<endl;//为何不是随机值，为何为1？？？
		return ix;
	}
public:
	int _ix;
};

class Derived :public Base
{
public:
	//派生类的同名的函数隐藏了基类的同名函数
	int func()
	{
		//_ix=9;//派生类的数据成员隐藏了基类的同名数据成员
		//Base::_ix=22;
		//cout<<"Base::_ix="<<Base::_ix<<endl;
		cout<<"Derived::_ix="<<Derived::_ix<<endl;
		return _ix;
	}
private:
	int _ix;
};

class Eye{
public:
	void look()
	{
		cout<<"Eye::look()"<<endl;
	}
};
class Nose{	
public:
	void smell()
	{
		cout<<"Nose::smell()"<<endl;
	}
};
class Mouth{
public:
	void eat()
	{
		cout<<"Mouth::eat()"<<endl;
	}
};
class Ear{
public:
	void listen()
	{
		cout<<"Ear::listen()"<<endl;
	}
};
class Head
:public Eye
,public Nose
,public Ear
,public Mouth
{};

class HeadEx{
public:
	void look()
	{
		cout<<"Eye::look()"<<endl;
	}

	void smell()
	{
		cout<<"Nose::smell()"<<endl;
	}

	void listen()
	{
		cout<<"Ear::listen()"<<endl;
	}

	void eat()
	{
		cout<<"Mouth::eat()"<<endl;
	}
	
private:
	Eye _eye;
	Mouth _mouth;
	Nose _nose;
	Ear _ear;
};
//基类的构造和析构顺序只与其声明顺序有关
//与基类在派生类中的初始化方式无关
int main(void)
{
	{
	C c(12,345,3465);//析构与构造顺序
	Derived d;
	cout<<d.func()<<endl;
	//cout<<d.func(23)<<endl;//同名函数被隐藏,如需调用必须加上作用域限定符
	cout<<"d.Base::func(5678)="<<d.Base::func(5678)<<endl;
	Base b1;
	Base *p;
	Derived d1;
	b1=d1;//派生类赋值给基类可以，反过来不可
	Base *p=d1;//可将基类的指针指向派生类，反过来非法
	cout<<"d1.func()="<<d1.func()<<endl;
	}
	
	cout<<endl;
	cout<<"--is a--"<<endl;//组合与派生
	Head head;
	head.eat();
	head.smell();
	head.look();
	head.listen();
	cout<<"--has a--"<<endl;
	HeadEx headEx;
	headEx.eat();
	headEx.smell();
	headEx.look();
	headEx.listen();

	
	//派生类与基类间的拷贝构造机制
		

	return 0;
}
