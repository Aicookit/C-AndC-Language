#include"CD3D.h"

CD3D::CD3D()
{
}

CD3D::~CD3D()
{
}

HRESULT CD3D::InitD3D(HWND hWnd)
{
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (m_pD3D == NULL)
	{
		MessageBox(hWnd, "1", "2", MB_OK);
		return E_FAIL;
	}
	D3DPRESENT_PARAMETERS  d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

	if (FAILED(m_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT,  ///默认显卡
		D3DDEVTYPE_HAL,     ///设备类型
		hWnd,D3DCREATE_SOFTWARE_VERTEXPROCESSING,&d3dpp,&m_pDevice)))
		return E_FAIL;
	else
	{
		MessageBox(hWnd, "3成功", "4成功", MB_OK);
	}
	return S_OK;
}

void CD3D::GetDevice(LPDIRECT3D9 * d3dDevice)
{
}

void CD3D::BeginRender()
{
}

void CD3D::EndRender()
{
}

void CD3D::Shutdown()
{
}
