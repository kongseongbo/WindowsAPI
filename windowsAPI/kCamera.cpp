#include "kCamera.h"
#include "kApplication.h"
#include "kGameObject.h"

namespace k
{
	Vector2 Camera::mResolution = Vector2::Zero; // 화면 해상도
	Vector2 Camera::mLookPosition = Vector2::Zero; // 바라보는 좌표
	Vector2 Camera::mDistance = Vector2::Zero; // 해상도 중심좌표와 현제 카메라의 간격차
	GameObject* Camera::mTarget = nullptr;

	void Camera::Initialize()
	{
		WindowData data = Application::GetInstance().GetWindowData();
		mResolution = Vector2(data.width, data.height);
		mLookPosition = (mResolution / 2.0f);

	}
	void Camera::Tick()
	{
		if (mTarget != nullptr)
			mLookPosition = mTarget->GetPos();
		
		mDistance = mLookPosition - (mResolution / 2.0f);
	}
}