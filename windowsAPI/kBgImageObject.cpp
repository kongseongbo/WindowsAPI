#include "kBgImageObject.h"
#include "kResources.h"
#include "kImage.h"
#include "kPlayer.h"
#include "kComponent.h"
namespace k
{
	BgImageObject::BgImageObject()
		: mImage(nullptr)
	{
		SetPos(Vector2::Zero);
		SetScale(Vector2::One);
	}
	BgImageObject::~BgImageObject()
	{
	}
	void BgImageObject::Initialize()
	{
		//mImage = Resources::Load<Image>(L"PlayScenePixel", L"..\\Resources\\Image\\Map\\HenesysGolemSawonPixel.bmp");
	}
	void BgImageObject::Tick()
	{
		GameObject::Tick();

		//Pixel로 Map 충돌처리
		//Playerpos;
		//mPixelImage->GetPixel(Playerpos);
		
	}
	void BgImageObject::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();
		Vector2 finalPos = pos;

		/*Vector2 rect;
		rect.x = mImage->GetWidth() * scale.x;
		rect.y = mImage->GetHeight() * scale.y;*/

		TransparentBlt(hdc, finalPos.x, finalPos.y, mImage->GetWidth(), mImage->GetHeight()
			, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 0, 255));


		GameObject::Render(hdc);
	}
	void BgImageObject::SetImage(const std::wstring& key, const std::wstring& fileName)
	{
		std::wstring path = L"..\\Resources\\Image\\";
		path += fileName;

		mImage = Resources::Load<Image>(key, path);
	}
}