#pragma once
#include "Common.h"
namespace k
{
	class Resource
	{
	public :
		Resource();
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; //���������Լ�

		const std::wstring& GetKey() { return mKey; }
		const std::wstring& GetPath() { return mPath; }

		void SetKey(const std::wstring& key) { mKey = key; }
		void SetPath(const std::wstring& path) { mPath = path; }
	private :
		std::wstring mPath;
		std::wstring mKey;
		//std::map<key,value> // Ʈ�� ���

	};

}

