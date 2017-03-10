#include <stdio.h>

//C++支持函数重载的实现原理:名字改编(name mangling)
//当函数名称相同时,根据函数参数的类型,个数,顺序来
//进行名字改编


//希望该函数以C的方式进行调用
//
//C与C++进行混合编程 
//将C的代码移植到C++里面

#ifdef __cplusplus
extern "C"
{
#endif
int add(int x, int y)
{
	return x + y;
}

#ifdef __cplusplus
}//end of extern "C"
#endif

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

