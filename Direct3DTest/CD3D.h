#pragma once
#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>

class  CD3D
{
public:
	 CD3D();
	~ CD3D();

public:
	HRESULT InitD3D(HWND hWnd);
	void GetDevice(LPDIRECT3D9 *d3dDevice);
	void BeginRender();
	void EndRender();
	void Shutdown();

	void GetProMtrx(D3DXMATRIX  pro);
	
private:
	LPDIRECT3D9		   m_pD3D;
	LPDIRECT3DDEVICE9  m_pDevice;

};

