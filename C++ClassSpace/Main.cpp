// TestSpece.cpp : 此文件用于测试C++


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
//	// 构造函数有参
//	Adder(int i = 0) { total = i; }
//
//	// 对外的接口 
//	void addNum(int number) { total += number; }
//	// 对外的接口
//	int getTotal() { return total; };
//
//	int getNum() { return num; };
//
//private:
//	// 对外隐藏的数据 
//	int total;
//
//	int num;
//};
//
//Adder g_adder; //全局实例对象 在全局的数据区占用存储空间，在全局数据区的变量的初始值为0
//
//int main()
//{
//	std::cout << "Hello World!\n";
//
//	Adder adder;	//局部实例对象占用的存储空间在栈上 ,变量初始值为随机值
//
//	Adder *pAdder = new Adder(); //类实例对象的指针 在全局数据区、堆、栈空间都能生成对象,变量初始值为0，但结果只是巧合
//	delete pAdder;
//
//	printf("%d\n",adder.getNum());
//}

#pragma endregion





