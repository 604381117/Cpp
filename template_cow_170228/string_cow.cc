#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String{
private:
	class CharProxy{
	public:
		CharProxy(int idx,String &str)
		:_idx(idx)
		,_str(str)
		{}

		~CharProxy()
		{}

		CharProxy & operator=(char ch);
		friend std::ostream & operator<<(std::ostream &os,const CharProxy &rhs);
	private:
		int _idx;
		String & _str;
	};
public:
	friend std::ostream & operator<<(std::ostream &os,const CharProxy &rhs);
	friend std::ostream & operator <<(std::ostream &os,const String &rhs);
	String();
	~String();
	String(const char* pstr);
	String(const String &rhs);

	String& operator=(const String & rhs);

	int size()const
	{
		return strlen(_pstr);
	}

	const char* c_str()const
	{
		return _pstr;
	}
	
	void initRefCount()
	{
		_pstr[size()+1]=1;		
	}

	void increaseRefCount()
	{
		++_pstr[size()+1];
	}

	void decreaseRefCount()
	{
		--_pstr[size()+1];
	}

	int useCount()const
	{
		return _pstr[size()+1];
	}

	CharProxy operator[](int idx);
private:
	char *_pstr;
};

std::ostream & operator<<(std::ostream &os,const String::CharProxy &rhs)
{
	os<<rhs._str._pstr[rhs._idx];
	return os;
}

String::CharProxy String::operator[](int idx)
{
	return CharProxy(idx,*this);
}

String::CharProxy & String::CharProxy::operator=(char ch)
{
	if(_idx>=0 && _idx<_str.size())
	{
		if(_str.useCount() > 1)
		{
			_str.decreaseRefCount();
			char *temp=new char[_str.size()+2];
			strcpy(temp,_str._pstr);
			_str._pstr=temp;
			_str.initRefCount();
		}
		_str._pstr[_idx]=ch;
	}else
		cout<<"越界访问"<<endl;
	return *this;
}
#if 0
//无法区分读操作还是写操作
char & String::operator[](int idx)
{
	static char ch='\0';
	if(idx>=0&&idx<size())
	{
		if(_pstr[size()+1]>1)
		{
			decreaseRefCount();
			char *temp=new char[size()+1];
			strcpy(temp,_pstr);
			_pstr=temp;
			initRefCount();
		}
		return _pstr[idx];
	}
	else
		return ch;
}
#endif
std::ostream & operator <<(std::ostream &os,const String &rhs)
{
	os<<rhs._pstr;
	return os;
}

String& String::operator=(const String & rhs)
{
	if(this==&rhs)
		return *this;
	if(!--_pstr[size()+1])
		delete []_pstr;
	_pstr=rhs._pstr;
	increaseRefCount();
	return *this;
}

String::String(const String &rhs)
:_pstr(rhs._pstr)
{
	increaseRefCount();
}

String::String(const char* pstr)
:_pstr(new char(strlen(pstr)+2))
{
	strcpy(_pstr,pstr);
	initRefCount();
}

String::String()
:_pstr(new char[2])
{
	cout<<"String()"<<endl;
	initRefCount();
}

String::~String()
{
	if(!--_pstr[size()+1]){
		delete []_pstr;
		cout<<"String::~Strng()"<<endl;
	}
}

int main(void)
{
	String s1="wangdao";
	String s2=s1;
	String s3;
	s3=s2;
	s3[0]='W';
	cout<<"s3[0]写---s4[0]读"<<endl;
	String s4(s2);
	cout<<"s4[0]="<<s4[0]<<endl;
	cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;
	printf("s1=%p s2=%p s3=%p s4=%p\n",s1.c_str(),s2.c_str(),s3.c_str(),s4.c_str());
	cout<<"s1's use count="<<s1.useCount() << endl;
	cout << "s2's use count = " << s2.useCount() << endl;
	cout << "s3's use count = " << s3.useCount() << endl;
	cout << "s4's use count = " << s4.useCount() << endl;
	return 0;
}
