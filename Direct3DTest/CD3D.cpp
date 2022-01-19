#include"CD3D.h"

CD3D::CD3D()
{
}

CD3D::~CD3D()
{
}

bool CD3D::InitD3D(HWND hWnd)
{
	///生成D3D接口对象
	if ((m_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
		return false;

	///获取D3D设备信息
	D3DCAPS9 caps;
	int  vp = 0;
	if (FAILED(m_pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps)))
	{
		MessageBox(NULL, "没有硬件设备", "失败", MB_OK);
		return false;
	}
	if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
	{
		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;  ///支持硬件顶点运算，我们就采用硬件顶点运算
	}
	else
	{
		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;  ///支持硬件顶点运算
	}


	D3DPRESENT_PARAMETERS  d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

	if (FAILED(m_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT,  ///默认显卡
		D3DDEVTYPE_HAL,     ///设备类型
		hWnd,
		vp,  ///用了软件顶点处理方式
		&d3dpp,
		&m_pDevice)))
	{
		MessageBox(hWnd, "4初始化D3D设备对象失败", "设备对象失败", MB_OK);
		return false;
	}
	m_pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	m_pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	return true;

}

LPDIRECT3DDEVICE9 CD3D::GetDevice()
{
	return m_pDevice;

}

HRESULT CD3D::BeginRender()
{
	HRESULT hr;
	m_pDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(125, 125, 125), 1.0f, 0);
	hr = m_pDevice->BeginScene();
	if (FAILED(hr))
	{
		return E_FAIL;
	}
	return S_OK;
}

void CD3D::EndRender()
{
	m_pDevice->EndScene();
	m_pDevice->Present(NULL, NULL, NULL, NULL);
}

void CD3D::Shutdown()
{
	m_pD3D->Release();
	m_pD3D = NULL;
	m_pDevice->Release();
	m_pDevice = NULL;

}

