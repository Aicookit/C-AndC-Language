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
	//cout << "Ƭ�μ�ʱ��ʼ" << timeStart <<"ms"<< endl;

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
	
	timeTotal = (int)(timeEnd - timeStart);  ///���������͹��캯����ʱ��Ϊ����ʱ��
	//cout << "����������ʱ��:" << timeTotal << "ms" << endl;
	return timeTotal;
}
