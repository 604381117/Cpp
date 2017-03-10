#include <string.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class String{
	friend bool operator==(const String &, const String &);
	friend bool operator!=(const String &, const String &);
	friend bool operator<(const String &, const String &);
	friend bool operator>(const String &, const String &);
	friend bool operator<=(const String &, const String &);
	friend bool operator>=(const String &, const String &);
	friend std::ostream &operator<<(std::ostream &os, const String &);
	friend std::istream &operator>>(std::istream &is, String &);
public:
	String()
	:_pstr(new char('\0'))
	{
		cout<<"String()"<<endl;	
	}

	String(const char* pstr)
	:_pstr(new char[strlen(pstr)+1])
	{
		cout<<"String(const char pstr)"<<endl;
		strcpy(_pstr,pstr);
	}
	
	String(const String & rhs)
	:_pstr(new char[strlen(rhs._pstr)+1])
	{
		cout<<"String(const String & rhs)"<<endl;
		strcpy(_pstr,rhs._pstr);
	}
	
	String &operator=(const char * pstr)
	{
		cout<<"String &operator=(const char * pstr)"<<endl;
		if(!strcmp(_pstr,pstr)){
		}else{
			if(strlen(_pstr)-strlen(pstr) > 0){
				bzero(_pstr,sizeof(_pstr));
				strcpy(_pstr,pstr);
			}else{
				delete []_pstr;
				_pstr=new char[strlen(pstr)+1];
				strcpy(_pstr,pstr);
			}
		}
		return *this;
	}
	
	String &operator=(const String & rhs)
	{
		cout<<"String &operator=(const String & rhs)"<<endl;
		if(this != &rhs){
			delete []_pstr;
			_pstr=new char[strlen(rhs._pstr)+1];
			strcpy(this->_pstr,rhs._pstr);
		}
		return *this;
	}
	
	String &operator+=(const String & rhs)//rhs为NULL时？
	{
		cout<<"String &operator+=(const String & rhs)"<<endl;
		char temp[strlen(_pstr)+1];
		memcpy(temp,_pstr,strlen(_pstr)+1);
		delete []_pstr;
		_pstr=new char[strlen(temp)+strlen(rhs._pstr)+2];
		memcpy(_pstr,temp,strlen(temp)+1);
		strcat(_pstr,rhs._pstr);
		return *this;
	}

	String &operator+=(const char * pstr)
	{
		cout<<"String &operator+=(const char * pstr)"<<endl;
		char temp[strlen(_pstr)+1];
		memcpy(temp,_pstr,strlen(_pstr)+1);
		delete []_pstr;
		_pstr=new char[strlen(temp)+strlen(pstr)+2];
		memcpy(_pstr,temp,strlen(temp)+1);
		strcat(_pstr,pstr);
		return *this;
	}

	char &operator[](std::size_t index)
	{
		cout<<"char &operator[](std::size_t index)"<<endl;		
		static char ch='\0';
		if(index>=0 && index<strlen(_pstr)){
			return _pstr[index];
		}else{
			return ch;
		}
	}
	
	//const成员函数不带this指针，可供const和非const对象调用
	//返回一个字符类型的常引用  const char ch接返回值
	const char &operator[](std::size_t index) const
	{
		cout<<"const char &operator[](std::size_t index) const"<<endl;
		static char ch='\0';
		if(index>=0 && index<strlen(_pstr)){
			return _pstr[index];
		}else{
			return ch;
		}
	}
	
	std::size_t size() const{
		return strlen(_pstr);	
	}

	const char* c_str()const{
		char *temp=new char[strlen(_pstr)+1];//类外释放？？
		memcpy(temp,_pstr,strlen(_pstr)+1);
		return temp;
	}

	void Print(){
		cout<<"Print()"<<endl;
		if(_pstr==NULL)
			cout<<"NULL"<<endl;
		else
			cout<<_pstr<<endl;
	}

	~String(){
		delete []_pstr;
	}
private:
	char *_pstr;
};

bool operator==(const String &p1, const String &p2){
	//cout<<"bool operator==(const String & p1, const String & p2)"<<endl;
	return !strcmp(p1._pstr,p2._pstr);
}

bool operator!=(const String & p1, const String & p2){
	//cout<<"bool operator!=(const String & p1, const String & p2)"<<endl;
	return strcmp(p1._pstr,p2._pstr);
}

bool operator<(const String & p1, const String & p2){
	//cout<<"bool operator<(const String & p1, const String & p2)"<<endl;
	return (strcmp(p1._pstr,p2._pstr)<0);
}

bool operator>(const String & p1, const String & p2){
	//cout<<"bool operator>(const String & p1, const String & p2)"<<endl;
	return (strcmp(p1._pstr,p2._pstr)>0);
}

