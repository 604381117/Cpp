 ///
 /// @file    main.cc
 /// @author  Icot(jobyang@163.com)
 /// @date    2017-03-14 16:27:02
 ///
#include "threadpool.h"
#include "mytask.h"

#include <unistd.h>
#include <memory>
#include <iostream>
using std::shared_ptr;

int main(void)
{
	shared_ptr<wd::Task> sp(new wd::MyTask);
	wd::Threadpool threadpool(4,10);//4个线程，任务队列大小10
	threadpool.start();
	int cnt=20;
	while(cnt--)
	{
		threadpool.addTask(sp.get());
		sleep(1);
	}
	threadpool.stop();
	return 0;
}
