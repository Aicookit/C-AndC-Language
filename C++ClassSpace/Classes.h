#pragma once

#include<iostream>

class Class01
{
public:
	Class01();
	~Class01();

	
	void Swap01 (int a,  int  b);  ///ֵ����
	void Test01(int a, int b);
	void Test02(int a);
	void Test03();

private:
	int a;

};




class Class02
{
public:
	Class02();
	~Class02();

	void Swap(int *a, int *b); ///ָ�봫��
private:

};



class  Class03
{
public:
	 Class03();
	~ Class03();

	void Swap(int &a, int &b); ///���ô���

private:

};

