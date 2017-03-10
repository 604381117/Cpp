#include <iostream>
using std::cout;
using std::endl;

class Complex{
//friend Complex operator+(Complex &,Complex &);	
public:
	Complex(double real,double vir)
	:_real(real)
	,_vir(vir)
	{
		cout<<"Complex(double,double)"<<endl;
	}
	
	double getreal()const{
		return _real;
	}

	double getvir()const{
		return _vir;
	}
	//复合赋值运算符最好以成员函数的形式进行重载
	Complex & operator+=(const Complex &rhs)
	{
		this->_real+=rhs._real;
		this->_vir+=rhs._vir;
		return *this;
	}

	Complex & operator++()
	{
		++this->_real;
		++this->_vir;
		return *this;
	}

	Complex operator++(int)
	{
		Complex temp(*this);
		++this->_real;
		++this->_vir;
		return temp;
	}

	void display()
	{
		cout <<_real<<"+"<<"i*"<<_vir<<endl;
	}

	friend std::ostream &operator<<(std::ostream &os,const Complex &rhs);
	friend std::istream &operator<<(std::istream &is,Complex &rhs);
private:
	double _real,_vir;
};

std::ostream &operator<<(std::ostream &os,const Complex &rhs)
{
	os<<rhs._real<<"+"<<"i*"<<rhs._vir;
	return os;
}

std::istream &operator<<(std::istream &is,Complex &rhs)
{
	is>>rhs._real;
	while(is.get()!='*');
	is>>rhs._vir;
	return is;
}

#if 0   
1.普通函数重载需将数据成员放在public区
2.或者用友元函数
3.或者定义getreal()
#endif
Complex operator+(const Complex &c1,const Complex &c2)
{
	return Complex(c1.getreal()+c2.getreal(),c1.getvir()+c2.getvir());
}
int main(void)
{
	Complex com1(3,7);
	Complex com2(1,-9);
	com1.display();
	com2.display();
	(com1+com2).display();
	cout<<endl;
	cout<<com1<<"----"<<com2<<endl;

	return 0;
}
