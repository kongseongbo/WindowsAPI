#include "kSceneManager.h"
#include "kLogoScene.h"

namespace k
{
	Scene* SceneManager::mScenes[(UINT)eSceneType::Max] ={};
	Scene* SceneManager::mPlayScene = nullptr;

	void SceneManager::Initialize()
	{
		//��� ������ �ʱ�ȭ
		mScenes[(UINT)eSceneType::Logo] = new LogoScene();
		mScenes[(UINT)eSceneType::Logo]->Initialize();

		mPlayScene = mScenes[(UINT)eSceneType::Logo];
	}
	void SceneManager::Tick()
	{
		//���� ������ update Tick
		mPlayScene->Tick();
	}
	void SceneManager::Render(HDC hdc)
	{
		//���� �� Render
		mPlayScene->Render(hdc);
	}
	void SceneManager::Reelease()
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
}