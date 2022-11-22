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
		// 힘과 마찰력을 이용한 이동
		float mMass; // 질량
		float mFriction; // 마찰력
		//float mMoveFriction;
		Vector2 mForce;
		Vector2 mVelocity; // 속도
		Vector2 mAccelation; // 가속도

		// 중력 이용한 점프
		Vector2 mGravity;
		bool mbGround;
		Vector2 mLimitVelocity;
	};
}