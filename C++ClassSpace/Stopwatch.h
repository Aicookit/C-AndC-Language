#pragma once

#include<time.h>
#include<iostream>
using namespace std;

///������ܿ�����
class Stopwatch
{
public:
	///Stopwatch() : timeStart(clock()) {};  ���캯������������㿪ʼ��ʱ
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

