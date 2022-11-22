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
#include "kRigidbody.h"
#include "kUIManager.h"

namespace k
{
	Player::Player()
		: mSpeed(1.0f)
		, mHp(100)
		, skillstack(0)
		, skillTime(0.0f)
	{
		SetName(L"Player");
		SetPos({ 1920 / 2, 1080 / 1.73 });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Player", L"..\\Resources\\Animations\\Player\\Idle\\stand.bmp");
		}
		

		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Player\\Up"
			, L"MoveUp");

		//왼쪽
		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Player\\Idle"
			, L"Idle");
		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Player\\MoveLeft"
			, L"MoveLeft");
		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Player\\Smash1"
			, L"Smash1");
		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Player\\Smash2"
			, L"Smash2");
		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Player\\Smash3"
			, L"Smash3");
		

		//오른쪽
		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Player\\RIdle"
			, L"RIdle");
		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Player\\MoveRight"
			, L"MoveRight");
		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Player\\RSmash1"
			, L"RSmash1");
		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Player\\RSmash2"
			, L"RSmash2");
		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Player\\RSmash3"
			, L"RSmash3");

		// 한 이미지에 전부 들어있을때
		//mAnimator->CreateAnimation(L"Idle", mImage
		//	, Vector2(0.0f, 0.0f), Vector2(120.0f, 130.0f)
		//	, Vector2(5.0f, -20.0f), 3, 0.1f);
		//mAnimator->CreateAnimation(L"MoveDown", mImage
		//	, Vector2(0.0f, 520.0f), Vector2(120.0f, 130.0f)
		//	, Vector2(5.0f, -20.0f), 10, 0.1f);
		//mAnimator->CreateAnimation(L"MoveLeft", mImage
		//	, Vector2(0.0f, 650.0f), Vector2(120.0f, 130.0f)
		//	, Vector2(5.0f, -20.0f), 10, 0.1f);
		//mAnimator->CreateAnimation(L"MoveUp", mImage
		//	, Vector2(0.0f, 780.0f), Vector2(120.0f, 130.0f)
		//	, Vector2(5.0f, -20.0f), 10, 0.1f);
		//mAnimator->CreateAnimation(L"MoveRight", mImage
		//	, Vector2(0.0f, 910.0f), Vector2(120.0f, 130.0f)
		//	, Vector2(5.0f, -20.0f), 10, 0.1f);

		mAnimator->Play(L"Idle", true);
		//mAnimator->FindEvents(L"MoveRight")->mCompleteEvent = std::bind(&Player::WalkComplete, this);
		//mAnimator->GetCompleteEvent(L"MoveRight") = std::bind(&Player::WalkComplete, this);

		//mAnimator->Play(L"MoveRight", true);
		//mAnimator->mCompleteEvent = std::bind(&Player::WalkComplete, this);
		
		AddComponent(mAnimator);

		//아래
		Collider* coliider = new Collider();
		AddComponent(coliider);
		coliider->SetOffset(Vector2(0.0f, 103.0f));
		coliider->SetScale(Vector2(10.0f, 10.0f));

		//위
		Collider* coliider2 = new Collider();
		AddComponent(coliider2);
		coliider2->SetOffset(Vector2(0.0f, 30.0f));
		coliider2->SetScale(Vector2(10.0f, 10.0f));
		
		//오른쪽
		Collider* coliider3 = new Collider();
		AddComponent(coliider3);
		coliider3->SetOffset(Vector2(20.0f, 50.0f));
		coliider3->SetScale(Vector2(10.0f, 10.0f));

		//왼쪽
		Collider* coliider4 = new Collider();
		AddComponent(coliider4);
		coliider4->SetOffset(Vector2(-30.0f, 50.0f));
		coliider4->SetScale(Vector2(10.0f, 10.0f));

		AddComponent<Rigidbody>();

		mCoff = 0.1f;
		mMisiileDir = Vector2::One;
		Camera::SetTarget(this);
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
			//missile->mDir.y = -1.0f;
			
			//GetComponent<Rigidbody>()->AddForce(Vector2(0.0f, -200.0f));
		}
		if (KEY_PREESE(eKeyCode::S))
		{
			//pos.y += 120.0f * Time::DeltaTime();
			//GetComponent<Rigidbody>()->AddForce(Vector2(0.0f, 200.0f));
		}
		if (KEY_PREESE(eKeyCode::A))
		{
			pos.x -= 120.0f * Time::DeltaTime();
			
			//GetComponent<Rigidbody>()->AddForce(Vector2(-200.0f, 0.0f));
		}
		if (KEY_PREESE(eKeyCode::D))
		{
			pos.x += 120.0f * Time::DeltaTime();

			//GetComponent<Rigidbody>()->AddForce(Vector2(200.0f, 0.0f));
		}
		SetPos(pos);

		if (KEY_DOWN(eKeyCode::SPACE))
		{
			Rigidbody* rigidbody = GetComponent<Rigidbody>();
			Vector2 velocity = rigidbody->GetVelocity();
			velocity.y = -400.0f;
			rigidbody->SetVelocity(velocity);

			rigidbody->SetGround(false);

			UIManager::Pop(eUIType::OPTION);
		}
		
		if (KEY_DOWN(eKeyCode::W))
		{
			mAnimator->Play(L"MoveUp", true);
		}
		if (KEY_DOWN(eKeyCode::S))
		{
			//mAnimator->Play(L"MoveDown", true);
		}
		if (KEY_DOWN(eKeyCode::A))
		{
			mAnimator->Play(L"MoveLeft", true);
		}
		if (KEY_DOWN(eKeyCode::D))
		{
			mAnimator->Play(L"MoveRight", true);
		}

		if (KEY_UP(eKeyCode::W))
		{
			mAnimator->Play(L"Idle", true);
		}
		if (KEY_UP(eKeyCode::S))
		{
			mAnimator->Play(L"Idle", true);
		}
		if (KEY_UP(eKeyCode::A))
		{
			mAnimator->Play(L"Idle", true);
		}
		if (KEY_UP(eKeyCode::D))
		{
			mAnimator->Play(L"Idle", true);
		}

		if (KEY_PREESE(eKeyCode::LBTN))
		{
			if (true)
			{
				Missile* missile = new Missile();

				Scene* playScene = SceneManager::GetPlayScene();
				playScene->AddGameObject(missile, eColliderLayer::Player_Projecttile);

				Vector2 playerPos = GetPos();
				Vector2 playerScale = GetScale() / 2.0f;

				missile->SetPos(playerPos);
				missile->mDestPos = Vector2::One; // = Input::GetMousePos();
				//missile->mDir = missile->mDestPos - pos;

				mMisiileDir = math::Rotate(mMisiileDir, 5.0f);
				missile->mDir = mMisiileDir;
			}
		}
		//Inventory
		if (KEY_DOWN(eKeyCode::I))
		{
			BackPack* backPack = new BackPack();
			Scene* playScene = SceneManager::GetPlayScene();
			playScene->AddGameObject(backPack, eColliderLayer::Player_Projecttile);
		}
		//Skill Smash 
		
		if (KEY_DOWN(eKeyCode::LSHIFT))
		{
			if (skillstack == 0)
			{
				skillstack++;
				mAnimator->Play(L"Smash1", false);
				
			}
			else if (skillstack == 1)
			{
				skillstack++;
				skillTime = 0.0f;
				mAnimator->Play(L"Smash2", false);
			}
			else if (skillstack == 2)
			{
				skillstack = 0;
				mAnimator->Play(L"Smash3", false);
			}
		}

		if (skillstack > 0)
		{
			skillTime += Time::DeltaTime();

			if (skillTime > 5.0f)
			{
				skillTime = 0.0f;
				skillstack = 0;
			}
		}
	}

	void Player::Render(HDC hdc)
	{
		//HBRUSH blueBrush = CreateSolidBrush(RGB(153, 204, 255));
		//Brush brush(hdc, blueBrush);

		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//Pen pen(hdc, redPen);

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
	void Player::WalkComplete()
	{
		Missile* missile = new Missile();

		Scene* playScene = SceneManager::GetPlayScene();
		playScene->AddGameObject(missile, eColliderLayer::Player_Projecttile);

		Vector2 playerPos = GetPos();
		Vector2 playerScale = GetScale() / 2.0f;
		Vector2 missileScale = missile->GetScale();

		missile->SetPos((playerPos + playerScale) - (missileScale / 2.0f));
	}
}
