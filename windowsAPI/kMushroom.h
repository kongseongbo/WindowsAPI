#pragma once
#include "kGameObject.h"

namespace k
{
	class Animator;
	class Image;
	class Mushroom : public GameObject
	{
	public:
		Mushroom();
		Mushroom(Vector2 position);
		~Mushroom();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;


	private:
		Image* mImage;
		float mTime;
		Animator* mAnimator;
	};
}
