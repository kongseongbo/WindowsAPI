#pragma once

#include "framework.h"

#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <bitset>
#include <set>
#include <functional> 
#include <filesystem> // 경로등을 처리하는 라이브러리
#include <assert.h>

#include "Maths.h"
#include "def.h"

//렌더링 라이브러리
#pragma comment(lib, "Msimg32.lib")
//사운드 라이브러리
#include <mmsystem.h>
#include <dsound.h>
#include <dinput.h>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dsound.lib")

//typedef Pos POINT;
//using Pos = POINT;

//typedef std::vector<std::vector<GameObject*>> GameObjects;
//typedef std::vector<GameObject*> LayerObjects;

struct Pixel
{
	BYTE R;
	BYTE G;
	BYTE B;
	BYTE A;

	Pixel(BYTE r, BYTE g, BYTE b, BYTE a)
		:R(r), G(g), B(b), A(a)
	{

	}
		
};

struct WindowData
{
	// 렌더 타겟
	// 프레임버퍼

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
		: mHdc(hdc)
		, mOldBrush(NULL)
		, mBrush(brush)
	{
		mOldBrush = (HBRUSH)SelectObject(mHdc, brush);
	}

	~Brush()
	{
		SelectObject(mHdc, mOldBrush);
		DeleteObject(mBrush);
	}
};
