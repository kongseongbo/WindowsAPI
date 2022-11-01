#include "kLogoScene.h"
#include "kSceneManager.h"
#include "kInput.h"

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
		//������Ʈ tick �� ȣ���Ѵ�.
		Scene::Tick();

		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeSccene(eSceneType::Title);
		}

	}
	void LogoScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t szFloat[50] ={};
		swprintf_s(szFloat, 50, L"LogoScene");
		int strLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 40, szFloat, strLen); //ȭ�鿡 Text���
	}
	void LogoScene::Enter()
	{
	}
	void LogoScene::Exit()
	{
	}
}