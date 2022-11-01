#pragma once
#include "kScene.h"

namespace k
{
	class EndScene : public Scene
	{
	public:
		EndScene();
		~EndScene();

		void Initialize() override;
		void Tick() override;
		void Render(HDC hdc) override;

		virtual void Enter(); // ���� ����ɶ�����
		virtual void Exit();

	private:

	};
}