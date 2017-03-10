//using std::cout;    //using声明机制离它最近的大括号有效
//using std::endl;   
//using namespace std;//using编译指令，它会把std空间中所有实体全部引进来
#include<iostream>    //它是由模板编写而成，与c的头文件有差异

namespace A
{
	void display()
	{
		std::cout << "A::display()" << std::endl;//作用域限定符
	}

	void display1()
	{
		display();
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
	return 0;
}
