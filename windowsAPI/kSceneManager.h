#pragma once
#include "Common.h"

namespace k
{
	class Scene;
	class SceneManager
	{
	public :
		static void Initialize();
		static void Tick();
		static void Render(HDC hdc);
		static void Reelease();

	private:
		static Scene* mScenes[(UINT)eSceneType::Max];
		static Scene* mPlayScene;

	};
}