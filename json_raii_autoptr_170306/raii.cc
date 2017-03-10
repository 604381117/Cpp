#include <memory>
#include <string>
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::auto_ptr;

#if 0
class SafeFile{
public:
	SafeFile(FILE *fp)
	:_fp(fp)
	{}

	~SafeFile(){
		if(_fp){
			fclose(_fp);
			cout<<"~SafeFill()"<<endl;
		}
	}
	
	void write(const string &msg)
	{
		fwrite(msg.c_str(),1,msg.size(),_fp);
	}

private:
	FILE *_fp;
};
#endif

template <typename T>
class RAII{
public:
	RAII(T *p)
	:_p(p)
	{
		cout<<"RAII(T *p)"<<endl;
	}

	T *operator->()
	{
		return _p;
	}

	T& operator*()
	{
		return *_p;
	}

	T* get()const
	{
		return _p;
	}

	~RAII()
	{
		if(_p)
			delete _p;
	}
private:
	T* _p;
};



int main(void)
{
#if 0
	FILE *fp=fopen("raiifile",w+);
	SafeFile sf(fp);
	SafeFile sf(fopen("raiifile.txt","rw+"));
	string msg("aaaaaaaaaaa");
	sf.write(msg);
#endif
	
	RAII<int> pint(new int(3));
	auto_ptr<double> apd(new double(345.345));
	cout<<*apd<<endl;

	return 0;
}
