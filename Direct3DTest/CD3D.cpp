#include"CD3D.h"

CD3D::CD3D()
{
}

CD3D::~CD3D()
{
}

bool CD3D::InitD3D(HWND hWnd)
{
	///����D3D�ӿڶ���
	if ((m_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
		return false;

	///��ȡD3D�豸��Ϣ
	D3DCAPS9 caps;
	int  vp = 0;
	if (FAILED(m_pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps)))
	{
		MessageBox(NULL, "û��Ӳ���豸", "ʧ��", MB_OK);
		return false;
	}
	if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
	{
		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;  ///֧��Ӳ���������㣬���ǾͲ���Ӳ����������
	}
	else
	{
		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;  ///֧��Ӳ����������
	}


	D3DPRESENT_PARAMETERS  d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

	if (FAILED(m_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT,  ///Ĭ���Կ�
		D3DDEVTYPE_HAL,     ///�豸����
		hWnd,
		vp,  ///����������㴦��ʽ
		&d3dpp,
		&m_pDevice)))
	{
		MessageBox(hWnd, "4��ʼ��D3D�豸����ʧ��", "�豸����ʧ��", MB_OK);
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

