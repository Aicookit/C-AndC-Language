// TestSpece.cpp : ���ļ����ڲ���C++
#pragma region Exp
///
class Adder
{
public:
	// ���캯���в�
	Adder(int i = 0) { total = i; }

	// ����Ľӿ� 
	void addNum(int number) { total += number; }
	// ����Ľӿ�
	int getTotal() { return total; };

	int getNum() { return num; };

private:
	// �������ص����� 
	int total;

	int num;
};
//
//Adder g_adder; //ȫ��ʵ������ ��ȫ�ֵ�������ռ�ô洢�ռ䣬��ȫ���������ı����ĳ�ʼֵΪ0
//
//int main()
//{
//	std::cout << "Hello World!\n";
//
//	Adder adder;	//�ֲ�ʵ������ռ�õĴ洢�ռ���ջ�� ,������ʼֵΪ���ֵ
//
//	Adder *pAdder = new Adder(); //��ʵ�������ָ�� ��ȫ�����������ѡ�ջ�ռ䶼�����ɶ���,������ʼֵΪ0�������ֻ���ɺ�
//	delete pAdder;
//
//	printf("%d\n",adder.getNum());
//}
#pragma endregion


#include<iostream>

#include"Classes.h"
#include<vector>

#include<malloc.h>
using namespace std;

///Struct
struct StuInfo
{
	char name[20];
	char sex[10];
	int  score;
};
int getSize()
{
	int a = 6;
	return  a;
}
int main()
{

	StuInfo *stu1 = NULL;
	
	//cout << stu1.name << "..." << stu1.sex << "..." << stu1.score << endl;

	StuInfo infos[6];

	infos[0]=  { "Wang","��",99 };
	infos[1] = { "Li","��",93 };
	infos[2] = { "Zhao","��",19 };
	infos[3] = { "He","��",569 };
	infos[4] = { "Su","Ů",123 };
	infos[5] = { "Su","Ů",123333 };
	//memcpy(stu1, infos, sizeof(infos));
	stu1 = infos;
	//cout << infos[0].name<< endl;
	int b = getSize();
	//StuInfo c[b];
	cout << sizeof(stu1) << endl;

	//cout << &infos << endl;

	//StuInfo *infoList = stu1;
	//cout << infoList <<stu1<<"..."<< endl;  //ָ��infoList �� &infos]ӵ����ͬ�ĵ�ַ
	//cout <<  &infos << endl;
	//cout << (sizeof(infos))/sizeof(infos[0])*sizeof(*infoList) << endl; //ȡָ������ÿ��Ԫ�صĳ���*infoList
	//for (int i = 0; i < 6; i++)
	//{
	//	cout << (infoList+i)->score << endl;
	//	infoooo[i] = *(infoList + i);
	//}


	int a = 6;
	//int *b = new int[a]; //ʹ��ָ������
	//vector<int> b(a);     //ʹ��Vector����
	//for (size_t i = 0; i < a; i++)
	//{
	//	b[i] = i;
	//	cout << b[i] << endl;
	//}
	//extern int c[];  ///����һ�����飬�ⲿѰ��

	//delete b;
	b = 0;

	delete stu1;
	stu1 = 0;
	return 0;
}

///���ʵ������newָ��Ͳ�ʹ��newֱ�Ӵ���
// �� *p�ࣻ  //p�౻��������ڴ�
// delete p�ࣻ //�̶��ڴ�
// p�� = 0��//�̶��ڴ� ����0

// &���ã� �ܲ�����ͬ���ڴ�

//���󣺴洢��ĳ���������͵��ڴ�ռ䣬���ұ�����ĵ�ַ(������ֵ�͵�ַ&).��ͨ����ַ����ֵ
//ָ�� ������Ҳ��һ������,��ֵ(�洢��ĳ���ݵĵ�ַ*p���͵�ַ������ĵ�ַ(&p)
//ָ���Ϊ�գ�����һ����Ϊ��

//�������ݵ�3�ַ�ʽ��



