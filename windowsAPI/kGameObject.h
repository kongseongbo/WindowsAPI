#pragma once
#include "Common.h"
#include "kEntity.h"
#include "kComponent.h"

namespace k
{
	class Collider;
	class GameObject : public Entity
	{
	public:
		GameObject();
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);


		void SetPos(Vector2 pos) { mPos = pos; }
		Vector2 GetPos() { return mPos; }
		void SetScale(Vector2 scale) { mScale = scale; } // object 크기 조절
		Vector2 GetScale() { return mScale; }

		void Death() { mDead = true; }
		bool IsDeath() { return mDead; }

		void AddComponent(Component* component);

		template<typename T>
		__forceinline T* GetComponent()
		{
			T* component;
			for (Component* c : mComponents)
			{
				component = dynamic_cast<T*>(c);
				if (component != nullptr)
					return component;
			}
			return nullptr;
		}

	private:
		std::vector<Component*> mComponents;
		Vector2 mPos;
		Vector2 mScale;
		bool mDead;
	};
}


//상속구조
//작업속도가 빠르다


//컴포넌트구조
//작업속도가 느리다
//SceneManager
//Scene