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
//	//����Ҫ�������е�code
//	
//	pTest = fun;
//	timeEnd = clock();
//
//	double total = (double)(1.0*(timeEnd - timeStart) / CLOCKS_PER_SEC);
//	//double total = (timeEnd - timeStart);
//	printf("�������й����� %f ��\n", total);
//}
void TimeCout::coutSpent()
{

	timeStart = clock();

	//����Ҫ�������е�code

	timeEnd = clock();

	double total = (double)(1.0*(timeEnd - timeStart) / CLOCKS_PER_SEC);
	//double total = (timeEnd - timeStart);
	printf("�������й����� %f ��\n", total);
}
void TimeCout::test2()
{
	string *pstr[10000];
	for (size_t i = 0; i < 10000; i++)
	{
		pstr[i] = new string("Life is short, you need python.");
	}
}

