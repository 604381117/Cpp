#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;

class Test{
private:
	int a;
};

class Computer{
public:
	explicit//禁止隐式转换
	Computer(const char * brand, float price)
	:_brand(new char[strlen(brand)+1])
	,_price(price)
	{
		strcpy(_brand,brand);
		cout << "构造函数Computer(char*,float)" << endl;
	}

	//加const可以接右值和匿名对象
	//拷贝构造函数的形参不能不是对象，否则会导致拷贝构造函数的无穷递归,故为引用
	Computer(const Computer & rhs)
	:_brand(new char[strlen(rhs._brand)+1])//rhs._brand为Computer内部访问private
	,_price(rhs._price)
	{
		strcpy(_brand,rhs._brand);
		cout << "深拷贝Computer(const Computer rhs)" << endl;
	}

	~Computer()
	{
		delete [] _brand;
		cout << "析构函数~Computer()" << endl;
	}

#if 0
	//默认拷贝构造函数，数据成员为指针类型时已不能满足我们需求，需要显式定义
	Computer(const Computer &rhs)
	:_brand(rhs._brand) //两个对象的brand成员指向同一块堆空间，有double free错误
	,_price(rhs._price) //直接复制地址称为浅拷贝
	{
	cout << "浅拷贝Computer(const Computer rhs)" << endl;
	}
#endif
	
	Computer & operator = (const Computer &rhs)
	{	
		cout << "运算符重载Computer operator =(const Computer &rhs)" << endl;
		if(this != &rhs)
		{
			delete []_brand;
			_brand=new char[strlen(rhs._brand)+1];
			strcpy(this->_brand,rhs._brand);
			this->_price = rhs._price;
		}
		return *this;
	}

	//隐含的this指针形式，代表当前对象本身，将当前对象的地址赋给this
	void Print(/*Point *const this*/)
	{
		cout << "Brand:" << this->_brand << endl;
		cout << "Price $:" << this->_price << endl;
	}
private:
	char * _brand;
	float _price;
};

int main(void)
{
	//调用拷贝构造函数时实参与形参为地址复制，右值无法取地址，故形参加上const
	Computer pc=Computer("Mac",5000);//匿名对象，为右值，无法直接取地址
	pc.Print();
	cout << endl;
	Computer pc1("DELL",890);
	Computer pc12 = pc1;
	pc1.Print();
	pc12.Print();
	cout << endl;

	pc12 = pc1;
	pc1.Print();
	pc12.Print();
	cout << endl;

	Computer pc3("lenovo",6789);
	Computer pc4(pc3);
	pc3.Print();
	pc4.Print();
	cout << endl;

	pc4 = pc3;
	pc3.Print();
	pc4.Print();
	cout << endl;
	//Point pt4(); //返回值为Point对象的无参函数，并非对象的声明；
	//Point pt41;  //对象的声明，调用默认构造函数

	//Point pt42=1;//发生了隐式转换 --> 禁止隐式转发生关键字:explicit
	return 0;
}
