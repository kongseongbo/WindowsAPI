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
		//cpu ���� ������(1�ʴ� ���) 1�� 12000�� �����ϴ� cpu
		static LARGE_INTEGER mCpuFrequency; //cpu ���� ������
		static LARGE_INTEGER mPrevFrequency;
		static LARGE_INTEGER mCurFrequency;
		
		//�������� ���� ���� �� �ɸ��ð�
		static float mDeltaTime;
		static float mTime;

	};
}


