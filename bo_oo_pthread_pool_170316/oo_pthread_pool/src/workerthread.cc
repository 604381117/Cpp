 ///
 /// @file    workerthread.cc
 /// @author  yangyu/icot(jobyang@163.com)
 /// @date    2017-03-16 11:17:56
 ///
#include "workerthread.h"
#include "threadpool.h"
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

WorkerThread::WorkerThread(Threadpool &threadpool)
:_threadpool(threadpool)
{}

WorkerThread::~WorkerThread()
{
	cout<<"~WorkerThread()"<<endl;
}
void WorkerThread::run()
{
	_threadpool.processTask();
}

}
