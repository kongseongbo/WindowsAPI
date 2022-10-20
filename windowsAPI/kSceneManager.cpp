#include "kSceneManager.h"
#include "kLogoScene.h"

namespace k
{
	Scene* SceneManager::mScenes[(UINT)eSceneType::Max] ={};
	Scene* SceneManager::mPlayScene = nullptr;

	void SceneManager::Initialize()
	{
		//모든 씬들을 초기화
		mScenes[(UINT)eSceneType::Logo] = new LogoScene();
		mScenes[(UINT)eSceneType::Logo]->Initialize();

		mPlayScene = mScenes[(UINT)eSceneType::Logo];
	}
	void SceneManager::Tick()
	{
		//현재 씬들을 update Tick
		mPlayScene->Tick();
	}
	void SceneManager::Render(HDC hdc)
	{
		//현재 씬 Render
		mPlayScene->Render(hdc);
	}
	void SceneManager::Reelease()
	{
		//프로그램 종료될때 한번만 호출
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			delete scene;
			scene = nullptr;
		}
	}
}