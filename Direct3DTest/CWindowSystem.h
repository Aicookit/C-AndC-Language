#pragma once
#include <Windows.h>
///����windows���ڵĴ�����ʹ��directx9����ͼ������
class CWindowSystem
{
public:
	CWindowSystem();
	~CWindowSystem();

	bool Init();
	bool Run();
	void Close();

private:

	bool InitWindow(int screenWith ,int screenHeigh );
	HWND m_hWnd;
	static LRESULT CALLBACK WindowProc(HWND hWnd,UINT uMessage, WPARAM wParam, LPARAM lParam);
};

