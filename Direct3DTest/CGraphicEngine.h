///d3d类实例化后相当于一个图形引擎,管理所有组件包括d3d,camera , input,material...
#pragma once
//#include<Windows.h>
#include "CD3D.h"
#include "CModel.h"

class CGraphicEngine
{
public:
	CGraphicEngine();
	~CGraphicEngine();

	bool InitAllComponets(HWND hWnd);
	bool FrameUpdata();
	void Close();
	 
private:
	CD3D * d3d;

	LPDIRECT3DDEVICE9 m_pDevice;


	///Model组件
	CModel *model;


	///声明文本显示接口
	LPD3DXFONT g_pFont = NULL;
	DWORD g_dwTimeStart = 0;
	DWORD g_dwFrameCount = 0;
	DWORD g_dwFPS = 0;
	bool CreateFrameHud();
	void StartCountFrame();
	void EndCountFrame();
};

