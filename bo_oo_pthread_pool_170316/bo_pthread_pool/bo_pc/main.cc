 ///
 /// @file    main.cc
 /// @author  Icot(jobyang@163.com)
 /// @date    2017-03-14 16:27:02
 ///
#include "buffer.h"
#include "consumer.h"
#include "producer.h"
#include "pthread.h"

#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::bind;

int main(void)
{
	wd::Buffer buffer(10);
	wd::Thread producer(bind(&wd::Producer::make,wd::Producer(),std::ref(buffer)));
	wd::Thread consumer(bind(&wd::Consumer::consume,wd::Consumer(),std::ref(buffer)));
	producer.start();
	consumer.start();
	producer.join();
	consumer.join();
	return 0;
}
