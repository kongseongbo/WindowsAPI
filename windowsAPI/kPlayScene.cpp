#include "kPlayScene.h"
#include "kInput.h"
#include "kSceneManager.h"
#include "kPlayer.h"
#include "kMonster.h"
#include "kCollisionManager.h"
#include "kBgImageObject.h"
#include "kMap.h"
#include "kObject.h"
#include "kMushroom.h"
#include "kImage.h"
#include "kResources.h"
#include "kGround.h"
#include "kUIManager.h"
#include "kHUD.h"
#include "kButton.h"

//#include "kObstacleManager.h"

namespace k
{
	PlayScene::PlayScene()
	{
		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"PlayScene", L"..\\Resources\\Image\\Map\\HenesysGolemSawonBG.bmp");
			mImage = Resources::Load<Image>(L"PlayScene1", L"..\\Resources\\Image\\Map\\HenesysGolemSawon.bmp");
			
		}
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		//BackImage
		BgImageObject* bg1 = new BgImageObject();
		Map* bg2 = new Map();
		bg1->SetImage(L"PlayScene", L"HenesysGolemSawonBG.bmp");
		bg1->Initialize();
		bg2->SetImage(L"PlayScene1", L"HenesysGolemSawon.bmp");
		bg2->Initialize();
		AddGameObject(bg1, eColliderLayer::BackGround);
		AddGameObject(bg2, eColliderLayer::BackGround2);

		//Player
		k::object::Instantiate<Player>(eColliderLayer::Player);
		
		//MushMom
		mushs[0] = k::object::Instantiate<Mushroom>(eColliderLayer::Monster);
		//mushs[1] = k::object::Instantiate<Mushroom>(Vector2{ 1600 / 2 + 130, 300 / 2 }, eColliderLayer::Mushmom);
		
		//Ground
		Ground* ground = k::object::Instantiate<Ground>(eColliderLayer::Ground);
		ground->SetPos(Vector2(700.0f, 700.0f));

		//HP Bar
		UIManager::Push(eUIType::HP);
		UIManager::Push(eUIType::MP);

		//mons[0] = k::object::Instantiate<Monster>(eColliderLayer::Monster);
		//mons[1] = k::object::Instantiate<Monster>(Vector2{ 1600 / 4 + 130, 300 / 4 }, eColliderLayer::Monster);

	}
	void PlayScene::Tick()
	{
		Scene::Tick();
		//k::ObstacleManager::GetObstacleManager()->Tick();

		//k::object::Destroy(mons[0], 3.0f); // n초 뒤 오브젝트 삭제
		
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
		CollisionManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player, true);
		CollisionManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player_Projecttile, true);
		CollisionManager::SetLayer(eColliderLayer::Ground, eColliderLayer::Player, true);
	}
	void PlayScene::Exit()
	{
	}
}