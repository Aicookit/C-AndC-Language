#pragma once
#include<time.h>
#include<iostream>
#include<string>

using namespace std;

class TimeCout
{

public:
	TimeCout();
	~TimeCout();
	template<typename FunctionT>
	void coutSpent(FunctionT T);
	void test2();
	void test();

private:

	clock_t timeStart;
	clock_t timeEnd;
};

