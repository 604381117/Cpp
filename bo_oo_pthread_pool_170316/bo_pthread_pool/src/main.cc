 ///
 /// @file    main.cc
 /// @author  Icot(jobyang@163.com)
 /// @date    2017-03-14 16:27:02
 ///
#include "threadpool.h"
#include "mytask.h"

#include <unistd.h>
#include <memory>

int main(void)
{
	wd::Threadpool threadpool(4,10);//4个线程，任务队列大小10
	threadpool.start();
	
	int cnt=20;
	while(cnt--)
	{
		threadpool.addTask(std::bind(&wd::MyTask::execute, wd::MyTask()));
		sleep(1);
	}
	threadpool.stop();
	return 0;
}
