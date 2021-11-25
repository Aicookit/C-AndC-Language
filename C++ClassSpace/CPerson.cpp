
#include "CPerson.h"

CPerson::CPerson()
{
	iAge = 3;
	iHeight = 60;
	fWeight = 30.0;

	isMale = true;

	strThink = "is this Moring?";
	strSpeak = "I'm a Robot";
}

CPerson::~CPerson()
{
}


void CPerson::setSpeakWords(string word)
{
	strSpeak = word;
}

string CPerson::getWords()
{
	return strSpeak;
}

//struct  LanguageType languageType;
//void CPerson::setLanguageType(LanguageType & language)
//{
//	languageType = language;
//}

//LanguageType CPerson::getLanguageType()
//{
//	return languageType;
//}

//void CPerson::setLanguageType(LanguageType languageType)
//{
//}







