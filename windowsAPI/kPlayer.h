#pragma once
#include "kGameObject.h"

namespace k
{
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

	private:
		float mSpeed;
		Image* mImage;
	};
}



