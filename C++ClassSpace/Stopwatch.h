#pragma once

#include<time.h>
#include<iostream>
using namespace std;

///������ܿ�����
class Stopwatch
{
public:
	Stopwatch() : timeStart(clock()) {};  ///���캯������������㿪ʼ��ʱ
	~Stopwatch();

	void coutSpendTime();

private:
	clock_t  timeStart;
	clock_t  timeEnd;
	clock_t  timeTotal;

};

