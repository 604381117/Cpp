 ///
 /// @file    producer.cc
 /// @author  Icot(jobyang@163.com)
 /// @date    2017-03-14 16:18:51
 ///
#include "pthread.h" 
#include "producer.h"
#include "buffer.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

void Producer::make(wd::Buffer &buf)
{
	::srand(::time(NULL));
	while(1){
		int number = ::rand()%100;
		buf.push(number);
		//MUTEX.lock();
		cout<<"producer push():"<<number<<endl;
		//MUTEX.unlock();
		sleep(1);
	}
}

}
