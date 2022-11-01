#pragma once
#include "kEntity.h"
#include "Common.h"

namespace k
{
	class GameObject; // �����ͽ��� ���ӿ�����Ʈ�� �˰��ֱ� ������ ���漱��
	class Component : public Entity
	{
	public:
		friend class GameObject;

		Component(eComponentType mType);
		Component() = delete; // �⺻������ ������� delete
		virtual ~Component();

		virtual void Tick() = 0;
		virtual void Render(HDC hdc);

		GameObject* GetOwner() { return mOwner; }
		
	private:
		const eComponentType mType;
		GameObject* mOwner;
	};
}