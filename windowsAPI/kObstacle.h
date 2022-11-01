#pragma once
#include "kGameObject.h"

namespace k
{
	class Obstacle : public GameObject
	{
	public :
		Obstacle();
		~Obstacle();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		float mSpeed;

	};

}