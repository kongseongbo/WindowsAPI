#include "kApplication.h"
#include "kSceneManager.h"
#include "kTime.h"
#include "kInput.h"
#include "kResources.h"
#include "kCollisionManager.h"
#include "kCamera.h"


namespace k
{
	void Application::Initialize(WindowData data)
	{
		initializeWindow(data);
		
		Time::Initialize();
		Input::Initialize();
		SceneManager::Initialize();
	}
	void Application::Tick()
	{
		Time::Tick();
		Input::Tick();
		Camera::Initialize();

		Camera::Tick();
		SceneManager::Tick();
		CollisionManager::Tick();

		//clear
		//Brush brush(mWindowData.backBuffer, mBrushes[(UINT)eBrushColor::Gray]);
		HBRUSH hPrevBrush = (HBRUSH)SelectObject(mWindowData.backBuffer, mBrushes[(UINT)eBrushColor::Gray]);
		Rectangle(mWindowData.backBuffer,
			-1, -1, mWindowData.width + 1, mWindowData.height + 1);
		SelectObject(mWindowData.backBuffer, hPrevBrush);

		SceneManager::Render(mWindowData.backBuffer);

		Input::Render(mWindowData.backBuffer);
		Time::Render(mWindowData.backBuffer);

		//더블버퍼링 winapi에는 없기때문에 비슷하게 만듬
		//BitBlt 함수 : DC간에 이미지를 복사 해주는 함수
		BitBlt(mWindowData.hdc
			, 0, 0, mWindowData.width, mWindowData.height
			, mWindowData.backBuffer, 0, 0, SRCCOPY);
	}

	Application::Application()
	{
		mWindowData.clear();
	}
	Application::~Application()
	{
		//동적할당 메모리 해제
		SceneManager::Release(); 
		Resources::Release();

		ReleaseDC(mWindowData.hWnd, mWindowData.hdc);
		ReleaseDC(mWindowData.hWnd, mWindowData.backBuffer);
	}
	void Application::initializeWindow(WindowData data)
	{
		mWindowData = data;
		mWindowData.hdc = GetDC(data.hWnd);

		//비트맵 해상도를 설정하기 위한 실제 윈도우 크기 계산
		RECT rect = { 0,0,mWindowData.width,mWindowData.height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		//윈도우 크기 변경
		SetWindowPos(mWindowData.hWnd, nullptr, 0, 0
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0);

		ShowWindow(mWindowData.hWnd, true);

		mWindowData.backTexture 
			= CreateCompatibleBitmap(mWindowData.hdc, mWindowData.width, mWindowData.height);

		mWindowData.backBuffer = CreateCompatibleDC(mWindowData.hdc);

		HBITMAP dafaultBitmap 
			= (HBITMAP)SelectObject(mWindowData.backBuffer, mWindowData.backTexture);

		DeleteObject(dafaultBitmap);


		//자주 사용하는 pen brush 설정
		//메모리 해제해줘야한다.
		mPens[(UINT)ePenColor::Red] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		mPens[(UINT)ePenColor::Green] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
		mPens[(UINT)ePenColor::Blue] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));

		mBrushes[(UINT)eBrushColor::Transparent] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
		mBrushes[(UINT)eBrushColor::Black] = (HBRUSH)GetStockObject(BLACK_BRUSH);
		mBrushes[(UINT)eBrushColor::Gray] = (HBRUSH)GetStockObject(GRAY_BRUSH);
		mBrushes[(UINT)eBrushColor::White] = (HBRUSH)GetStockObject(WHITE_BRUSH);

		
	}
}
