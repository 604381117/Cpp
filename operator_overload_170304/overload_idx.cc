#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class CharArr{
public:
	CharArr(int size)
	:_len(size)
	,_pstr(new char[_len])
	{}
	
	~CharArr(){
		delete []_pstr;
	}

	char &operator[](int idx){
		cout<<"operator [](int)"<<endl;
		static char cha='\0';
		if(idx>=0&&idx<_len)
		{
			return _pstr[idx];
		}else{
			cout <<"idx 越界" <<endl;
			return cha;
		}
	}
public:
	int _len;
	char * _pstr;
};

int main(void)
{
	const char * pstr="wangdao belief";
	CharArr ca(strlen(pstr));
	for(int idx=0;idx<strlen(pstr);++idx)
		ca[idx]=pstr[idx];
	cout << endl;
	for(int idx=0;idx<strlen(pstr);++idx)
		cout <<ca[idx]<<" ";
	return 0;
}
