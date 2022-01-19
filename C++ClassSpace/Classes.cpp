#include"Classes.h"

using namespace std;
///01
Class01::Class01()
{
	cout << "Class01" << endl;
}
Class01::~Class01()
{
	cout << "~~Class01" << endl;
}

void Class01::Swap01(int a, int b)
{
	int   temp;
	temp = a;
	a = b;
	b = temp;
}

void Class01::Test01(int a, int b)
{
	cout << "Test01" << endl;
}

void Class01::Test02(int a)
{
	cout << "Test02" << endl;
}

void Class01::Test03()
{
	cout << "Test03" << endl;
}


//02
Class02::Class02()
{
}

Class02::~Class02()
{
}
void Class02::Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


//03
Class03::Class03()
{
}

Class03::~Class03()
{
}

void Class03::Swap(int &a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}
