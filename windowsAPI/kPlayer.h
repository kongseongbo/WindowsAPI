#pragma once
#include "kGameObject.h"

namespace k
{
	class Animator;
	class Image;
	class Player : public GameObject
	{
	public :
		Player();
		~Player();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

		void WalkComplete();

		void SetHp(int hp) { mHp = hp; }
		int GetHp() { return mHp; }

	private:
		float mCoff;
		float mSpeed;
		Image* mImage;
		Animator* mAnimator;
		Vector2 mMisiileDir;

		int mHp;
		int skillstack;
		float skillTime;
	};
}



