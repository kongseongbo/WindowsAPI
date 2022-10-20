#pragma once
#include "Common.h"

namespace k
{
	// ���� ���α׷��� �� �༮
	class Application
	{
	public :
		static Application& GetInstance() // �̱������� �����Ҵ����� ���� �̱��������� �Ҹ��ڰ� ȣ����� �ʴ´�.
		{
			static Application mInstance;
			return mInstance;
		}

		

		void Initialize(WindowData data);
		void Tick(); 

	private:
		Application();
		~Application();

	private:
		
		WindowData mWindowData;
	};
}


