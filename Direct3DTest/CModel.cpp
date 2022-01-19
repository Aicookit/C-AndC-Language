#include"CModel.h"

CModel::CModel()
{
}

CModel::~CModel()
{
}

HRESULT CModel::InitModel(LPDIRECT3DDEVICE9 lpDevice, LPCWSTR  model)
{
	 LoadModel(model);
	//LoadTexture(texture);
	//Vertex vertices[] =
	//{ {-1.0f, 0.0f, 0.0f, D3DCOLOR_XRGB(255,0,0) }, //�� B����ɫ
	//{  0.0f, 1.0f, 0.0f, D3DCOLOR_XRGB(0,255,0) }, //�� A����ɫ
	//{ 1.0f, 0.0f, 0.0f, D3DCOLOR_XRGB(255,255,255) }, //�� C��ǳ��
	//{ 0.0f, -1.0f, 0.0f, D3DCOLOR_XRGB(0,0,0) } }; //�� D���ۺ�
	//WORD indices[] = {0, 1, 2,0,2,3}; //��������
	///����buffer
	lpDevice->CreateVertexBuffer(m_vertexCount*sizeof(*m_vertexList), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &m_pVB, NULL);
	
	///������Ϣ���붥�㻺��
	Vertex * pVertices = NULL;
	m_pVB->Lock(0, m_vertexCount * sizeof(*m_vertexList),(void**)&pVertices, 0);
	//memcpy(pVertices, tempVertices, m_vertexCount * sizeof(*m_vertexList));//��ô��ָ��m_vertexList��ԭ�����鸴�Ƶ�pVertices��
	pVertices = m_vertexList;
	m_pVB->Unlock();

	///��������������
	lpDevice->CreateIndexBuffer(m_indexCount * sizeof(*m_indexList),0,
		D3DFMT_INDEX16, D3DPOOL_DEFAULT,&m_pIB,NULL);
	int a64 = m_vertexCount * sizeof(*m_vertexList);
	///��������Ϣ��������������
	WORD * pIndices = NULL;
	m_pIB->Lock(0, m_indexCount * sizeof(*m_indexList), (void **)&pIndices, 0);
	//memcpy(pIndices, m_indexList, m_indexCount * sizeof(*m_indexList));
	pIndices = m_indexList;
	int b12 = m_indexCount*sizeof(*m_indexList);

	//indices[0] = 0, indices[1] = 1, indices[2] = 2;
	//indices[3] = 0, indices[4] = 2, indices[5] = 3;
	/*for (WORD i = 0; i < sizeof(m_vertexCount); i++)
	{
		indices[i] = i;
	}*/
	m_pIB->Unlock();
	
	return S_OK;
}

void CModel::SetSize(LPCWSTR model, float x, float y, float z)
{
}

HRESULT CModel::DrawModel(LPDIRECT3DDEVICE9 lpDevice)
{
	HRESULT hr;
	lpDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	lpDevice->SetStreamSource(0, m_pVB, 0, sizeof(Vertex));
	lpDevice->SetIndices(m_pIB);

	//2.1��������ǰ�����ö��󷽷���Ⱦ����
	//lpDevice->SetTexture(0, g_pTexture);
	//hr = lpDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
	hr =lpDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, m_vertexCount, 0, m_indexCount/3);  //���Ͽ�ʼ����
	if (FAILED(hr))
	{
		MessageBox(NULL, "�������ʧ��", "ʧ��", MB_OK);
		return E_FAIL;
	}
	return S_OK;
}

void CModel::Close()
{
	m_pVB->Release();
	m_pIB->Release();
	m_pTexture->Release();
	delete[] m_vertexList;
	m_vertexList = 0;
	delete[] m_indexList;
	m_vertexList = 0;
	m_vertexCount= 0;
	m_indexCount = 0;
}

HRESULT CModel::LoadModel(LPCWSTR model)
{
	if (FAILED(CreateModel(model)))
	{
		MessageBox(NULL, "CreateModelʧ��", "ʧ��", MB_OK);
		return E_FAIL;
	}
	return S_OK;
}

void CModel::LoadTexture(LPCWSTR model)
{
}


