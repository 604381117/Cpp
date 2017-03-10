#include<iostream>
using std::cout;
using std::endl;

int main(void)
{
	int a=10;
	int *pa=&a;//取地址运算符
	*pa=20;

	int &ref=a;//引用类型，ref为a的别名
	cout<<"a="<<a<<endl;
    cout<<"ref="<<ref<<endl;
	ref=30;
	cout<<"a="<<a<<endl;
	cout<<"ref="<<ref<<endl;
	cout<<endl;

	int b=40;
	ref=b;
	cout<<"a="<<a<<endl;
    cout<<"ref="<<ref<<endl;
    cout<<"b="<<b<<endl;
    cout<<endl;
	
//	int &ref2;   //error ,引用必须初始化
//	ref=1;

//	int &ref3=10  //10为一个字面值，也叫做右值，不能取地址。左边的ref可变，右边10是常量不可变，权限小的给权限大的不合法。
//  &10	

	const int &ref4=10;//常引用，能绑定到右值上，
	cout<<"ref4="<<ref4<<endl;

	return 0;
}
