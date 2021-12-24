///d3d类实例化后相当于一个图形引擎,管理所有组件包括d3d,camera , input,material...
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

