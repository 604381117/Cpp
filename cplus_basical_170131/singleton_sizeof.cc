#include<stdio.h> 
#include <iostream>
using std::cout;
using std::endl;

struct A{
	int a;	//int型，在一般系统上占据4个内存字节	4
	char b;	//char型，占1个内存字节					1 + 3 (3浪费)
	float c;	//单精度浮点型，占4个内存字节	4 + 4 (4浪费)
	double d;	//double型，占8个内存字节		8
	short e[5]; //short型数组，每个元素占2个内存字节	8 + 2
	char & f;	//引用，当成指针维护	2 + 4 (2浪费)				
	double & g; //引用，当成指针维护	4 + 4 (后4浪费)
	static int h;	//static成员，公共内存，不影响单个对象的大小 0
};

//内存中通过该类只能创建一个对象
//1.该对象只能是一个堆对象
class Singleton{
public:
	static Singleton *getInstance()
	{
		if(NULL==_pInstance)
		_pInstance = new Singleton;
		return _pInstance;
	}
	
	void Display()
	{
		cout << "Singleton::Display()" << endl;
	}
private:
	Singleton()
	{}	
private:
	static Singleton *_pInstance;
};

Singleton *Singleton::_pInstance = NULL;

int main(void)
{
	Singleton *s1 = Singleton::getInstance();
	Singleton *s2 = Singleton::getInstance();
	Singleton *s3 = Singleton::getInstance();
	s1->Display();
	s2->Display();
	s3->Display();
	printf("s1=%p\n",s1);
	printf("s2=%p\n",s2);
	printf("s3=%p\n",s3);
	int b,*p;
	int &a=b;
	printf("sizeof(&)=%d\n",sizeof(a));
	printf("sizeof(*)=%d\n",sizeof(p));
	printf("sizeof(char)=%d\n",sizeof(char));
	printf("sizeof(short)=%d\n",sizeof(short));
	printf("sizeof(int)=%d\n",sizeof(int));
	printf("sizeof(float)=%d\n",sizeof(float));
	printf("sizeof(double)=%d\n",sizeof(double));
	printf("sizeof(long)=%d\n",sizeof(long));
	printf("sizeof(A)=%d\n",sizeof(A));
	return 0;
}

