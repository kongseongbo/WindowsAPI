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
		//������Ʈ tick �� ȣ���Ѵ�.
		Scene::Tick(); // �θ� �����Լ� ȣ��
	}
	void LogoScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}