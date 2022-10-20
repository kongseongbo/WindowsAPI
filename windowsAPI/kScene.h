#pragma once
#include "Common.h"
#include "kEntity.h"

namespace k
{
	class GameObject; // 전방선언
	class Scene : public Entity
	{
	public :
		Scene();
		virtual ~Scene(); // 소멸자에 virtual을 안붙여주면 찾아가지못한다.

		virtual void Initialize(); 
		virtual void Tick(); // update
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* object);
		
	private:
		std::vector<GameObject*> mObject;


	};


}




