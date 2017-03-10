#include <iostream>
#include <pthread.h>
using std::cout;
using std::endl;

class MutexLock{
public:
	MutexLock()
	:_islocking(false)
	{
		pthread_mutex_init(&_mutex,NULL);
	}

	~MutexLock(){
		pthread_mutex_destroy(&_mutex);
	}

	void lock(){
		pthread_mutex_lock(&_mutex);
		_islocking=true;
	}

	void unlock()
	{
		pthread_mutex_unlock(&_mutex);
		_islocking=false;
	}
	
	bool status()const{
		return _islocking;
	}
	
	pthread_mutex_t * getMutexLockPtr(){
		return &_mutex;
	}

private:
	MutexLock(const MutexLock&)//对象语义，系统资源具有唯一性不可复制
	{}

	MutexLock& operator=(const MutexLock&)
	{}
private:
	bool _islocking;
	pthread_mutex_t _mutex;
};

class Condition{
public:
	Condition(MutexLock &mutex)
	:_mutex(mutex)
	{
		pthread_cond_init(&_cond,NULL);
	}
	
	~Condition(){
		pthread_cond_destroy(&_cond);
	}

	void wait(){
		pthread_cond_wait(&_cond,_mutex.getMutexLockPtr());	
	}

	void notify(){
		pthread_cond_signal(&_cond);
	}

	void notifyall(){
		pthread_cond_broadcast(&_cond);
	}

private:
	MutexLock & _mutex;//互斥锁不能成为条件变量的对象成员,生命周期不相干
	pthread_cond_t _cond;
};

int main(void)
{
	MutexLock mutex;
	Condition cond(mutex);
	mutex.lock();
	cond.wait();
	cond.notify();
	mutex.unlock();
	return 0;
}

