#include "log4func.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;
int main(void)
{
	LogWarn("warn msg");
	LogError("error msg");
	LogInfo("info msg");
	LogDebug("debug msg");
	return 0;
}


