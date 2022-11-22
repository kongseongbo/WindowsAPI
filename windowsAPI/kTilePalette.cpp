#include "kTilePalette.h"
#include "kImage.h"
#include "kResources.h"
#include "kObject.h"
#include "kToolScene.h"
#include "kInput.h"


namespace k
{
	TilePalette::TilePalette()
	{
		mImage
			= Resources::Load<Image>(L"TileAtlas", L"..\\Resources\\Image\\Tile.bmp");
	}

	TilePalette::~TilePalette()
	{
	}

	void TilePalette::Tick()
	{
		if (KEY_PREESE(eKeyCode::LBTN))
		{
			if (GetFocus())
			{
				k::Vector2 mousePos = k::Input::GetMousePos();

				int y = mousePos.y / (TILE_SIZE * TILE_SCALE);
				int x = mousePos.x / (TILE_SIZE * TILE_SCALE);

				k::Scene* scene = k::SceneManager::GetPlayScene();
				k::ToolScene* toolScene = dynamic_cast<k::ToolScene*>(scene);
				UINT index = toolScene->GetTileIndex();

				CrateTile(index, Vector2(x, y));
			}

		}
	}

	void TilePalette::Render(HDC hdc)
	{
	}
	void TilePalette::CrateTile(UINT index, Vector2 indexPos)
	{
		TileID key;
		key.left = indexPos.x;
		key.right = indexPos.y;

		std::unordered_map<UINT64, Tile*>::iterator iter = mTiles.find(key.ID);
		if (iter != mTiles.end())
		{
			iter->second->SetIndex(index);
		}

		Vector2 objectPos = indexPos * (TILE_SIZE * TILE_SCALE);

		Tile* tile = object::Instantiate<Tile>(objectPos, eColliderLayer::Tile);
		tile->Initiailize(mImage, index);

		mTiles.insert(std::make_pair(key.ID, tile));

	}
}