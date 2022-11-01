#include "kObstacle.h"
#include "kTime.h"
#include "kInput.h"
#include "kPlayer.h"


namespace k
{
	Obstacle::Obstacle()
		:mSpeed(1.0f)
	{
		SetPos({ 0.0f,0.0f });
		SetScale({ 30.0f,30.0f });
	}

	Obstacle::~Obstacle()
	{
	}

	void Obstacle::Tick()
	{
		Vector2 pos = GetPos();

		pos.y += 300.0f * Time::DeltaTime();

		SetPos(pos);
	}

	void Obstacle::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();
		Rectangle(hdc, pos.x, pos.y, pos.x + scale.x, pos.y + scale.y);

	}

}


