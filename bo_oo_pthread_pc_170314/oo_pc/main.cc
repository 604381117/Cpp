 ///
 /// @file    main.cc
 /// @author  Icot(jobyang@163.com)
 /// @date    2017-03-14 16:27:02
 ///
#include "buffer.h"
#include "producer.h"
#include "consumer.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <memory>
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	wd::Buffer buffer(10);
	wd::Producer producer(buffer);
	wd::Consumer consumer(buffer);
	producer.start();
	consumer.start();
	
	producer.join();
	consumer.join();
	return 0;
}
