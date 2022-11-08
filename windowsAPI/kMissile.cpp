#include "kMissile.h"
#include "kTime.h"
#include "kCollider.h"
#include "kCamera.h"
#include "kAnimator.h"
#include "kResources.h"
#include "kImage.h"

namespace k
{
	Missile::Missile()
		: mSpeed(1.0f)
		, mAliveTime(5.0f)
	{
		SetPos({ 100.0f, 100.0f });
		SetScale({ 20.0f, 20.0f });

		Collider* col = new Collider();
		col->SetScale(Vector2(20.0f, 20.0f));

		AddComponent(col);
		if (mImage == nullptr)
		{
			mImage = Resources::Find<Image>(L"Player");
		}
		
		Animator* ani = new Animator();
		ani->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(120.0f, 130.0f)
			, Vector2(5.0f, -20.0f), 3, 0.1f);

		ani->Play(L"Idle", true);

		AddComponent(ani);

		mDir += Vector2(1.0f, 0.0f);
	}

	Missile::~Missile()
	{
	}

	void Missile::Tick()
	{
		GameObject::Tick();

		mAliveTime -= Time::DeltaTime();
		if (mAliveTime <= 0.0f)
		{
			this->Death();
		}

		float radian = DegreeToRadian(90.0f);
		float degree = RadianToDegree(2 * PI);

		float speed = 100.0f;

		Vector2 pos = GetPos();
		//pos.y -= 500.0f * Time::DeltaTime(); 
		//pos.y -= Time::DeltaTime();

		// 삼각함수를 이용한 회전
		//mDir = PI / 2.0f;
		//pos.x += speed * cosf(mDir) * Time::DeltaTime();
		//pos.y -= speed * sinf(mDir) * Time::DeltaTime();


		// 벡터를 이용한 회전
		pos.y += mDir.y * speed * Time::DeltaTime();
		pos.x += mDir.x * speed * Time::DeltaTime();

		SetPos(pos);
	}

	void Missile::Render(HDC hdc)
	{
		/*Vector2 pos = GetPos();
		Vector2 scale = GetScale();
		pos = Camera::CalculatePos(pos);

		Ellipse(hdc, pos.x - 10, pos.y - 10, pos.x + scale.x, pos.y + scale.y);*/

		GameObject::Render(hdc);
	}
	void Missile::OnCollisionEnter(Collider* other)
	{
		GameObject* gameObj = other->GetOwner();
		gameObj->Death();

		this->Death();
	}

	void Missile::OnCollisionStay(Collider* other)
	{
	}
	void Missile::OnCollisionExit(Collider* other)
	{
	}
}