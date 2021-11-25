// TestSpece.cpp : 此文件用于测试C++
//

#include"CPerson.h"


int main()
{
	//std::cout << "Hello World!\n";
	CPerson person;
	person.setSpeakWords("hh");
	string a = person.getWords();
	cout << a;
}

