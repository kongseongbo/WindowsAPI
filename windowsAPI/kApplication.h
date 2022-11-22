#pragma once
#include "Common.h"

namespace k
{
	// ���� ���α׷��� �� �༮
	class Application
	{
	public:
		static Application& GetInstance() // �̱������� �����Ҵ����� ���� �̱��������� �Ҹ��ڰ� ȣ����� �ʴ´�.
		{
			static Application mInstance;
			return mInstance;
		}

		void Initialize(WindowData data);
		void initializeAtlasWindow(WindowData data);
		void Tick();

		void SetMenuBar(bool power); 

		WindowData GetWindowData() { return mWindowData; }
		WindowData GetAtlasWindowData() { return mAtlasWindowData; }
		HDC GetHdc() { return mWindowData.hdc; }
		HPEN GetPen(ePenColor color) { return mPens[(UINT)color]; }
		HBRUSH GetBrush(eBrushColor color) { return mBrushes[(UINT)color]; }
		eSceneType GetPlaySceneType();

	private:
		Application();
		~Application();

		void initializeWindow(WindowData data);

	private:
		WindowData mWindowData;
		WindowData mAtlasWindowData;

		HPEN mPens[(UINT)ePenColor::End];
		HBRUSH mBrushes[(UINT)eBrushColor::End];

		HMENU mMenu;
	};
}


