// TestSpece.cpp : 此文件用于测试C++
#pragma region Exp
///
class Adder
{
public:
	// 构造函数有参
	Adder(int i = 0) { total = i; }

	// 对外的接口 
	void addNum(int number) { total += number; }
	// 对外的接口
	int getTotal() { return total; };

	int getNum() { return num; };

private:
	// 对外隐藏的数据 
	int total;

	int num;
};
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

	infos[0]=  { "Wang","男",99 };
	infos[1] = { "Li","男",93 };
	infos[2] = { "Zhao","男",19 };
	infos[3] = { "He","男",569 };
	infos[4] = { "Su","女",123 };
	infos[5] = { "Su","女",123333 };

	int a = 6;

	return 0;
}

///类的实例化：new指针和不使用new直接创建
// 类 *p类；  //p类被随机分配内存
// delete p类； //固定内存
// p类 = 0；//固定内存 但归0

// &引用： 能操作共同的内存

//对象：存储了某种数据类型的内存空间，并且被分配的地址(即：有值和地址&).能通过地址访问值
//指针 ：本身也是一个对象,有值(存储了某数据的地址*p）和地址：本身的地址(&p)
//指针可为空，引用一定不为空

//参数传递的3种方式：





