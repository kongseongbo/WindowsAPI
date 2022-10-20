#pragma once
#include "Common.h"
#include "kEntity.h"

namespace k
{
	class GameObject; // ���漱��
	class Scene : public Entity
	{
	public :
		Scene();
		virtual ~Scene(); // �Ҹ��ڿ� virtual�� �Ⱥٿ��ָ� ã�ư������Ѵ�.

		virtual void Initialize(); 
		virtual void Tick(); // update
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* object);
		
	private:
		std::vector<GameObject*> mObject;


	};


}




