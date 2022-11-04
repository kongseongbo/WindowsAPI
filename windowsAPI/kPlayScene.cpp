#include "kPlayScene.h"
#include "kInput.h"
#include "kSceneManager.h"
#include "kPlayer.h"
#include "kMonster.h"
#include "kCollisionManager.h"
#include "kBgImageObject.h"
#include "kObjcet.h"

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
		
		k::object::Instantiate<Player>(eColliderLayer::Player);
		mons[0] = k::object::Instantiate<Monster>(eColliderLayer::Monster);
		mons[1] = k::object::Instantiate<Monster>(Vector2{ 1600 / 2 + 130, 300 / 2 }, eColliderLayer::Monster);

		CollisionManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player, true);
		CollisionManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player_Projecttile, true);
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
	}
	void PlayScene::Exit()
	{
	}
}