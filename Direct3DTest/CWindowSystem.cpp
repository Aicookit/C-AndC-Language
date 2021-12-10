
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
		MessageBox(m_hWnd, "��ʼ������ʧ��", NULL, MB_OK);
	}
	
	//ʵ������

	return true;
}

bool CWindowSystem::Run()
{
	MSG message = {};
	//ZeroMemory(&message, sizeof(MSG));
	bool flag = true;
	while (flag)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_NOREMOVE))  //�ȴ���Ϣ��������false
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
			 //������Window��β�ķ����������������Ϣ���У�����ֱ��ֱ��ִ��
			 DestroyWindow(hwnd); //DestroyWindow������һ����Ϫ WM__DESTROY
			 break;
		 }
		 case WM_DESTROY:
			 PostQuitMessage(0); //��ʱGetMessage()��ֵΪFALSE�����ڲŻᱻ�ص�
		 //case WM_LBUTTONDOWN: //����������
		 //{
			// int xPos = LOWORD(lparam);//��ȡ��갴�µ�����
			// int yPos = HIWORD(lparam);

			// TCHAR buf[1024];
		
			// wsprintf(buf, TEXT("x = %d,y = %d"), xPos, yPos);

			// MessageBox(hwnd, buf, TEXT("����������"), MB_OK);
			// break;
		 //}
		 //case WM_KEYDOWN:
			//	 MessageBox(hwnd, TEXT("������"), TEXT("���̰���"), MB_OK);
			// break;
     }
	 return DefWindowProc(hwnd, umessage, wparam, lparam);
 }
