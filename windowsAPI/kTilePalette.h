#pragma once
#include "kTile.h"

namespace k
{	
	class Image;
	class TilePalette
	{
	public:
		TilePalette();
		~TilePalette();

		void Tick();
		void Render(HDC hdc);

		void CrateTile(UINT index, Vector2 indexPos);
		//void CrateTiles

		//void Save
		//void Load

		Image* GetAtlasImage() { return mImage; }


	private:
		Image* mImage;
		std::unordered_map<UINT64, Tile*>mTiles;
	};
}