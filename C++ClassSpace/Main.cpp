// TestSpece.cpp : ���ļ����ڲ���C++
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

