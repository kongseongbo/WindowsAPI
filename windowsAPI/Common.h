#pragma once

#include "framework.h"

#include <string>
#include <vector>
#include <list>
#include <map>

#include "Maths.h"
#include "def.h"

struct WindowData
{
	HWND hWnd; // 윈도우의 핸들
	HDC hdc; 
	UINT height; // 32bit unsigned int
	UINT width; 

	void clear()
	{
		hWnd = nullptr;
		hdc = nullptr;
		height = 0;
		width = 0;
	}
};

