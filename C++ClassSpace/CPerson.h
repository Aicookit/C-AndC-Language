#pragma once
#include<chrono>      //此库包含时间，日期，时钟等功能
#include<iostream>
#include<string>
using namespace std;

///①Struct
struct  LanguageType
{
	string Chinese;
	string English;
	///can define diferent data types in struct
};

///②Class
class CPerson
{
public:
	CPerson();
	~CPerson();

private:
	int iAge;
	int iHeight;
	float fWeight;

	bool isMale;

	string strThink, strSpeak;




public:
	/*virtual void setLanguageType(LanguageType languageType); ///virtual

	void setLanguageType(LanguageType &languageType);*/
	//LanguageType getLanguageType();

	void setSpeakWords(string word);
	string getWords();
};



