 ///
 /// @file    consumer.cc
 /// @author  Icot(jobyang@163.com)
 /// @date    2017-03-14 16:24:55
 ///
#include "consumer.h"
#include "buffer.h"

#include <unistd.h>

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

void Consumer::consume(wd::Buffer &buf)
{
	while(1){
		int number = buf.pop();
		//MUTEX.lock();
		cout << ">>>>>consume pop():" << number << endl;
		//MUTEX.unlock();
		sleep(2);
	}
}

}
