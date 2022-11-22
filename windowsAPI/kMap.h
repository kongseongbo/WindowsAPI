#pragma once
#include "kGameObject.h"

namespace k
{
	class Image;
	class Map : public GameObject
	{
	public:
		Map();
		~Map();

		virtual void Initialize() override;
		virtual void Tick()override;
		virtual void Render(HDC hdc)override;

		void SetImage(const std::wstring& key, const std::wstring& fileName);

	private:
		Image* mImage;

	};
}