#include "kRigidbody.h"
#include "kTime.h"
#include "kGameObject.h"
#include "kCollider.h"

namespace k
{
	Rigidbody::Rigidbody()
		: Component(eComponentType::Rigidbody)
		, mMass(1.0f)
		, mFriction(100.0f)
	{
		mLimitVelocity.x = 200.0f;
		mLimitVelocity.y = 1000.0f;
		mbGround = false;
		mGravity = Vector2(0.0f, 800.0f);
	}

	Rigidbody::~Rigidbody()
	{
	}
	void Rigidbody::Tick()
	{
		//�̵�
		// F = M X A
		// A = F / M

		mAccelation = mForce / mMass;

		//�ӵ��� ���ӵ��� �����ش�.
		mVelocity += mAccelation * Time::DeltaTime();

		if (mbGround)
		{
			// ������ ���� ��
			Vector2 gravity = mGravity;
			gravity.Normalize();
			float dot = k::math::Dot(mVelocity, gravity);
			mVelocity -= gravity * dot;
		}
		else
		{
			// ���߿� ���� ��
			mVelocity += mGravity * Time::DeltaTime();
		}
		
		// �ִ� �ӵ� ����
		Vector2 gravity = mGravity;
		gravity.Normalize();
		float dot = k::math::Dot(mVelocity, gravity);
		gravity = gravity * dot;

		Vector2 sideVelocity = mVelocity - gravity;
		if (mLimitVelocity.y < gravity.Length())
		{
			gravity.Normalize();
			gravity *= mLimitVelocity.y;
		}

		if (mLimitVelocity.x < sideVelocity.Length())
		{
			sideVelocity.Normalize();
			sideVelocity *= mLimitVelocity.x;
		}
		mVelocity = gravity + sideVelocity;

		//������ ���� ( ����� ���� ����, �ӵ��� 0 �� �ƴ� ��)
		if (!(mVelocity == Vector2::Zero))
		{
			// �ӵ��� �ݴ� �������� �������� ����
			Vector2 friction = -mVelocity;
			friction = friction.Normalize() * mFriction * mMass * Time::DeltaTime();

			// ���������� ���� �ӵ� ���ҷ��� ���� �ӵ����� �� ū ���
			if (mVelocity.Length() < friction.Length())
			{
				// �ӵ��� 0 �� �����.
				mVelocity = Vector2(0.f, 0.f);
			}
			else
			{
				// �ӵ����� ���������� ���� �ݴ�������� �ӵ��� �����Ѵ�.
				mVelocity += friction;
			}
		}

		// �ӵ��� �°� ��ü�� �̵���Ų��.
		Vector2 pos = GetOwner()->GetPos();
		pos = pos + mVelocity * Time::DeltaTime();
		GetOwner()->SetPos(pos);

		//Collider* col = GetOwner()->GetComponent<Collider>();
		//col->SetPos(pos);


		mForce.clear();

	}
	void Rigidbody::Render(HDC hdc)
	{
	}
	void Rigidbody::AddForce(Vector2 force)
	{
		mForce += force;
	}
}