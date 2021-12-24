#pragma once
#include <Windows.h>
#include "CGraphicEngine.h"
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

	CGraphicEngine *graphicEngine;

	HWND m_hWnd;
	bool InitWindow(int screenWith ,int screenHeigh );
	static LRESULT CALLBACK WindowProc(HWND hWnd,UINT uMessage, WPARAM wParam, LPARAM lParam);
};

