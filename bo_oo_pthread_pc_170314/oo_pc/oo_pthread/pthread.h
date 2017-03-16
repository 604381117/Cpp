 /// @file    pthread.h
 /// @author  Icot(jobyang@163.com)
 /// @date    2017-03-14 11:05:44
#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{
//private Noncopyable 实现继承
//public Noncopyable 接口继承
class Thread:private Noncopyable{
public:
	Thread();
	virtual ~Thread();
	void start();
	void join();
	static void *threadFunc(void *arg);//固定this指针，只传一个参数arg过去
	virtual void run()=0;//接口
private:
	pthread_t _pthId;
	bool _isRunning;
};

}
