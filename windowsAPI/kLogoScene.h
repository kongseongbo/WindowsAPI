#pragma once
#include "kScene.h"

namespace k
{
	class LogoScene : public Scene
	{
	public:
		LogoScene();
		~LogoScene();

		void Initialize() override;
		void Tick() override;
		void Render(HDC hdc) override;

	};

}


