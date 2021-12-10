
#include"CWindowSystem.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hpreInstance, LPTSTR lpCMDLine, int iCMDShow)
{
	//init windows
	CWindowSystem *windowSystem;
	bool result;
	windowSystem = new CWindowSystem;

	if (windowSystem)
	{
		result = windowSystem->Init();
	}

	if (result)
	{
		windowSystem->Run();
	}


	windowSystem->Close();

	delete windowSystem;

	windowSystem = 0;

	return 0;
}