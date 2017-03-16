 ///
 /// @file    threadpool.h
 /// @author  yangyu/icot(jobyang@163.com)
 /// @date    2017-03-16 11:05:10
 ///
#ifndef __WD_THREADPOOL_H__
#define __WD_THREADPOOL_H__

#include "buffer.h"
#include "pthread.h"

#include <vector>
#include <memory>
#include <functional>
using std::vector;
using std::shared_ptr;

namespace wd
{

class Thread;

typedef std::function<void()> Task;

class Threadpool{
public:
	Threadpool(size_t threadNum,size_t bufSize);
	~Threadpool();
	void start();
	void stop();
	void addTask(Task task);
private:
	Task getTask();
	void processTask();
private:
	bool _isExit;
	size_t  _threadNum;
	size_t _bufSize;
	Buffer _buff;
	vector<shared_ptr<Thread>> _threads;
};

}
#endif
