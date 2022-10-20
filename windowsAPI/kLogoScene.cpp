#include "kLogoScene.h"


namespace k
{
	LogoScene::LogoScene()
	{
	}
	LogoScene::~LogoScene()
	{
	}
	void LogoScene::Initialize()
	{
	}
	void LogoScene::Tick()
	{
		//오브젝트 tick 을 호출한다.
		Scene::Tick(); // 부모 가상함수 호출
	}
	void LogoScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}