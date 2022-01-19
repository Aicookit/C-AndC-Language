///d3d��ʵ�������൱��һ��ͼ������,���������������d3d,camera , input,material...
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


	///Model���
	CModel *model;


	///�����ı���ʾ�ӿ�
	LPD3DXFONT g_pFont = NULL;
	DWORD g_dwTimeStart = 0;
	DWORD g_dwFrameCount = 0;
	DWORD g_dwFPS = 0;
	bool CreateFrameHud();
	void StartCountFrame();
	void EndCountFrame();
};