bool CModel::CreateModel(LPCWSTR emodel)
{
	if (L"Triangle" == emodel)
	{
		//��ʱӦ���Ѿ�ȷ�����ж�����Ϣ
		LoadTriangleMesh();
	}
	if (L"Plane"== emodel)
	{
		//��ʱӦ���Ѿ�ȷ�����ж�����Ϣ
		LoadPlaneMesh();
	}
	if (L"Cube" == emodel)
	{
		LoadCube();
	}
	if (L"Sphere" == emodel)
	{
		LoadSphere();
	}

	return true;
}


HRESULT CModel::LoadTriangleMesh()
{
	//Vertex vertices[] =
	//{
	//	{-1.0f,-1.0f,0.0f,D3DCOLOR_XRGB(255,0,0)},
	//	{ 0.0f,1.0f,0.0f, D3DCOLOR_XRGB(0,255,0)},
	//	{ 1.0f,-1.0f,0.0f,D3DCOLOR_XRGB(0,255,255)},
	//};
	Vertex vertices[3];
	vertices[0].x = -1.0f; vertices[0].y = -1.0f; vertices[0].z = 0.0f;
	vertices[0].color = D3DCOLOR_XRGB(255, 0, 0);
	vertices[1].x = -0.0f; vertices[1].y = 1.0f; vertices[1].z = 0.0f;
	vertices[1].color = D3DCOLOR_XRGB(255, 0, 0);
	vertices[2].x = 1.0f; vertices[2].y = -1.0f; vertices[2].z = 0.0f;
	vertices[2].color = D3DCOLOR_XRGB(255, 0, 0);
	WORD indexes[3] = { 0,1,2 };
	m_vertexList = vertices; ///�õ����ж�����Ϣ�����ڴ��ַ����ָ��m_vertexList
	m_indexList = indexes;
	m_vertexCount = sizeof(vertices) / sizeof(vertices[0]);
	m_indexCount = sizeof(indexes) / sizeof(indexes[0]);
	return S_OK;
}

HRESULT CModel::LoadPlaneMesh()
{
	Vertex  vertexs[4];
	vertexs[0].x = -1.0f; vertexs[0].y = 0.0f;  vertexs[0].z = 0.0f;
	//vertexs[0].nx= -1.0f; vertexs[0].ny = -1.0f; vertexs[0].nz = -1.0f;
	//vertexs[0].u = 0.0f;  vertexs[0].v = 1.0f;
	vertexs[0].color = D3DCOLOR_XRGB(255, 255, 255);

	vertexs[1].x = 0.0f;  vertexs[1].y = 1.0f;  vertexs[1].z = 0.0f;
	//vertexs[1].nx = -1.0f; vertexs[1].ny = 1.0f; vertexs[1].nz = -1.0f;
	//vertexs[1].u = 0.0f;   vertexs[1].v = 0.0f;
	vertexs[1].color = D3DCOLOR_XRGB(0, 255, 0);

	vertexs[2].x =  1.0f; vertexs[2].y =  0.0f;  vertexs[2].z = 0.0f;
	//vertexs[2].nx = 1.0f; vertexs[2].ny = 1.0f; vertexs[2].nz = -1.0f;
	//vertexs[2].u = 1.0f;  vertexs[2].v =  0.0f;
	vertexs[2].color = D3DCOLOR_XRGB(0, 0, 0);

	vertexs[3].x = 0.0f; vertexs[3].y = -1.0f;  vertexs[3].z = 0.0f;
	//vertexs[3].nx = 1.0f; vertexs[3].ny = -1.0f; vertexs[3].nz = -1.0f;
	//vertexs[3].u = 1.0f;  vertexs[3].v = 1.0f;
	vertexs[3].color = D3DCOLOR_XRGB(0, 0, 0);
	
	WORD indexes[6] = { 0,1,2,0,2,3 };
	m_vertexList = vertexs; ///�õ����ж�����Ϣ�����ڴ��ַ����ָ��m_vertexList
	m_indexList =  indexes;
	m_vertexCount = sizeof(vertexs)/sizeof(vertexs[0]);
	m_indexCount  = sizeof(indexes)/sizeof(indexes[0]);
	return S_OK;
}

bool CModel::LoadCube()
{
	return true;
}

bool CModel::LoadSphere()
{
	return true;
}


///Triangel
CTriangle::CTriangle()
{
}

CTriangle::~CTriangle()
{
}

///ƽ����

CPlane::CPlane(int x,int y):x{1},y{1}
{
}

CPlane::~CPlane()
{
}



///Cube��
CCube::CCube(int x, int y, int z):x{1},y{1},z{1}
{
}

CCube::~CCube()
{
}