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

Producer::Producer(Buffer &buf)
:_buf(buf)
{ } 

void Producer::run()
{
	::srand(::time(NULL));
	while(1){
		int number = ::rand()%100;
		_buf.push(number);
		cout<<"producer push():"<<number<<endl;
		sleep(1);
	}
}

}
