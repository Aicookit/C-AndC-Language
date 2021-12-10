#pragma once

#include<time.h>
#include<iostream>
using namespace std;

///检查性能开销类
class Stopwatch
{
public:
	Stopwatch() : timeStart(clock()) {};  ///构造函数，创建对象便开始计时
	~Stopwatch();

	void coutSpendTime();

private:
	clock_t  timeStart;
	clock_t  timeEnd;
	clock_t  timeTotal;

};

