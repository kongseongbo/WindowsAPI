#include "kEntity.h"

namespace k
{
	Entity::Entity()
		: mName(L"")
		, mID((UINT32)this) // �ұ�Ģ���� ���ڸ� �ֱ����� �ڽ��� �ּҰ����� �ʱ�ȭ
	{
	}
	Entity::~Entity()
	{
	}
}
