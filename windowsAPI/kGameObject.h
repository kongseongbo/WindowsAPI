#pragma once
#include "Common.h"
#include "kEntity.h"

namespace k
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Tick();
		virtual void Render();

		void SetPos(Vector2 pos) { mPos = pos; }
		Vector2 GetPos() { return mPos; }

		void SetScale(Vector2 scale) { mScale = scale; } // object 크기 조절
		Vector2 GetScale() { return mScale; }


	private:
		Vector2 mPos;
		Vector2 mScale;
	};
}


