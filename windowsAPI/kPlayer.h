#pragma once
#include "kGameObject.h"

namespace k
{
	class Player : public GameObject
	{
	public :
		Player();
		~Player();

		void Tick() override;
		void Render(HDC hdc) override;

	private:

	};
}



