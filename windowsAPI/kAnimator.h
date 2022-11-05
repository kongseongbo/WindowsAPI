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

			void operator()() // Evnet�� �Լ�ó�� ����ϱ����� operator
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
		//
		void CreateAnimation(const std::wstring& name, Image* image
			, Vector2 leftTop, Vector2 size, Vector2 offset
			, UINT spriteLegth, float duration, bool bAffectedCamera = true);
		void Play(const std::wstring& name, bool bLoop = false);

	public:
		Event mStartEvent; //�ִϸ��̼� �����Ҷ� Event
		Event mCompleteEvent; //�ִϸ��̼� �������� Event
		Event mEndEvent; // ���ο�  �ִϸ��̼����� �ٲ� Event

	private:
		std::map< std::wstring, Animation*> mAnimations;
		Animation* mPlayAnimaion;
		bool mbLoop;
	};
}