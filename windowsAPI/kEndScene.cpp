#include "kEndScene.h"
#include "kInput.h"
#include "kSceneManager.h"

namespace k
{
	EndScene::EndScene()
	{
	}
	EndScene::~EndScene()
	{
	}
	void EndScene::Initialize()
	{
	}
	void EndScene::Tick()
	{
		Scene::Tick();
	}
	void EndScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t szFloat[50] = {};
		swprintf_s(szFloat, 50, L"EndScene");
		int strLen = wcsnlen_s(szFloat, 50);

		TextOut(hdc, 10, 40, szFloat, strLen); //화면에 Text출력
	}
	void EndScene::Enter()
	{
	}
	void EndScene::Exit()
	{
	}
}