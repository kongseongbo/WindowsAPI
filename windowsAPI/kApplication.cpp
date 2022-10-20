#include "kApplication.h"
#include "kSceneManager.h"

namespace k
{
	void Application::Initialize(WindowData data)
	{
		mWindowData = data;
		mWindowData.hdc = GetDC(data.hWnd);

		SceneManager::Initialize();
	}
	void Application::Tick() // update
	{
		SceneManager::Tick();
		SceneManager::Render(mWindowData.hdc);
	}

	Application::Application()
	{
		mWindowData.clear();
	}
	Application::~Application()
	{
		SceneManager::Reelease();

		ReleaseDC(mWindowData.hWnd, mWindowData.hdc);
	}
}
