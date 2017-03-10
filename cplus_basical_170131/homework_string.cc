#include<string.h>
#include <iostream>
#include<string>
using std::cout;
using std::endl;

class String{
public:
	String()
	:_pstr(new char('n'))
	{
		cout << "默认构造函数String()" << endl;
	}

	String(const char * pstr)
	:_pstr(new char[strlen(pstr)+1])
	{
		strcpy(_pstr,pstr);
		cout << "显式构造函数String(const char * pstr)" << endl;
	}

	String(const String & rhs)
	:_pstr(new char[strlen(rhs._pstr)+1])
	{
		strcpy(_pstr,rhs._pstr);
		cout << "深拷贝构造函数String(const String &rhs)" << endl;
	}

	String & operator=(const String & rhs)
	{
		cout << "=符号重载String & operatot=(const String & rhs)" << endl;
		if(this != &rhs)
		{
			delete []_pstr;
			_pstr = new char[strlen(rhs._pstr)+1];
			strcpy(this->_pstr,rhs._pstr);
		}
		return *this;
	}

	~String()
	{
		cout << "析构函数~String()"	<< endl;
		delete []_pstr;
	}

	void print()
	{
		cout << _pstr << endl;
	}
private:
	char *_pstr;
};

int main(void)
{
	String str1;
	str1.print();
	cout << endl;
	String str2 = "Hello,world";
	String str3 = "wangdao";					
	str2.print();		
	str3.print();
	cout << endl;
	str2 = str3;
	str2.print();
	cout << endl;
	String str4 = str3;
	str4.print();
	cout << endl;
	return 0;
}
