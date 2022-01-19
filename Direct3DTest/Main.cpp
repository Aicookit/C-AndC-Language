
#include<afx.h>
#include"CWindowSystem.h"
#include"Stopwatch.h"
#include<stdlib.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hpreInstance, LPTSTR lpCMDLine, int iCMDShow)
{
	//init windows
	CWindowSystem *windowSystem = NULL;
	bool result;
	windowSystem = new CWindowSystem;
	//Stopwatch *startcount = NULL;
	if (windowSystem)
	{
		result = windowSystem->Init();
	}

	if (result)
	{
		//startcount = new Stopwatch();
		//startcount->StartTime('1');

		windowSystem->Run();
		
		//startcount->EndTime();
		//int count = startcount->GetCountData();
		//CString cStr;
		//cStr.Format("%d", count);
		//MessageBox(NULL, cStr,"ºÄÊ±", MB_OK);
	}


	windowSystem->Close();

	delete windowSystem;
	windowSystem = 0;
	//delete startcount;
	//startcount = 0;
	return 0;
}