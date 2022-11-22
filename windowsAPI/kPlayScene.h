#pragma once
#include "kScene.h"


namespace k
{
	class Image;
	class Mushroom;
	class Monster;
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
		Monster* mons[2];
		Mushroom* mushs[2];

		Image* mImage;
	};

}