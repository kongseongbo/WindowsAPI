#pragma once

#include "framework.h"

#include <string>
#include <vector>
#include <list>
#include <map>
#include <bitset>
#include <set>

#include "Maths.h"
#include "def.h"

//TransparentBlt을 사용하기 위해 추가
#pragma comment(lib,"Msimg32.lib")

struct WindowData
{
	HWND hWnd; // 윈도우의 핸들
	HDC hdc; // 메인 그림 담당

	HBITMAP backTexture; //백 그림 도화지
	HDC backBuffer; // 백 그림 담당

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

struct Pen
{
private:
	HDC mHdc;
	HPEN mOldPen;
	HPEN mPen;

public:
	Pen(HDC hdc)
		: mHdc(hdc)
		, mOldPen(NULL)
		, mPen(NULL)
	{
	}
	Pen(HDC hdc, HPEN pen)
		: mHdc(hdc)
		, mOldPen(NULL)
		, mPen(pen)
	{
		mOldPen = (HPEN)SelectObject(mHdc, pen);
	}
	~Pen()
	{
		SelectObject(mHdc, mOldPen);
		DeleteObject(mPen);
	}

	void SetPen(HPEN pen)
	{
		mOldPen = (HPEN)SelectObject(mHdc, pen);
	}
};

struct Brush
{
private:
	HDC mHdc;
	HBRUSH mOldBrush;
	HBRUSH mBrush;

public:
	Brush(HDC hdc, HBRUSH brush)
		:mHdc(hdc)
		, mOldBrush(NULL)
		,mBrush(brush)
	{
		mOldBrush = (HBRUSH)SelectObject(mHdc, brush);
	}
	~Brush()
	{
		SelectObject(mHdc, mOldBrush);
		DeleteObject(mBrush);
	}
};
