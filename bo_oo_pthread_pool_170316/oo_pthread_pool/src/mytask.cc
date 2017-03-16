 ///
 /// @file    mytask.cc
 /// @author  yangyu/icot(jobyang@163.com)
 /// @date    2017-03-16 15:07:07
 ///
#include "mytask.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
	
void MyTask::execute()
{
	srand(time(NULL));
	cout<<"MyTask::execute number:" << rand()%100 << endl;
	sleep(1);
}

}

