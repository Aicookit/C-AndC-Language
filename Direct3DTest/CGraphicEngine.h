///d3d��ʵ�������൱��һ��ͼ������,���������������d3d,camera , input,material...
#pragma once
#include<Windows.h>
#include"CD3D.h"

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
};

