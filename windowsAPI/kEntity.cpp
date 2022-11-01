#include "kEntity.h"

namespace k
{
	Entity::Entity()
		: mName(L"")
		, mID((UINT32)this) // 불규칙적인 숫자를 넣기위해 자신의 주소값으로 초기화
	{
	}
	Entity::~Entity()
	{
	}
}
