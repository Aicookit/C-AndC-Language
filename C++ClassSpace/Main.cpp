// TestSpece.cpp : ���ļ����ڲ���C++


#include"CPerson.h"
int main()
{
	int n;
	cout << "Please input the size of rhombus(the size should between 1 to 10):" << endl;
	cin >> n;

	if (n > 10) {
		return -1;
	}
	else if (n < 1)
	{
		return -1;
	}

	for (int i = 1; i < 2 * n; i++) {
		for (int j = 0; j < abs(n - i); j++) {
			cout << " ";
		}
		for (int j = 0; j < 2 * (n - abs(n - i)) - 1; j++) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}

#pragma region Exp
///
//class Adder
//{
//public:
//	// ���캯���в�
//	Adder(int i = 0) { total = i; }
//
//	// ����Ľӿ� 
//	void addNum(int number) { total += number; }
//	// ����Ľӿ�
//	int getTotal() { return total; };
//
//	int getNum() { return num; };
//
//private:
//	// �������ص����� 
//	int total;
//
//	int num;
//};
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





