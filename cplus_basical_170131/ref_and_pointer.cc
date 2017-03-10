#include<iostream>
using std::cout;
using std::endl;

//引用于指针的区别
//相同点：都有地址的概念;不同点：
//1.指针不需要初始化，引用必须进行初始化；
//2.指针可以改变指向，但引用一经绑定不能改变其指向；
//3.指针可以赋值为空，但引用不行。

//引用作函数参数，可减少空间开辟，加快函数执行效率，引用就是操作变量本身
void swap(int &x,int &y)
{
	x=x+y;
	y=x-y;
	x=x-y;
}

//返回一个引用
int array[5]={1,2,3,4,5};
int &func(int idx)
{
	return array[idx];//不能返回一个局部变量的引用
}

//不能返回一个指向堆空间变量的引用，防止内存泄露
int &func3()
{
	int *pa=new int(3);
	return *pa;
}

void swap(int *pa,int *pb)//地址传递，本质是把地址值得传递
{
	*pa=*pa+*pb;
	*pb=*pa-*pb;
	*pa=*pa-*pb;
}

#if 0
//无引用符号时，arr[idx]是需要开辟空间的，赋值给func
int func(int idx)
{
	return arr[idx];
}
void swap(inta,int b)  //值传递
{
	a=a+b;
	b=a-b;
	a=a-b;
}

//不能返回一个局部变量的指针
int *func1()
{
	int temp=3；
	return *temp；	
}

//不能返回一个局部变量的指针
int &func2()
{
	int temp=10;
	return temp;
}
#endif

int test(void)
{
	int x=3,y=4;
	cout<<"x="<<x<<endl;
	cout<<"y="<<y<<endl;
	swap(x,y);
	cout<<"x="<<x<<endl;
    cout<<"y="<<y<<endl;
	func(0)=10;
	cout<<"array[0]="<<array[0]<<endl;
	return 0;
}

int main(void)
{
	int &ref=func3();
	cout << "ref="<<ref<<endl;
	delete &ref;
	int a=3;
	int b=4;
	int c=a+b+func3();
	cout<<"c="<<c<<endl;
	test();
	return 0;
}
