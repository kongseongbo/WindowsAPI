#include "kAnimator.h"
#include "kGameObject.h"
#include "kImage.h"
#include "kCamera.h"
#include "kResources.h"

namespace k
{
	Animator::Animator()
		: Component(eComponentType::Aimator)
		, mPlayAnimaion(nullptr)
		, mbLoop(false)
	{
		//mImage = Resources::Load<Image>(L"Player", L"..\\Resources\\Image\\Player.bmp");
	}

	Animator::~Animator()
	{
		//std::map<std::wstring, Animation*> mAnimations;
		for (auto iter : mAnimations)
		{
			delete iter.second;
		}

		//std::map<std::wstring, Events*> mEvents;
		for (auto iter : mEvents)
		{
			delete iter.second;
		}
	}

	void Animator::Tick()
	{
		if (mPlayAnimaion != nullptr)
		{
			mPlayAnimaion->Tick();

			if (mbLoop && mPlayAnimaion->isComplete()) // PlayAnimaion 다시 재생
			{
				Animator::Events* events
					= FindEvents(mPlayAnimaion->GetName());
				if (events != nullptr)
					events->mCompleteEvent();

				mPlayAnimaion->Reset();
			}
		}
	}

	void Animator::Render(HDC hdc)
	{
		if (mPlayAnimaion != nullptr)
		{
			mPlayAnimaion->Render(hdc);
		}
	}

	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		std::map<std::wstring, Animation*>::iterator iter = mAnimations.find(name);
		if (iter == mAnimations.end())
			return nullptr;

		return iter->second;
	}

	void Animator::CreateAnimation(const std::wstring& name, Image* image
		, Vector2 leftTop, Vector2 size, Vector2 offset
		, UINT spriteLegth, float duration, bool bAffectedCamera)
	{
		Animation* animation = FindAnimation(name);
		if (animation != nullptr)
		{
			MessageBox(nullptr, L"중복 키 애니메이션 생성", L"애니메이션 생성 실패!", MB_OK);
			return;
		}

		animation = new Animation();
		animation->Create(image, leftTop, size, offset
			, spriteLegth, duration, bAffectedCamera);

		animation->SetName(name);
		animation->SetAnimator(this);

		mAnimations.insert(std::make_pair(name, animation));

		Events* events = new Events();
		mEvents.insert(std::make_pair(name, events));
	}

	void Animator::Play(const std::wstring& name, bool bLoop)
	{
		Animator::Events* events = FindEvents(name);
		if (events != nullptr)
			events->mStartEvent();

		Animation* prevAnimation = mPlayAnimaion;
		mPlayAnimaion = FindAnimation(name);
		mPlayAnimaion->Reset();
		mbLoop = bLoop;

		//새로운 애니메이션으로 바뀔때
		if (prevAnimation != mPlayAnimaion)
		{
			if (events != nullptr)
				events->mEndEvent();
		}
	}
	Animator::Events* Animator::FindEvents(const std::wstring key)
	{
		std::map<std::wstring, Events*>::iterator iter = mEvents.find(key);
		if (iter == mEvents.end())
		{
			return nullptr;
		}
		return iter->second;
	}
	std::function<void()>& Animator::GetStartEvent(const std::wstring key)
	{
		Events* events = FindEvents(key);

		return events->mStartEvent.mEvent;
	}
	std::function<void()>& Animator::GetCompleteEvent(const std::wstring key)
	{
		Events* events = FindEvents(key);

		return events->mCompleteEvent.mEvent;
	}
	std::function<void()>& Animator::GetEndEvent(const std::wstring key)
	{
		Events* events = FindEvents(key);

		return events->mEndEvent.mEvent;
	}
}