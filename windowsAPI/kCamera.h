#pragma once
#include "Common.h"

namespace k
{
	class GameObject;
	class Camera
	{
	public :
		static void Initialize();
		static void Tick();

		static Vector2 CalculatePos(Vector2 pos) { return pos - mDistance; }
		static void SetTarget(GameObject* GameObj) { mTarget = GameObj; }

	private:
		Camera() = default;
		~Camera() = default;

	private:
		static Vector2 mResolution; // 화면 해상도
		static Vector2 mLookPosition; // 바라보는 좌표
		static Vector2 mDistance; // 해상도 중심좌표와 현제 카메라의 간격차
		static  GameObject* mTarget; 
	};
}