#pragma once

#include<iostream>
#include<string>
using namespace std;

///¢ÙStruct
struct  LanguageType
{
	string Chinese;
	string English;
	///can define diferent data types in struct
};

///¢ÚClass
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



