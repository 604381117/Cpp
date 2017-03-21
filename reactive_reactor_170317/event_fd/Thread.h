#include "Noncopyable.h"
#include <pthread.h>

#include <functional>
using std::function;

namespace wd
{

class Thread
: private Noncopyable// 实现继承
//: public Noncopyable//接口继承
{
	typedef function<void()> ThreadCallback;
public:
	Thread(ThreadCallback cb);
	~Thread();

	void start();
	void join();

	static void * threadFunc(void * arg);

private:
	bool 	       _isRunning;
	pthread_t      _pthId;
	ThreadCallback _cb;//回调函数
};

}//end of namespace wd

