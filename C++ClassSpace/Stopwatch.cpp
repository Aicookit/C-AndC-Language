#include"Stopwatch.h"

//Stopwatch::Stopwatch()
//{
//	
//}

Stopwatch::~Stopwatch()
{
	timeEnd = clock();
	timeTotal = timeEnd - timeStart;  ///析构函数和构造函数的时间差即为所用时间
	cout << "此操作所用时间:" << timeTotal << "ms" << endl;
}

void Stopwatch::coutSpendTime()
{
	string *pstr[10000];
	for (size_t i = 0; i < 10000; i++)
	{
		pstr[i] = new string("Life is short, you need python.");
	}

}
