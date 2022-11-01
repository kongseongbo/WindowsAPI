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
		static Vector2 mResolution; // ȭ�� �ػ�
		static Vector2 mLookPosition; // �ٶ󺸴� ��ǥ
		static Vector2 mDistance; // �ػ� �߽���ǥ�� ���� ī�޶��� ������
		static  GameObject* mTarget; 
	};
}