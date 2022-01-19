#include"CGraphicEngine.h"

CGraphicEngine::CGraphicEngine()
{
}

CGraphicEngine::~CGraphicEngine()
{
}

bool CGraphicEngine::InitAllComponets(HWND hWnd)
{
	d3d = new CD3D();
	if (FAILED(d3d->InitD3D(hWnd)))
	{
		MessageBox(NULL, "初始化d3d失败", "失败", MB_OK);
		return false;
	}
	m_pDevice = d3d->GetDevice();

	if (!CreateFrameHud())
	{
		MessageBox(hWnd, "5创建帧率抬头失败", "帧率失败", MB_OK);
		return false;
	}

	if (model==NULL)
	{
		model = new CModel();
	}
	model->InitModel(m_pDevice, L"Plane");
	//model->InitModel(m_pDevice, L"Triangle");


	return true;
}

bool CGraphicEngine::FrameUpdata()
{
	StartCountFrame();
	d3d->BeginRender();

	model->DrawModel(m_pDevice);

	EndCountFrame();
	d3d->EndRender();

	return true;
}

void CGraphicEngine::Close()
{

	m_pDevice->Release();
	m_pDevice = NULL;

	g_pFont->Release();
	g_pFont = NULL;

	if (d3d != NULL)
	{
		d3d->Shutdown();
		delete d3d;
		d3d = 0;
	}

	if (model!=NULL)
	{
		model->Close();
		delete model;
		model = 0;
	}
}

#pragma region Frame Show
bool CGraphicEngine::CreateFrameHud()
{
	// 创建字体
	if (FAILED(D3DXCreateFont(m_pDevice, 36, 0, 0, 1, false, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, "Arial", &g_pFont)))
		return false;
	return true;
}

void CGraphicEngine::StartCountFrame()
{
	DWORD dw = timeGetTime() - g_dwTimeStart;
	if (dw > 1000)
	{
		g_dwTimeStart = timeGetTime();
		g_dwFPS = g_dwFrameCount;
		g_dwFrameCount = 0;
	}
	else
	{
		++g_dwFrameCount;
	}
}

void CGraphicEngine::EndCountFrame()
{
	//渲染字体
	RECT Rect = { 0, 0, 300, 60 };
	char szFPS[256];
	sprintf_s(szFPS, "FPS : %d", g_dwFPS);
	g_pFont->DrawTextA(NULL, szFPS, -1, &Rect, DT_TOP, D3DCOLOR_XRGB(255, 255, 255));
}


#pragma endregion