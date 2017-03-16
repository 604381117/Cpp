 /// @file    pthread.h
 /// @author  Icot(jobyang@163.com)
 /// @date    2017-03-14 11:05:44
#include "Noncopyable.h"

#include <pthread.h>
#include <functional>
using std::function;

namespace wd
{
//private Noncopyable 实现继承
//public Noncopyable 接口继承
class Thread:private Noncopyable{
	typedef function<void()> ThreadCallback;
public:
	Thread(ThreadCallback cb);
	~Thread();
	void start();
	void join();
	static void *threadFunc(void *arg);
	
private:
	ThreadCallback _cb;
	pthread_t _pthId; //oo_thread
	bool _isRunning;
};

}
