#include "kScene.h"
#include "kGameObject.h"

namespace k
{
	Scene::Scene()
	{
	}

	Scene::~Scene()
	{
		for (size_t i = 0; i < mObject.size(); i++)
		{
			delete mObject[i];
		}
	}

	void Scene::Initialize()
	{
		for (size_t i = 0; i < mObject.size(); i++)
		{
			mObject[i]->Initialize();
		}
	}

	void Scene::Tick()
	{
		for (size_t i = 0; i < mObject.size(); i++)
		{
			mObject[i]->Tick();
		}
	}

	void Scene::Render(HDC hdc)
	{

	}

	void Scene::AddGameObject(GameObject* object)
	{
		if (object == nullptr)
			return;

		mObject.push_back(object);
	}
}


