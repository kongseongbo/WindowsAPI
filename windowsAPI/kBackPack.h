#pragma once
#include "kGameObject.h"


namespace k
{
	class Image;
	class BackPack : public GameObject
	{
	public:
		BackPack();
		~BackPack();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

	private:
		float mSpeed;
		Image* mImage;
		//int alpha; // 투명도 조절 0 ~ 255
	};

}