#include "kTitleScene.h"
#include "kImage.h"
#include "kResources.h"
#include "kInput.h"
#include "kSceneManager.h"
#include "kBgImageObject.h"
namespace k
{
	TitleScene::TitleScene()
	{
		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"TitleScene", L"..\\Resources\\Image\\TitleScene.bmp");
		}
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		BgImageObject* bg = new BgImageObject();
		bg->SetImage(L"TitleScene", L"TitleScene.bmp");
		bg->Initialize();

		AddGameObject(bg, eColliderLayer::BackGround);
	}
	void TitleScene::Tick()
	{
		Scene::Tick();
		// ���⼭ ���������� �Ѿ���ְ� �ؾ��Ѵ�.
		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeSccene(eSceneType::Play);
		}
	}
	void TitleScene::Render(HDC hdc)
	{

		Scene::Render(hdc);

		BitBlt(hdc, 0, 0
			, mImage->GetWidth(), mImage->GetHeight()
			, mImage->GetDC(), 0, 0, SRCCOPY);

		wchar_t szFloat[50] = {};
		swprintf_s(szFloat, 50, L"TitleScene");
		int strLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 40, szFloat, strLen); //ȭ�鿡 Text���
		
	}
	void TitleScene::Enter()
	{
	}
	void TitleScene::Exit()
	{
	}
}