#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		Base()
			: _pdata(new char[1])
		{
			cout << "Base()" << endl;
		}


		Base(const char * pdata)
			: _pdata(new char[strlen(pdata) + 1])
		{
			strcpy(_pdata, pdata);
		}

		Base(const Base & rhs)
			: _pdata(new char[strlen(rhs._pdata) + 1])
		{
			cout << "Base(const Base&)" << endl;
			strcpy(_pdata, rhs._pdata);
		}

		Base & operator=(const Base & rhs)
		{
			cout << "Base & operator=(const Base &)" << endl;
			if(this != &rhs)
			{
				delete [] _pdata;
				_pdata = new char[strlen(rhs._pdata) + 1];
				strcpy(_pdata, rhs._pdata);
			}
			return *this;
		}


		~Base()
		{
			delete [] _pdata;
		}

		friend std::ostream & operator<<(std::ostream &os, const Base& rhs);
	private:
		char * _pdata;
};

//当派生类有显式定义复制控制函数，而基类也有显式定义复制控制函数时,
//且进行派生类对象的复制操作时，派生类部分调用相应的复制控制函数，
////但此时并不会自动调用基类部分的复制控制函数；如果要复制基类部分，
////则必须在派生类的复制控制函数之中显式调用基类相应的复制控制函数

class Derived
: public Base
{
	public:
		Derived(const char * pdata, const char * pdata2)
			: Base(pdata)
			  , _pdata2(new char[strlen(pdata2) + 1])
	{
		cout << "Derived(const char *)" << endl;
		strcpy(_pdata2, pdata2);
	}

		Derived(const Derived & rhs)
			: Base(rhs) //显式调用基类的复制构造函数
			  , _pdata2(new char[strlen(rhs._pdata2) + 1])
	{
		cout << "Derived(const Derived&rhs)" << endl;
		strcpy(_pdata2, rhs._pdata2);
	}

		Derived & operator=(const Derived & rhs)
		{
			cout << "Derived & operator=(const Derived&rhs)" << endl;
			if(this != &rhs)
			{
				Base::operator=(rhs);//显式调用基类的赋值运算符函数

				delete [] _pdata2;
				_pdata2 = new char[strlen(rhs._pdata2) + 1];
				strcpy(_pdata2, rhs._pdata2);
			}
			return *this;
		}

		~Derived()
		{
			delete [] _pdata2;
		}


		friend std::ostream & operator<<(std::ostream &os, const Derived & rhs);
	private:
		char * _pdata2;
};

std::ostream & operator<<(std::ostream &os, const Base& rhs)
{
	os << rhs._pdata;
	return os;
}

std::ostream & operator<<(std::ostream &os, const Derived & rhs)
{
	os << (Base)rhs << " "
		<< rhs._pdata2;
	return os;
}

int main(void)
{
	Derived d1("hello", ",world");
	cout << "d1 = " << d1 << endl;

	Derived d2 = d1;
	cout << "d2 = " << d2 << endl;
	cout << endl;

#if 1
	Derived d3("shenzhen", "wangdao");
	cout << "d3 = " << d3 << endl;
	cout << endl;

	d3 = d1;
	cout << "d3 = " << d3 << endl;

#endif
	return 0;
}
