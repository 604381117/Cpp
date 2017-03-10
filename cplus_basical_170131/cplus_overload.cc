#include <stdio.h>

//C++支持函数重载的实现原理:名字改编(name mangling)
//当函数名称相同时,根据函数参数的类型,个数,顺序来
//进行名字改编

int add(int x, double y)
{
	return x + y;
}

int add(int x, int y, int z)
{
	return x + y + z;
}


int main(void)
{
	int a = 3, b = 4;
	printf("a + b = %d\n", add(a, b));
	return 0;
}

