 ///
 /// @file    mutexlockguard.h
 /// @author  Icot(jobyang@163.com)
 /// @date    2017-03-14 17:05:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class MutexLockGuard{
public:
	MutexLockGuard();
	~MutexLockGuard();
private:
	Mutex &mutex;
};
