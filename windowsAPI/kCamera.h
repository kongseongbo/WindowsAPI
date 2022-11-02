#pragma once
#include "Common.h"

namespace k
{
	class Image;
	class GameObject;
	class Camera
	{
	public:
		static void Initialize();
		static void Tick();
		static void Render(HDC hdc);
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

		static eCameraEffect mEffect;
		static Image* mCutton; // ������ �̹���
		static float mAlphaTime;

		static float mCuttonAlpha; // 0 ~ 255
		static float mEndTime;
	};
}