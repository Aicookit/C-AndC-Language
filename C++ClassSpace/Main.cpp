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



#include"CPerson.h"
#include"TimeCout.h"

void test2()
{
	string *pstr[10000];
	for (size_t i = 0; i < 10000; i++)
	{
		pstr[i] = new string("Life is short, you need python.");
	}
}
int main()
{
	TimeCout tc;
	tc.coutSpent(test2);
	
	return 0;

}



// �� *p�ࣻ  //p�౻��������ڴ�
// delete p�ࣻ //�̶��ڴ�
// p�� = 0��//�̶��ڴ� ����0

// &���ã� �ܲ�����ͬ���ڴ�

//���󣺴洢��ĳ���������͵��ڴ�ռ䣬���ұ�����ĵ�ַ(������ֵ�͵�ַ&).��ͨ����ַ����ֵ
//ָ�� ������Ҳ��һ������,��ֵ(�洢��ĳ���ݵĵ�ַ*p���͵�ַ������ĵ�ַ(&p)
//ָ���Ϊ�գ�����һ����Ϊ��



