#include"Stopwatch.h"

Stopwatch::Stopwatch()
{
}

Stopwatch::~Stopwatch()
{
}

void Stopwatch::StartTime(char tag)
{
	timeStart = clock();
	//cout << "片段计时开始" << timeStart <<"ms"<< endl;

}

void Stopwatch::EndTime()
{
	//string *pstr[10000];
	//for (size_t i = 0; i < 10000; i++)
	//{
	//	pstr[i] = new string("Life is short, you need python.");
	//}
	timeEnd = clock();
}

int Stopwatch::GetCountData()
{
	
	timeTotal = (int)(timeEnd - timeStart);  ///析构函数和构造函数的时间差即为所用时间
	//cout << "此运行所用时间:" << timeTotal << "ms" << endl;
	return timeTotal;
}
