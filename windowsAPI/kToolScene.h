#pragma once
#include "kScene.h"
#include "kTilePalette.h"

namespace k
{
	class Image;
	class ToolScene : public Scene
	{
	public:
		ToolScene();
		~ToolScene();

		void Initialize() override;
		void Tick() override;
		void Render(HDC hdc) override;

		virtual void Enter(); // 씬이 변경될때마다
		virtual void Exit();

		Image* GetAtalasImage() { return mTilePalette->GetAtlasImage(); }
		void SetTileIndex(UINT index) { mTileIndex = index; }
		UINT GetTileIndex() { return mTileIndex; }

	private:
		TilePalette* mTilePalette;
		UINT mTileIndex;

	};

}