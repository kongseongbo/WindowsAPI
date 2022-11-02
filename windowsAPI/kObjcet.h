#pragma once
#include "kScene.h"
#include "kGameObject.h"
#include "kSceneManager.h"


namespace k
{
	namespace object
	{
		template <typename T>
		static __forceinline T* Instantiate(eColliderLayer type)
		{
			T* gameObjcet = new T();
			Scene* scene = SceneManager::GetPlayScene();
			scene->AddGameObject(dynamic_cast<GameObject*>(gameObjcet), type);

			return gameObjcet;
		}

		template <typename T>
		static __forceinline T* Instantiate(Vector2 position, eColliderLayer type)
		{
			T* gameObjcet = new T(position);
			Scene* scene = SceneManager::GetPlayScene();
			scene->AddGameObject(dynamic_cast<GameObject*>(gameObjcet), type);

			return gameObjcet;
		}



		static __forceinline void Release()
		{
			// �ش� ���� �ִ� ��� object�� �����;��Ѵ�.
			Scene* scene = SceneManager::GetPlayScene();
			
		}
	}
}