bool operator<=(const String & p1, const String & p2){
	//cout<<"bool operator<=(const String & p1, const String & p2)"<<endl;
	return (strcmp(p1._pstr,p2._pstr) <= 0);
}

bool operator>=(const String & p1, const String & p2){
	//cout<<"bool operator>=(const String & p1, const String & p2)"<<endl;
	return (strcmp(p1._pstr,p2._pstr) >= 0);
}

std::istream &operator>>(std::istream &is, String &s){
	//cout<<"std::istream &operator>>(std::istream &is, String &s)"<<endl;
	is>>s._pstr;
}

std::ostream &operator<<(std::ostream &os, const String &s){
	//cout<<"std::ostream &operator<<(std::ostream &os, const String &s)"<<endl;
	os << s._pstr<<"  ";
}


String operator+(const String & p1, const String & p2)
{
	String temp(p1);
	temp+=p2;
	return temp;
}

String operator+(const String &p1, const char *pstr)
{
	String temp(p1);
	temp+=pstr;
	return temp;
}

String operator+(const char *pstr, const String &p1)
{
	String temp(pstr);
	temp+=p1;
	return temp;
}

int main(void)
{
	const char *p="wangdao";
	String s1;
	String s2("17th");
	String s3(s2);
	String s4,s5,s6;
	s4=s3;
	s5="linux";
	s6=p;
	cout<<endl;
	cout<<"p s1(NULL) s2   s3    s4    s5    s6"<<endl;
	cout<<p<<s1<<s2<<s3<<s4<<s5<<s6<<endl;
	cout<<"s1==s2 s2==s3 s3==s4 s4==s5 s5==s6"<<endl;
	cout<<(s1==s2)<<" "<<(s2==s3)<<" "<<(s3==s4)<<" "<<(s4==s5)<<" "<<(s5==s6)<<endl;
	cout<<"s1!=s2 s2!=s3 s3!=s4 s4!=s5 s5!=s6"<<endl;
	cout<<(s1!=s2)<<" "<<(s2!=s3)<<" "<<(s3!=s4)<<" "<<(s4!=s5)<<" "<<(s5!=s6)<<endl;
	cout<<"s1>s2 s2>s3 s3>s4 s4>s5 s5>s6"<<endl;
	cout<<(s1>s2)<<" "<<(s2>s3)<<" "<<(s3>s4)<<" "<<(s4>s5)<<" "<<(s5>s6)<<endl;
	cout<<"s1>=s2 s2>=s3 s3>=s4 s4>=s5 s5>=s6"<<endl;
	cout<<(s1>=s2)<<" "<<(s2>=s3)<<" "<<(s3>=s4)<<" "<<(s4>=s5)<<" "<<(s5>=s6)<<endl;
	cout<<"s1<s2 s2<s3 s3<s4 s4<s5 s5<s6"<<endl;
	cout<<(s1<s2)<<" "<<(s2<s3)<<" "<<(s3<s4)<<" "<<(s4<s5)<<" "<<(s5<s6)<<endl;
	cout<<"s1<=s2 s2<=s3 s3<=s4 s4<=s5 s5<=s6"<<endl;
	cout<<(s1<=s2)<<" "<<(s2<=s3)<<" "<<(s3<=s4)<<" "<<(s4<=s5)<<" "<<(s5<=s6)<<endl;
	
	String s7,s8,s9("999"),s10("101010"),s11("111111"),s12("121212");
	cin>>s7;
	cin>>s8;
	cout<<"p      s7   s8   s9   s10   s11   s12"<<endl;
	cout<<p<<"  "<<s7<<s8<<s9<<s10<<s11<<s12<<endl;
	s8+=s7;
	s9+=p;
	s10=s7+s8;
	s11=p+s9;
	s12=s9+p;
	cout<<endl;
	
	cout<<"p      s7      s8+=s7        s9+=p  s10= s7+s8  s11=p+s9    s12=s9+p"<<endl;
	cout<<p<<"  "<<s7<<s8<<s9<<s10<<s11<<s12<<endl<<endl;
	
	const char * pstr="wangdao belief";
	String s13=pstr;
	for(int i=0;i<strlen(pstr);++i)
		cout<<s13[i]<<" ";
	cout<<endl;
	cout<<"size: s7  s8  s9  s10  s11  s12"<<endl;
	cout<<"    "<<s7.size()<<" "<<s8.size()<<" "<<s9.size()<<" "<<s10.size()<<" "<<s11.size()<<" "<<s12.size()<<endl;
	const char *temp;
	temp=s12.c_str();
	cout<<"s12.c_str()="<<temp<<endl;
	cout<<endl;
	delete temp;//??
	return 0;
}
