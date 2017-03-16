///
/// @file    producer.cc
/// @author  Icot(jobyang@163.com)
/// @date    2017-03-14 20:40:20
///
#include "producer.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
using std::cout;
using std::endl;

void Producer::func()
{
	int cnt = 20;
	::srand(::time(NULL));
	while(cnt--)
	{
		int number = ::rand() % 100;
		cout << "producer number: " << number << endl;
		::sleep(1);
	}
}
