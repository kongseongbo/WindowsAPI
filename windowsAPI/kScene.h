#pragma once
#include "Common.h"
#include "kEntity.h"

namespace k
{
	class GameObject;
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);

		virtual void Enter(); // 씬이 변경될때마다
		virtual void Exit();

		void AddGameObject(GameObject* object, eColliderLayer type);

		std::vector<GameObject*>& GetGameObjects(eColliderLayer type) { return mObjects[(UINT)type]; }

	private:
		std::vector<std::vector<GameObject*>> mObjects;
	};
}
