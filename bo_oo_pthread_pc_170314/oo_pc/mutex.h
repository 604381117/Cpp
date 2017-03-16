 ///
 /// @file    mutex.h
 /// @author  Icot(jobyang@163.com)
 /// @date    2017-03-14 15:24:20
 ///
#ifndef __WD_MUTEX_H__
#define __WD_MUTEX_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{

class MutexLock{
public:
	MutexLock();
	~MutexLock();
	void lock();
	void unlock();
	bool status()const;
	pthread_mutex_t * getMutexLockPtr();
private:
	MutexLock(const MutexLock&);
	MutexLock& operator=(const MutexLock&);
private:
	bool _islocking;
	pthread_mutex_t _mutex;
};

}
#endif
