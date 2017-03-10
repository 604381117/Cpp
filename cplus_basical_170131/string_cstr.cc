#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


int test(void)
{  //C风格的字符串
	const char * pstr = "hello,world";
	cout << pstr << endl;
	int len1 = strlen(pstr);

	char * p1 = (char *) malloc(len1 + 1);
	memset(p1, 0, len1 + 1);
	strcpy(p1, pstr);
	cout << p1 << endl;
	free(p1);

	const char * pstr2 = "shenzhen";
	int len2 = strlen(pstr2);
	char * p2 = (char*) malloc(len1 + len2 + 1);
	memset(p2, 0, len1 + len2 + 1);
	strcpy(p2, pstr);
	strcat(p2, pstr2);
	cout << p2 << endl;

	free(p2);
	return 0;
}

int test1(void)
{
	string s1 = "hello,world";
	cout << "s1 = " << s1 << endl;
	string s2 = s1;//复制
	cout << "s2 = " << s2 << endl;

	string s3 = "shenzhen";
	string s4 = s1 + s3;//字符串的拼接
	cout << "s4 = " << s4 << endl;

	//将C++风格的字符串转换成C风格的字符串
	const char * pstr = s4.c_str();
	cout << pstr << endl;

	string s5 = s4 + ",wangdao";
	cout << "s5 = " << s5 << endl;

	string s6 = "1111" + s5;
	cout << "s6 = " << s6 << endl;

	//将string看成是一个数组
	cout << "s6[0] = " << s6[0] << endl;
	cout << "s6[4] = " << s6[4] << endl;

	//获取字符串的长度
	cout << "s1's size = " << s1.size() << endl;
	cout << "s1's size = " << s1.length() << endl;

	//对字符串进行遍历
	for(size_t idx = 0; idx != s1.size(); ++idx)
	{
		cout << s1[idx] << endl;
	}

	cout << "迭代器的用法" << endl;
	//用迭代器去访问(迭代器可以看成是指针)
	string::iterator it;
	for(it = s1.begin(); it != s1.end(); ++it)
	{
		cout << *it << endl;
	}

	//获取字符串的子串
	string s7 = s6.substr(4, 5);
	cout << "s7 = " << s7 << endl;

	return 0;
}

int main(void)
{
	//test();
	test1();
	return 0;
}
