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

		static ObstacleManager* GetObstacleManager() { return &obstaclemanager; } // 다른곳에서도 쉽게 ObstacleManager를 가져다 사용할수 있도록 static 함수 사용
		void Tick();
		void Render(HDC hdc);

	private:
		std::vector<Obstacle*> obstacles;
		static ObstacleManager obstaclemanager; //static 함수에 사용가능하도록 같은 static변수로 선언

	};

}