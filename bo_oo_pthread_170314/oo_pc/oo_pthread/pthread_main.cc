 ///
 /// @file    test.cc
 /// @author  Icot(jobyang@163.com)
 /// @date    2017-03-14 11:25:34
 ///
#include "pthread.h"
#include <unistd.h>
#include <time.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

class DerivedThread:public wd::Thread{
public:
	virtual void run()
	{
		int cnt=20;
		srand(time(NULL));
		while(cnt--){
			int number=rand()%100;
			cout<<"number= "<<number<<endl;
			sleep(1);			
		}
	}
};

int main(void)
{
	unique_ptr<wd::Thread> p(new DerivedThread);
	p->start();
	p->join();
	return 0;
}

