#include "kSceneManager.h"
#include "kLogoScene.h"
#include "kTitleScene.h"
#include "kPlayScene.h"
#include "kEndScene.h"

namespace k
{
	Scene* SceneManager::mScenes[(UINT)eSceneType::Max] ={};
	Scene* SceneManager::mPlayScene = nullptr; // 현재 화면에 나오고 있는 씬

	void SceneManager::Initialize()
	{
		//모든 씬들을 초기화
		mScenes[(UINT)eSceneType::Logo] = new LogoScene();
		mScenes[(UINT)eSceneType::Logo]->Initialize();

		mScenes[(UINT)eSceneType::Title] = new TitleScene();
		mScenes[(UINT)eSceneType::Title]->Initialize();

		mScenes[(UINT)eSceneType::Play] = new PlayScene();
		mScenes[(UINT)eSceneType::Play]->Initialize();

		mScenes[(UINT)eSceneType::End] = new EndScene();
		mScenes[(UINT)eSceneType::End]->Initialize();

		
		//mPlayScene = mScenes[(UINT)eSceneType::Logo];
		ChangeSccene(eSceneType::Logo);
		//업캐스팅
		//다운캐스팅
	}
	void SceneManager::Tick()
	{
		//현재 씬  Tick
		mPlayScene->Tick();
		
	}
	void SceneManager::Render(HDC hdc)
	{
		//현재 씬 Render
		mPlayScene->Render(hdc);
	}
	void SceneManager::Release()
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
	void SceneManager::ChangeSccene(eSceneType type)
	{
		if (mPlayScene == nullptr)
		{
			mPlayScene = mScenes[(UINT)eSceneType::Logo];
		}
		else
		{
			mPlayScene->Exit();
			mPlayScene = mScenes[(UINT)type];
		}

		mPlayScene->Enter();

	}
}