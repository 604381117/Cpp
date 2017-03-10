#include<stdlib.h>
#include<iostream>
using std::cout;
using std::endl;

//malloc/free     //1.c标准库函数；2.只负责开辟空间，不负责初始化；
//new/delete      //1.开辟空间同时进行初始化为0；

int main(void)
{
	int *pa=(int*)malloc(sizeof(int)*10);//申请数组空间时乘以个数
	*pa=100;
	cout << "*pa=" << *pa << endl;
	free(pa);

	int *pb=new int(3);
	*pb=200;
    cout << "*pb=" << *pb << endl;
    delete pb;

	int a=100;
	cout << "a=" << a << endl;
	int b(10);
	int c(a);
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	int *pc=new int[3];
	for(int idx=0;idx<3;idx++)
	{
		cout << "pc[idx]=" << pc[idx] <<endl;
	}
	delete []pc;
}


