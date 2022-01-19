#pragma once
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib,"winmm.lib")

//#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include <stdio.h>
#include<iostream>

///#include 是以当前文件所在路径为当前目录
///#pragma comment 是以当前工程所在路径为当前目录
///静态库(lib)的调用需要头文件(#include ".h")和添加库文件(.lib)
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



// 作为Direct3D 中的渲染部件，LPDIRECT3DDEVICE9 设备对象用于顶点变换、光照处理以及矢量图形的光栅化