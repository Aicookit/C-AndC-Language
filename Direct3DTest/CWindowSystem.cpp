
#include"CWindowSystem.h"

CWindowSystem::CWindowSystem()
{
}

CWindowSystem::~CWindowSystem()
{
}

bool CWindowSystem::Init()
{
	//int screenWidth, screenHeigh;
	//screenWidth = 0;
	//screenHeigh = 0;
	//InitWindow();
	bool isInitWindows = InitWindow(600, 400);

	if (!isInitWindows)
	{
		MessageBox(m_hWnd, "初始化窗口失败", NULL, MB_OK);
	}
	
	//实例引擎

	return true;
}

bool CWindowSystem::Run()
{
	MSG message = {};
	//ZeroMemory(&message, sizeof(MSG));
	bool flag = true;
	while (flag)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_NOREMOVE))  //等待消息处理完后变false
		{
			if (message.message == WM_QUIT)
			{
				break;
			}

			if (GetMessage(&message,NULL,0,0))
			{
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
		}
		
		//Render...
	}

	return true;
}

void CWindowSystem::Close()
{
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
		return 0;
	}

	ShowWindow(m_hWnd, SW_SHOW);

	UpdateWindow(m_hWnd);

	return true;
}


 LRESULT CALLBACK CWindowSystem::WindowProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
 {
     switch (umessage)
     {
		 case WM_CLOSE:
		 {
			 //所有以Window结尾的方法，都不会进入消息队列，而是直接直接执行
			 DestroyWindow(hwnd); //DestroyWindow发送另一个夏溪 WM__DESTROY
			 break;
		 }
		 case WM_DESTROY:
			 PostQuitMessage(0); //此时GetMessage()的值为FALSE，窗口才会被关掉
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
