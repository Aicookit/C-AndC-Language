#include"TimeCout.h"

TimeCout::TimeCout()
{
}

TimeCout::~TimeCout()
{
}

void(*pTest)();


//FunctionT TimeCout::coutSpent(FunctionT fun)
//{
//	
//	timeStart= clock();
//
//	//放入要计算运行的code
//	
//	pTest = fun;
//	timeEnd = clock();
//
//	double total = (double)(1.0*(timeEnd - timeStart) / CLOCKS_PER_SEC);
//	//double total = (timeEnd - timeStart);
//	printf("本次运行共花销 %f 秒\n", total);
//}
void TimeCout::coutSpent()
{

	timeStart = clock();

	//放入要计算运行的code

	timeEnd = clock();

	double total = (double)(1.0*(timeEnd - timeStart) / CLOCKS_PER_SEC);
	//double total = (timeEnd - timeStart);
	printf("本次运行共花销 %f 秒\n", total);
}
void TimeCout::test2()
{
	string *pstr[10000];
	for (size_t i = 0; i < 10000; i++)
	{
		pstr[i] = new string("Life is short, you need python.");
	}
}

