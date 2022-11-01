#pragma once
#include "kEntity.h"
#include "Common.h"

namespace k
{
	class GameObject; // 컴포넌스가 게임오브젝트를 알고있기 때문에 전방선언
	class Component : public Entity
	{
	public:
		friend class GameObject;

		Component(eComponentType mType);
		Component() = delete; // 기본생성자 못만들게 delete
		virtual ~Component();

		virtual void Tick() = 0;
		virtual void Render(HDC hdc);

		GameObject* GetOwner() { return mOwner; }
		
	private:
		const eComponentType mType;
		GameObject* mOwner;
	};
}