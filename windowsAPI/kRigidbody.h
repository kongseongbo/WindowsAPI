#pragma once
#include "kComponent.h"

namespace k
{
	class Rigidbody : public Component
	{
	public:
		Rigidbody();
		~Rigidbody();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void AddForce(Vector2 force);
		void SetMass(float mass) { mass = mMass; }
		void SetGround(bool isGround) { mbGround = isGround; }
		Vector2 GetVelocity() { return mVelocity; }
		void SetVelocity(Vector2 velocity) { mVelocity = velocity; }

	private:
		// ���� �������� �̿��� �̵�
		float mMass; // ����
		float mFriction; // ������
		//float mMoveFriction;
		Vector2 mForce;
		Vector2 mVelocity; // �ӵ�
		Vector2 mAccelation; // ���ӵ�

		// �߷� �̿��� ����
		Vector2 mGravity;
		bool mbGround;
		Vector2 mLimitVelocity;
	};
}