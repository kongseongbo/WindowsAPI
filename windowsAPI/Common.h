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
#include <filesystem> // ��ε��� ó���ϴ� ���̺귯��
#include <assert.h>

#include "Maths.h"
#include "def.h"

//������ ���̺귯��
#pragma comment(lib, "Msimg32.lib")
//���� ���̺귯��
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
	// ���� Ÿ��
	// �����ӹ���

	HWND hWnd; // �������� �ڵ�
	HDC hdc; // ���� �׸� ���

	HBITMAP backTexture; //�� �׸� ��ȭ��
	HDC backBuffer; // �� �׸� ���

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
