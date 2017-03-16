 ///
 /// @file    workerthread.h
 /// @author  yangyu/icot(jobyang@163.com)
 /// @date    2017-03-16 11:15:41
 ///
#ifndef __WD_WORKERTHREAD_H__
#define __WD_WORKERTHREAD_H__

#include "pthread.h"

namespace wd
{

class Threadpool;

class WorkerThread:public Thread{
public:
	WorkerThread(Threadpool &threadpool);
	~WorkerThread();
	void run();
private:
	Threadpool& _threadpool;
};

}
#endif
