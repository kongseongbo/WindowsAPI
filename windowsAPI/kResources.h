#pragma once
#include"kResource.h"
#include "Common.h"


namespace k
{
	//템플릿은 cpp파일에 구현못한다.
	//헤더파일에서 구현
	class Resources
	{

	public:

		// ResourceIter으로 이름 줄이기 auto iter = mResources.find(key);
		// auto 단점 : 가독성이 매우 별로다.
		typedef std::map<std::wstring, Resource*>::iterator ResourceIter; 

		template <typename T>
		static T* Find(const std::wstring& key)
		{
			ResourceIter iter = mResources.find(key);

			//리소스가 이미 map안에 존재한다
			if (iter != mResources.end())
				return dynamic_cast<T*>(iter->second); // dynamic_cast 부모자식간 형변환 T타입과 Resource타입

			return nullptr;
		}

		template <typename T>
		static T* Load(const std::wstring& key,const std::wstring& path)
		{
			T* resource = Resources::Find<T>(key);

			//해당 키로 이미 로딩된게 있으면 리소스를 반환
			if (resource != nullptr)
				return resource;

			//리소스 없다
			resource = new T();
			if (FAILED(resource->Load(path)))
			{
				MessageBox(nullptr, L"Image Load Failed!!!", L"Error", MB_OK);
				return nullptr;
			}

			resource->SetKey(key);
			resource->SetPath(path);

			mResources.insert(std::make_pair(key, resource));

			return dynamic_cast<T*>(resource);
		}

		//Resource* 메모리 해제
		static void Release()
		{
			ResourceIter iter = mResources.begin();
			for (; iter != mResources.end(); ++iter)
			{
				if (iter->second == nullptr)
					continue;

				delete(iter->second);
				iter->second = nullptr;
			}
			
		}


	private:
		static std::map<std::wstring, Resource*> mResources; // 리소스를 다 담고있다.

	};
}