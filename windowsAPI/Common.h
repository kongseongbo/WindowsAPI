#pragma once

#include "framework.h"

#include <string>
#include <vector>
#include <list>
#include <map>

#include "Maths.h"

//using  Pos = POINT; // == typedef Pos = POINT;

struct WindowData
{
	HWND hWnd;
	HDC hdc;
	UINT height;
	UINT width;

	void clear()
	{
		hWnd = nullptr;
		hdc = nullptr;
		height = 0;
		width = 0;
	}
};

