#include "kPlayScene.h"
#include "kInput.h"
#include "kSceneManager.h"
#include "kPlayer.h"
#include "kMonster.h"
#include "kCollisionManager.h"
#include "kBgImageObject.h"

//#include "kObstacleManager.h"

namespace k
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		//BgImageObject* bg = new BgImageObject();
		//bg->SetImage(L"LogoBG", L"LogoBG.bmp");
		//bg->Initialize();
		//AddGameObject(bg);

		AddGameObject(new Player(), eColliderLayer::Player);
		AddGameObject(new Monster(), eColliderLayer::Monster);


		Monster* pMonster = new Monster();
		pMonster->SetPos({ 1600 / 2 + 130, 300 / 2 });

		AddGameObject(pMonster, eColliderLayer::Monster);
		CollisionManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player, true);
		CollisionManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player_Projecttile, true);
	}
	void PlayScene::Tick()
	{
		Scene::Tick();
		//k::ObstacleManager::GetObstacleManager()->Tick();

		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeSccene(eSceneType::End);
		}

	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		//k::ObstacleManager::GetObstacleManager()->Render(hdc);

		wchar_t szFloat[50] = {};
		swprintf_s(szFloat, 50, L"Game PlayScene");
		int strLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 30, szFloat, strLen); //화면에 Text출력
	}
	void PlayScene::Enter()
	{
	}
	void PlayScene::Exit()
	{
	}
}