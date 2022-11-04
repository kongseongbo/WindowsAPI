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

		Animator();
		~Animator();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		Animation* FindAnimation(const std::wstring& name);
		void CreateAnimation(const std::wstring& name, Image* image
			, Vector2 leftTop, Vector2 size, Vector2 offset
			, float columnLength, UINT spriteLegth, float duration, bool bAffectedCamera = true);
		void Play(std::wstring& name, bool bLoop = false);

	public:
		Event mStartEvent;
		Event mCompleteEvent;
		Event mEndEvent;

	private:
		std::map<const std::wstring&, Animation*> mAnimations;
		Animation* mPlayAnimaion;
		bool mLoop;
	};
}