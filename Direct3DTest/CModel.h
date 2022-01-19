#pragma once
#include"CD3D.h"
#include<string>
#include<cstringt.h>
#include<vector>
using namespace std;

class CModel
{
public:
	CModel();
	~CModel();

	HRESULT InitModel(LPDIRECT3DDEVICE9 lpDevice, LPCWSTR model);
	
	void SetSize(LPCWSTR  model, float x, float y, float z);
	void SetPosition();
	void SetRotate();
	HRESULT DrawModel(LPDIRECT3DDEVICE9 lpDevice);
	void Close();

private:
	HRESULT LoadModel(LPCWSTR model);
	void LoadTexture(LPCWSTR model);

	struct Vertex   ///定义顶点信息
	{
		FLOAT x, y, z;
		//FLOAT nx, ny, nz;
		//FLOAT u, v;
		DWORD  color;
	};

	//#define D3DFVF_CUSTOMVERTEX		(D3DFVF_XYZ | D3DFVF_NORMAL|D3DFVF_TEX1)
	#define D3DFVF_CUSTOMVERTEX		(D3DFVF_XYZ | D3DFVF_DIFFUSE)


	LPDIRECT3DVERTEXBUFFER9 m_pVB ;
	LPDIRECT3DINDEXBUFFER9 m_pIB;

	LPDIRECT3DTEXTURE9 m_pTexture;

	int  m_vertexCount;
	int  m_indexCount;
	Vertex *m_vertexList;  ///保存单个模型的所有顶点位置、法线、贴图信息
	WORD   *m_indexList;   ///保存索引顺序

	bool CreateModel(LPCWSTR model);

	HRESULT LoadTriangleMesh();
	HRESULT LoadPlaneMesh();

	bool LoadCube();

	bool LoadSphere();

};
///Triangel
class  CTriangle
{
public:
	CTriangle();
	~CTriangle();

private:

};


///平面类
class CPlane
{
public:
	CPlane(int x, int y);
	~CPlane();


private:
	int x;
	int y;
};

///Cube类
class CCube
{
public:
	CCube(int x, int y,int z);
	~CCube();

private:
	int x;
	int y;
	int z;
};

