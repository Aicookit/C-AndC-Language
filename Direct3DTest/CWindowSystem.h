#pragma once
#include <Windows.h>
#include "CGraphicEngine.h"
///负责windows窗口的创建和使用directx9创建图形引擎
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

