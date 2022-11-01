#pragma once
#include "Common.h"

namespace k
{
	class Time
	{
	public :
		static void Initialize();
		static void Tick();
		static void Render(HDC hdc);
		
		static float DeltaTime() { return mDeltaTime; }

	private:
		//cpu 고유 진동수(1초당 몇번) 1초 12000번 진동하는 cpu
		static LARGE_INTEGER mCpuFrequency; //cpu 고유 진동수
		static LARGE_INTEGER mPrevFrequency;
		static LARGE_INTEGER mCurFrequency;
		
		//한프레임 도는 동안 총 걸린시간
		static float mDeltaTime;
		static float mTime;

	};
}


