#include "kSceneManager.h"
#include "kLogoScene.h"
#include "kTitleScene.h"
#include "kPlayScene.h"
#include "kEndScene.h"
#include "kToolScene.h"
#include "kObject.h"

namespace k
{
	Scene* SceneManager::mScenes[(UINT)eSceneType::Max] = {};
	Scene* SceneManager::mPlayScene = nullptr; // ���� ȭ�鿡 ������ �ִ� ��
	eSceneType SceneManager::mType = eSceneType::Max;

	void SceneManager::Initialize()
	{
		//��� ������
		mScenes[(UINT)eSceneType::Logo] = new LogoScene();
		mScenes[(UINT)eSceneType::Logo]->Initialize();
		
		mScenes[(UINT)eSceneType::Title] = new TitleScene();
		mScenes[(UINT)eSceneType::Title]->Initialize();

		mScenes[(UINT)eSceneType::Play] = new PlayScene();
		mScenes[(UINT)eSceneType::Play]->Initialize();

		mScenes[(UINT)eSceneType::End] = new EndScene();
		mScenes[(UINT)eSceneType::End]->Initialize();

		ChangeSccene(eSceneType::Logo);
		//mPlayScene = mScenes[(UINT)eSceneType::Logo];
		//��ĳ����
		//�ٿ�ĳ����
	}
	void SceneManager::Tick()
	{
		//���� ��  Tick
		mPlayScene->Tick();

	}
	void SceneManager::Render(HDC hdc)
	{
		//���� �� Render
		mPlayScene->Render(hdc);
	}
	void SceneManager::DestroyGameObject()
	{
		k::object::Release();
	}
	void SceneManager::Release()
	{
		//���α׷� ����ɶ� �ѹ��� ȣ��
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
		if (mScenes[(UINT)type] == nullptr)
			return;

		mPlayScene->Exit();
		mPlayScene = mScenes[(UINT)type];
		

		mPlayScene->Enter();

	}
}