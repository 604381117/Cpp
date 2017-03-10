#include <iostream>
using std::cout;
using std::endl;

class Base
{//抽象类的第二种形式-->不能实例化对象
protected:
	Base(int ix)
	: _ix(ix)
	{}

public:
	void display()
	{
		cout << "Base::_ix = " << _ix << endl;
	}
private:
	int _ix;
};

class Child : public Base
{
public:
	Child(int ix)
	: Base(ix)
	{
		cout << "Child(ix)" << endl;
	}

};

int main(void)
{
	//Base base(1);//不能直接创建Base的对象, 
	Child child(1);
	child.display();

	return 0;
}
