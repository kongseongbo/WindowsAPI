#include "kMap.h"
#include "kResources.h"
#include "kImage.h"
#include "kCamera.h"

namespace k
{
	Map::Map()
		: mImage(nullptr)
	{
		SetPos(Vector2::Zero);
		SetScale(Vector2::One);
	}
	Map::~Map()
	{
	}
	void Map::Initialize()
	{
		
	}
	void Map::Tick()
	{
		GameObject::Tick();

		//Pixel로 Map 충돌처리
		//Playerpos;
		//mPixelImage->GetPixel(Playerpos);
	}
	void Map::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();
		Vector2 finalPos = Camera::CalculatePos(pos);

		/*Vector2 rect;
		rect.x = mImage->GetWidth() * scale.x;
		rect.y = mImage->GetHeight() * scale.y;*/

		TransparentBlt(hdc, finalPos.x, finalPos.y, mImage->GetWidth(), mImage->GetHeight()
			, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 0, 255));


		GameObject::Render(hdc);
	}
	void Map::SetImage(const std::wstring& key, const std::wstring& fileName)
	{
		std::wstring path = L"..\\Resources\\Image\\";
		path += fileName;

		mImage = Resources::Load<Image>(key, path);
	}
}