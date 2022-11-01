#include "kObstacleManager.h"
#include "Time.h"
#include "kSceneManager.h"
#include "kScene.h"
#include "kObstacle.h"
#include "kCollider.h"

namespace k
{
	ObstacleManager ObstacleManager::obstaclemanager;

	ObstacleManager::ObstacleManager()
	{
		srand((unsigned int)time(NULL)); // 난수 생성을 위해 필요
	}
	ObstacleManager::~ObstacleManager()
	{
	}
	void ObstacleManager::Tick()
	{
		for (GameObject* object : obstacles) // 범위 기반 for문
		{
			object->Tick();
		}


		Obstacle* obstacle = new Obstacle;
		float x = rand() % 1921;
		obstacle->SetPos({ x, -1 });

		Scene* scene = SceneManager::GetPlayScene();
		//scene->AddGameObject(obstacle. eColliderLayer::Default);
		obstacles.push_back(obstacle);
	}
	void ObstacleManager::Render(HDC hdc)
	{
		for (GameObject* object : obstacles)
		{
			int a = rand() % 255;
			int b = rand() % 255;
			int c = rand() % 255;

			HBRUSH brush = CreateSolidBrush(RGB(a, b, c));
			Brush OldBrush(hdc, brush);

			HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
			Pen OldPen(hdc, pen);
		
			object->Render(hdc);
		}
	}
}