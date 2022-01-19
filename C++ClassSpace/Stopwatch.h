#pragma once

#include<time.h>
#include<iostream>
using namespace std;

///检查性能开销类
class Stopwatch
{
public:
	///Stopwatch() : timeStart(clock()) {};  构造函数，创建对象便开始计时
	Stopwatch();
	~Stopwatch();

	void StartTime(char tag);
	void EndTime();
	int GetCountData();

private:
	clock_t  timeStart;
	clock_t  timeEnd;
	int  timeTotal;
};

