#pragma once
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib,"winmm.lib")

//#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include <stdio.h>
#include<iostream>

///#include ���Ե�ǰ�ļ�����·��Ϊ��ǰĿ¼
///#pragma comment ���Ե�ǰ��������·��Ϊ��ǰĿ¼
///��̬��(lib)�ĵ�����Ҫͷ�ļ�(#include ".h")����ӿ��ļ�(.lib)
class  CD3D
{
public:
	 CD3D();
	~ CD3D();

public:
	bool InitD3D(HWND hWnd);
	LPDIRECT3DDEVICE9 GetDevice();
	HRESULT BeginRender();
	void EndRender();
	void Shutdown();

	void GetProMtrx(D3DXMATRIX  pro);
	
private:
	LPDIRECT3D9		   m_pD3D = NULL;
	LPDIRECT3DDEVICE9  m_pDevice = NULL;
};



// ��ΪDirect3D �е���Ⱦ������LPDIRECT3DDEVICE9 �豸�������ڶ���任�����մ����Լ�ʸ��ͼ�εĹ�դ��