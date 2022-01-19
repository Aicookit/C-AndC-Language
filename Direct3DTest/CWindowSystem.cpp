
#include"CWindowSystem.h"

CWindowSystem::CWindowSystem()
{
}

CWindowSystem::~CWindowSystem()
{
}

bool CWindowSystem::Init()
{
	//初始化win窗口
	bool isInitWindows = InitWindow(600, 400);

	if (!isInitWindows)
	{
		MessageBox(m_hWnd, "初始化窗口失败", NULL, MB_OK);
	}
	
	//实例引擎
	graphicEngine = new CGraphicEngine;
	bool result = graphicEngine->InitAllComponets(m_hWnd);
	if (!result)
	{
		MessageBox(m_hWnd, "graphics initialize failed!", 0, MB_OK);
	}

	return true;
}

bool CWindowSystem::Run()
{
	MSG message;

	bool flag = true;
	while (flag)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_NOREMOVE))  //等待消息处理完后变false
		{
			if (GetMessage(&message,NULL,0,0))
			{
				TranslateMessage(&message);
				DispatchMessage(&message);
			}

			if (message.message == WM_QUIT)
			{
				flag = false;
				break;
			}
		}
		//Render...
		flag = graphicEngine->FrameUpdata();
	}

	return true;
}

void CWindowSystem::Close()
{
	if (graphicEngine)
	{
		graphicEngine->Close();
		delete graphicEngine;
		graphicEngine = 0;
	}

	if (m_hWnd)
	{
		m_hWnd = 0;
	}
}



bool CWindowSystem::InitWindow(int screenWith, int screenHeigh)
{
	WNDCLASSEX wc;

	int posX, posY;
	posX =100;
	posY = 100;

	HINSTANCE hinstance = GetModuleHandle(NULL);

	LPCSTR applicationName = "Engine";

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hinstance;
	wc.hIcon = LoadIcon(hinstance, "");
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(hinstance, "");
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = applicationName;

	RegisterClassEx(&wc);

	m_hWnd = CreateWindowEx(NULL, applicationName, "DirectX",WS_OVERLAPPEDWINDOW,
		posX, posY, screenWith, screenHeigh, NULL, NULL, hinstance, NULL);


	if (m_hWnd == NULL)
	{
		return false;
	}

	ShowWindow(m_hWnd, SW_SHOW);

	//UpdateWindow(m_hWnd);

	return true;
}


 LRESULT CALLBACK CWindowSystem::WindowProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
 {
     switch (umessage)
     {
		 case WM_CLOSE:
		 {
			 //所有以Window结尾的方法，都不会进入消息队列，而是直接直接执行
			 PostQuitMessage(0); //DestroyWindow发送另一个夏溪 WM__DESTROY
			 return 0;
		 }
		 case WM_DESTROY:
			 PostQuitMessage(0);
			 return 0;
		 //case WM_LBUTTONDOWN: //鼠标左键按下
		 //{
			// int xPos = LOWORD(lparam);//获取鼠标按下的坐标
			// int yPos = HIWORD(lparam);

			// TCHAR buf[1024];
		
			// wsprintf(buf, TEXT("x = %d,y = %d"), xPos, yPos);

			// MessageBox(hwnd, buf, TEXT("鼠标左键按下"), MB_OK);
			// break;
		 //}
		 //case WM_KEYDOWN:
			//	 MessageBox(hwnd, TEXT("键按下"), TEXT("键盘按下"), MB_OK);
			// break;
     }
	 return DefWindowProc(hwnd, umessage, wparam, lparam);
 }
