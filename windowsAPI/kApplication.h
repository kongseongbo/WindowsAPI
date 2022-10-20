#pragma once
#include "Common.h"

namespace k
{
	// 메인 프로그램이 될 녀석
	class Application
	{
	public :
		static Application& GetInstance() // 싱글턴패턴
		{
			return mInstance;
		}

		Application();
		~Application();

		void Initialize(WindowData data);
		void Tick(); 

	private:
		static Application mInstance;
		WindowData mWindowData;
	};
}


