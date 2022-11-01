#pragma once
#include "kGameObject.h"

namespace k
{
	class Obstacle;
	class ObstacleManager
	{
	public:
		ObstacleManager();
		virtual ~ObstacleManager();

		static ObstacleManager* GetObstacleManager() { return &obstaclemanager; } // �ٸ��������� ���� ObstacleManager�� ������ ����Ҽ� �ֵ��� static �Լ� ���
		void Tick();
		void Render(HDC hdc);

	private:
		std::vector<Obstacle*> obstacles;
		static ObstacleManager obstaclemanager; //static �Լ��� ��밡���ϵ��� ���� static������ ����

	};

}