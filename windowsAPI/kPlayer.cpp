#include "kPlayer.h"
#include "kTime.h"
#include "kInput.h"
#include "kMissile.h"
#include "kScene.h"
#include "kSceneManager.h"
#include "kImage.h"
#include "kResources.h"
#include "kAnimator.h"
#include "kCollider.h"
#include "kCamera.h"
#include "kBackPack.h"

namespace k
{
	Player::Player()
		: mSpeed(1.0f)
	{
		SetName(L"Player");
		SetPos({ 900.0f, 700.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Player", L"..\\Resources\\Image\\Player.bmp");
		}

		AddComponent(new Animator());
		AddComponent(new Collider());

		//Camera::SetTarget(this);
	}

	Player::~Player()
	{

	}

	void Player::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();
		if (KEY_PREESE(eKeyCode::W))
		{
			pos.y -= 120.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(eKeyCode::S))
		{
			pos.y += 120.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(eKeyCode::A))
		{
			pos.x -= 120.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(eKeyCode::D))
		{
			pos.x += 120.0f * Time::DeltaTime();
		}

		if (KEY_DOWN(eKeyCode::SPACE))
		{
			Missile* missile = new Missile();

			Scene* playScene = SceneManager::GetPlayScene();
			playScene->AddGameObject(missile, eColliderLayer::Player_Projecttile);

			Vector2 playerPos = GetPos();
			Vector2 playerScale = GetScale() / 2.0f;
			Vector2 missileScale = missile->GetScale();

			missile->SetPos((playerPos + playerScale) - (missileScale / 2.0f));
		}
		if (KEY_DOWN(eKeyCode::I))
		{
			BackPack* backPack = new BackPack();
			Scene* playScene = SceneManager::GetPlayScene();
			playScene->AddGameObject(backPack, eColliderLayer::Player_Projecttile);
		}

		SetPos(pos);
	}

	void Player::Render(HDC hdc)
	{
		//HBRUSH blueBrush = CreateSolidBrush(RGB(153, 204, 255));
		//Brush brush(hdc, blueBrush);

		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//Pen pen(hdc, redPen);

		Vector2 pos = GetPos();
		Vector2 scale = GetScale();

		/*BitBlt(hdc , pos.x, pos.y
			, mImage->GetWidth(), mImage->GetHeight()
			, mImage->GetDC(), 0, 0, SRCCOPY);*/

		Vector2 finalPos;
		finalPos.x = (pos.x - mImage->GetWidth() * (scale.x / 2.0f));
		finalPos.y = (pos.y - mImage->GetHeight() * (scale.y / 2.0f));

		//캐릭터 크기 확대
		Vector2 rect;
		rect.x = mImage->GetWidth() * scale.x;
		rect.y = mImage->GetHeight() * scale.y;

		finalPos = Camera::CalculatePos(finalPos);

		//크기 변경 가능 pos.x, pos.y, mImage->GetWidth() * ?, mImage->GetHeight() * ?
		TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y
			, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 0, 255));

		GameObject::Render(hdc);
	}

	void Player::OnCollisionEnter(Collider* other)
	{

	}

	void Player::OnCollisionStay(Collider* other)
	{

	}

	void Player::OnCollisionExit(Collider* other)
	{

	}
}



/*Vector2 finalPos;
finalPos.x = (pos.x - mImage->GetWidth() * (scale.x / 2.0f));
finalPos.y = (pos.y - mImage->GetHeight() * (scale.y / 2.0f));

TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight()
	, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
	, RGB(255, 0, 255));*/

	//크기 변경이 안된다.
	/*BitBlt(hdc, pos.x, pos.y
		, mImage->GetWidth(), mImage->GetHeight()
		, mImage->GetDC(), 0, 0, SRCCOPY);*/