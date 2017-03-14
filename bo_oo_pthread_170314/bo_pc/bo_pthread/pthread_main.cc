///
/// @file    test.cc
/// @author  Icot(jobyang@163.com)
/// @date    2017-03-14 11:25:34
///
#include "pthread.h"
#include "producer.h"

int main(void)
{
	wd::Thread thread(std::bind(&Producer::func,Producer()));
	thread.start();
	//thread.func();
	thread.join();
	
	return 0;
}

