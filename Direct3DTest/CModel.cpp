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
	//{ {-1.0f, 0.0f, 0.0f, D3DCOLOR_XRGB(255,0,0) }, //点 B，红色
	//{  0.0f, 1.0f, 0.0f, D3DCOLOR_XRGB(0,255,0) }, //点 A，绿色
	//{ 1.0f, 0.0f, 0.0f, D3DCOLOR_XRGB(255,255,255) }, //点 C，浅蓝
	//{ 0.0f, -1.0f, 0.0f, D3DCOLOR_XRGB(0,0,0) } }; //点 D，粉红
	//WORD indices[] = {0, 1, 2,0,2,3}; //索引序列
	///创建buffer
	lpDevice->CreateVertexBuffer(m_vertexCount*sizeof(*m_vertexList), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &m_pVB, NULL);
	
	///顶点信息填入顶点缓存
	Vertex * pVertices = NULL;
	m_pVB->Lock(0, m_vertexCount * sizeof(*m_vertexList),(void**)&pVertices, 0);
	//memcpy(pVertices, tempVertices, m_vertexCount * sizeof(*m_vertexList));//怎么把指针m_vertexList还原成数组复制到pVertices中
	pVertices = m_vertexList;
	m_pVB->Unlock();

	///创建索引缓冲区
	lpDevice->CreateIndexBuffer(m_indexCount * sizeof(*m_indexList),0,
		D3DFMT_INDEX16, D3DPOOL_DEFAULT,&m_pIB,NULL);
	int a64 = m_vertexCount * sizeof(*m_vertexList);
	///把索引信息填入索引缓冲区
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

	//2.1绘制物体前，调用对象方法渲染纹理
	//lpDevice->SetTexture(0, g_pTexture);
	//hr = lpDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
	hr =lpDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, m_vertexCount, 0, m_indexCount/3);  //集合开始绘制
	if (FAILED(hr))
	{
		MessageBox(NULL, "顶点绘制失败", "失败", MB_OK);
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
		MessageBox(NULL, "CreateModel失败", "失败", MB_OK);
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
		//此时应该已经确定所有顶点信息
		LoadTriangleMesh();
	}
	if (L"Plane"== emodel)
	{
		//此时应该已经确定所有顶点信息
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
	m_vertexList = vertices; ///拿到素有顶点信息并把内存地址告诉指针m_vertexList
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
	m_vertexList = vertexs; ///拿到素有顶点信息并把内存地址告诉指针m_vertexList
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

///平面类

CPlane::CPlane(int x,int y):x{1},y{1}
{
}

CPlane::~CPlane()
{
}



///Cube类
CCube::CCube(int x, int y, int z):x{1},y{1},z{1}
{
}

CCube::~CCube()
{
}