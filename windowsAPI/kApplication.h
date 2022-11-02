#pragma once
#include "Common.h"

namespace k
{
	// 메인 프로그램이 될 녀석
	class Application
	{
	public:
		static Application& GetInstance() // 싱글턴패턴 동적할당으로 만든 싱글턴패턴은 소멸자가 호출되지 않는다.
		{
			static Application mInstance;
			return mInstance;
		}

		void Initialize(WindowData data);
		void Tick();

		WindowData GetWindowData() { return mWindowData; }
		HPEN GetPen(ePenColor color) { return mPens[(UINT)color]; }
		HBRUSH GetBrush(eBrushColor color) { return mBrushes[(UINT)color]; }

	private:
		Application();
		~Application();

		void initializeWindow(WindowData data);

	private:
		WindowData mWindowData;
		HPEN mPens[(UINT)ePenColor::End];
		HBRUSH mBrushes[(UINT)eBrushColor::End];
	};
}


