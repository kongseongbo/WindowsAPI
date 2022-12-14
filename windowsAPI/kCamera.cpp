#include "kCamera.h"
#include "kApplication.h"
#include "kGameObject.h"
#include "kInput.h"
#include "kTime.h"
#include "kImage.h"

namespace k
{
	Vector2 Camera::mResolution = Vector2::Zero; // 화면 해상도
	Vector2 Camera::mLookPosition = Vector2::Zero; // 바라보는 좌표
	Vector2 Camera::mDistance = Vector2::Zero; // 해상도 중심좌표와 현제 카메라의 간격차
	GameObject* Camera::mTarget = nullptr;

	eCameraEffect Camera::mEffect = eCameraEffect::None;
	Image* Camera::mCutton = nullptr; // 검정색 이미지
	float Camera::mAlphaTime = 0.0f;
	float Camera::mCuttonAlpha = 0.0f; // 0 ~ 255
	float Camera::mEndTime = 5.0f;

	void Camera::Initialize()
	{
		WindowData data = Application::GetInstance().GetWindowData();
		mResolution = Vector2(data.width, data.height);
		mLookPosition = (mResolution / 2.0f);

		mCutton = Image::Create(L"CameraCutton", 1600, 900);
	}
	void Camera::Tick()
	{
		if (mAlphaTime <= mEndTime)
		{
			mAlphaTime += Time::DeltaTime();
			float ratio = (mAlphaTime / mEndTime);

			if (eCameraEffect::FadeIn == mEffect)
			{
				mCuttonAlpha = 1.0f - ratio;
			}
			else if (eCameraEffect::FadeOut == mEffect)
			{
				mCuttonAlpha = ratio;
			}
		}

		if (KEY_PREESE(eKeyCode::UP))
		{
			mLookPosition.y -= 600.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(eKeyCode::DOWN))
		{
			mLookPosition.y += 600.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(eKeyCode::LEFT))
		{
			mLookPosition.x -= 600.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(eKeyCode::RIGHT))
		{
			mLookPosition.x += 600.0f * Time::DeltaTime();
		}

		if (mTarget != nullptr)
			mLookPosition = mTarget->GetPos();

		mDistance = mLookPosition - (mResolution / 2.0f);
	}
	void Camera::Render(HDC hdc)
	{
		if (mCuttonAlpha <= 0.0f)
			return;

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = 0;
		func.SourceConstantAlpha = (BYTE)(255.0f * mCuttonAlpha); //투명도 조절

		AlphaBlend(hdc, 0, 0
			, mCutton->GetWidth(), mCutton->GetHeight()
			, mCutton->GetDC(), 0, 0
			, mCutton->GetWidth(), mCutton->GetHeight()
			, func);
	}
}