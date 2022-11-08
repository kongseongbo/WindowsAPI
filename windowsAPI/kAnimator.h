#pragma once
#include "kComponent.h"
#include "kAnimation.h"

namespace k
{
	class Image;
	class Animator : public Component
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}

			void operator()() // Evnet를 함수처럼 사용하기위한 operator
			{
				if (mEvent)
					mEvent();
			}

			std::function<void()> mEvent;
		};
		struct Events
		{
			Event mStartEvent; //애니메이션 시작할때 Event
			Event mCompleteEvent;//애니메이션 끝났을때 Event
			Event mEndEvent;// 새로운  애니메이션으로 바뀔때 Event
		};

		Animator();
		~Animator();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		Animation* FindAnimation(const std::wstring& name);
		//
		void CreateAnimation(const std::wstring& name, Image* image
			, Vector2 leftTop, Vector2 size, Vector2 offset
			, UINT spriteLegth, float duration, bool bAffectedCamera = true);
		void Play(const std::wstring& name, bool bLoop = false);

	public:
		Events* FindEvents(const std::wstring key);
		std::function<void()>& GetStartEvent(const std::wstring key);
		std::function<void()>& GetCompleteEvent(const std::wstring key);
		std::function<void()>& GetEndEvent(const std::wstring key);

	private:
		std::map< std::wstring, Animation*> mAnimations;
		std::map<std::wstring, Events*> mEvents;

		Animation* mPlayAnimaion;
		bool mbLoop;
	};
}