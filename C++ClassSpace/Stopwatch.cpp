#include"Stopwatch.h"

//Stopwatch::Stopwatch()
//{
//	
//}

Stopwatch::~Stopwatch()
{
	timeEnd = clock();
	timeTotal = timeEnd - timeStart;  ///���������͹��캯����ʱ��Ϊ����ʱ��
	cout << "�˲�������ʱ��:" << timeTotal << "ms" << endl;
}

void Stopwatch::coutSpendTime()
{
	string *pstr[10000];
	for (size_t i = 0; i < 10000; i++)
	{
		pstr[i] = new string("Life is short, you need python.");
	}

}
