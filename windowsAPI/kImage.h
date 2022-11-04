#pragma once
#include "kResource.h"
namespace k
{
	class Image : public Resource // �߻�Ŭ���� ���
	{
	public :
		static Image* Create(const std::wstring& key, UINT width, UINT height);

		Image();
		~Image();

		virtual HRESULT Load(const std::wstring& path) override;

		HDC GetDC() { return mHdc; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }

	private:
		HBITMAP mBitmap;
		HDC mHdc;
		UINT mWidth;
		UINT mHeight;
		
	};

}

