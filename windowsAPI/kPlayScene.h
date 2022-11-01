#pragma once
#include "kScene.h"


namespace k
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Tick() override;
		void Render(HDC hdc) override;

		virtual void Enter(); // 씬이 변경될때마다
		virtual void Exit();

	private:

	};

}