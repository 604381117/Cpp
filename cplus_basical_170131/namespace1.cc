//using std::cout;    //using声明机制离它最近的大括号有效
//using std::endl;   
//using namespace std;//using编译指令，它会把std空间中所有实体全部引进来
#include<iostream>    //它是由模板编写而成，与c的头文件有差

int num=10;
namespace A
{
	int num=5;    //匿名的名称空间，访问时只需要::num
	void display()
	{
		int num=1;
		std::cout << "A::display()" << std::endl;//作用域限定符
		std::cout << "display中的局部变量num=" << num << std::endl;
		std::cout << "命名空间A中的变量num=" << A::num << std::endl;
		std::cout << "匿名的名称空间变量num=" << ::num << std:: endl;
	}

	void display1()
	{
		display();
	}
	namespace AC
	{
		void print()
		{
			std::cout << "AC::display()" << std:: endl;
		}
	}
}

namespace B
{
	void display()
	{
		std::cout << "B::display()" << std::endl;//作用域限定符
	}
}

int main(void)
{
	A::display();
	B::display();
	A::display1();
	A::AC::print();
	return 0;
}
