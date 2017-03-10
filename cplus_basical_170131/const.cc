#include<iostream>
using std::cout;
using std::endl;
#define K 100  //发生时机在预编译阶段，只是一个简单的替换,一旦发生错误都是在运行时，具有隐藏性

int main(void)
{
	const int a=10; //发生时机：编译，会进行语法检查
	//a=20;//error
	cout << K << endl;
	cout << "a=" << a << endl;
	//const int b;  //error,const常量必须进行初始化
	int b=100,c=1000;
	const int *p=&b;//*p固定，p的指向可改变，常量指针（const to pointer）
	//*p=110;//error
	b=101;
	cout << "*p=" << *p << endl;
	p=&c;//指针本身的指向可变
	cout << "*p=" << *p << endl;
	
	int * const pb=&b;//*pb可变，pb指向固定,指针常量（const pointer）
	*pb=110;
	cout << "*pb=" << *pb << endl;
	b=115;
	cout << "*pb=" << *pb << endl;
	//pb=&c;//error
}
