#include "kComponent.h"
#include "kGameObject.h"

namespace k
{
	Component::Component(eComponentType type)
		:mType(type)
		,mOwner(nullptr)
	{

	}

	Component::~Component()
	{
	}

	void Component::Tick()
	{
		
	}

	void Component::Render(HDC hdc)
	{
	}
}


