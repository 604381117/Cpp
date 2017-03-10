//c与c++混合编译时，c的头文件置于c++之前
//c++是c的超集
#include<iostream>    //它是由模板编写而成，与c的头文件有差异
using namespace std;  //命名空间

int main(int argc,char **argv)
{
	int a;
	cout << "hello world!\n" << endl;//endl为换行
	cin >> a;
	cout << a << "\n";
	return 0;
}
