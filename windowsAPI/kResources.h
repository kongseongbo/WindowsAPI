#pragma once
#include"kResource.h"
#include "Common.h"


namespace k
{
	//���ø��� cpp���Ͽ� �������Ѵ�.
	//������Ͽ��� ����
	class Resources
	{

	public:

		// ResourceIter���� �̸� ���̱� auto iter = mResources.find(key);
		// auto ���� : �������� �ſ� ���δ�.
		typedef std::map<std::wstring, Resource*>::iterator ResourceIter; 

		template <typename T>
		static T* Find(const std::wstring& key)
		{
			ResourceIter iter = mResources.find(key);

			//���ҽ��� �̹� map�ȿ� �����Ѵ�
			if (iter != mResources.end())
				return dynamic_cast<T*>(iter->second); // dynamic_cast �θ��ڽİ� ����ȯ TŸ�԰� ResourceŸ��

			return nullptr;
		}

		template <typename T>
		static T* Load(const std::wstring& key,const std::wstring& path)
		{
			T* resource = Resources::Find<T>(key);

			//�ش� Ű�� �̹� �ε��Ȱ� ������ ���ҽ��� ��ȯ
			if (resource != nullptr)
				return resource;

			//���ҽ� ����
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

		//Resource* �޸� ����
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
		static std::map<std::wstring, Resource*> mResources; // ���ҽ��� �� ����ִ�.

	};
}