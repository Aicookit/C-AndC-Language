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

	void coutSpent();
	void test2();

private:

	clock_t timeStart;
	clock_t timeEnd;
};

