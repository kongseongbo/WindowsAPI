#include "kAnimation.h"
#include "kImage.h"
#include "kAnimator.h"
#include "kGameObject.h"
#include "kCamera.h"

namespace k
{
	Animation::Animation()
	{

	}
	Animation::~Animation()
	{

	}

	void Animation::Tick()
	{

	}
	void Animation::Render(HDC hdc)
	{
		GameObject* gameObj = mAnimator->GetOwner();
		Vector2 pos = gameObj->GetPos();

		if (mAffectedCamera)
			pos = Camera::CalculatePos(pos);


		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 127; // 0 - 225

		AlphaBlend(hdc
			, int(pos.x - mSpriteSheet[mSpriteIndex].size.x / 2.0f)
			, int(pos.y - mSpriteSheet[mSpriteIndex].size.y / 2.0f)
			, int(mSpriteSheet[mSpriteIndex].size.x)
			, int(mSpriteSheet[mSpriteIndex].size.y)
			, mImage->GetDC()
			, int(mSpriteSheet[mSpriteIndex].leftTop.x)
			, int(mSpriteSheet[mSpriteIndex].leftTop.y)
			, int(mSpriteSheet[mSpriteIndex].size.x)
			, int(mSpriteSheet[mSpriteIndex].size.y)
			, func);

	}

	void Animation::Create(Image* image, Vector2 leftTop, Vector2 size, Vector2 offset
		, float columnLength, UINT spriteLegth, float duration, bool bAffectedCamera)
	{
		mImage = image;
		mAffectedCamera = bAffectedCamera;

		for (size_t i = 0; i < spriteLegth; i++)
		{
			Sprite sprite;
			sprite.leftTop.x = leftTop.x + (columnLength * (float)i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mSpriteSheet.push_back(sprite);
		}

	}

	void Animation::Reset()
	{

	}
}