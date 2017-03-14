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

Consumer::Consumer(Buffer &buf)
:_buf(buf)
{	}

void Consumer::run()
{
	while(1){
		int number = _buf.pop();
		cout << ">>>>>consume pop():" << number << endl;
		sleep(2);
	}
}

}
