#pragma once
#include "kGameObject.h"

namespace k
{
	class Image;
	class Tile : public GameObject
	{
	public :
		Tile(Vector2 pos);
		~Tile();

		void Initiailize(Image* atlas, int index);
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void SetIndex(UINT index);
		UINT GetIndex() { return mIndex; }

	private:
		Image* mAtlas;
		UINT mIndex;
		UINT mX;
		UINT mY;
	};
}