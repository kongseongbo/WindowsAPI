#include "kMushroom.h"

#include "kTime.h"
#include "kSceneManager.h"
#include "kInput.h"
#include "kMissile.h"
#include "kScene.h"
#include "kImage.h"
#include "kResources.h"
#include "kAnimator.h"
#include "kCollider.h"
#include "kCamera.h"

namespace k
{
	Mushroom::Mushroom()
		: mTime(0.0f)
	{
		SetName(L"Mushmom");
		SetPos({ 1920 / 3, 1080 / 1.73 });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Mushmom", L"..\\Resources\\Animations\\Mushmom\\MushIdle\\stand.bmp");
		}

		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Mushmom\\MushIdle"
			, L"MushIdle");
		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Mushmom\\MushMoveLeft"
			, L"MushMoveLeft");
		/*mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Mushmom\\Jump"
			, L"MoveUp");*/
		/*mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Mushmom\\MoveRight"
			, L"MoveRight");*/

		mAnimator->Play(L"MushIdle", true);
		//mAnimator->GetCompleteEvent(L"MoveRight") = std::bind(&Player::WalkComplete, this);


		AddComponent(mAnimator);
		AddComponent(new Collider());
	}

	Mushroom::~Mushroom()
	{

	}

	void Mushroom::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);

		//mTime += Time::DeltaTime();

		//if (mTime > 5.0f)
		//{
		//	pos.x -= 30;
		//	SetPos(pos);
		//	mTime = 0.0f;
		//}
	}

	void Mushroom::Render(HDC hdc)
	{

		GameObject::Render(hdc);
	}
	void Mushroom::OnCollisionEnter(Collider* other)
	{
	}
	void Mushroom::OnCollisionStay(Collider* other)
	{
	}
	void Mushroom::OnCollisionExit(Collider* other)
	{
	}
}