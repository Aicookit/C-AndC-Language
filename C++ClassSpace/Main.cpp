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
StuInfo *stuInfo1;
int main()
{
	StuInfo *stu1 = NULL;
	
	StuInfo infos[6];

	infos[0]=  { "Wang","��",99 };
	infos[1] = { "Li","��",93 };
	infos[2] = { "Zhao","��",19 };
	infos[3] = { "He","��",569 };
	infos[4] = { "Su","Ů",123 };
	infos[5] = { "Su","Ů",123333 };

	int a = 6;

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





