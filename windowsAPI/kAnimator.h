#pragma once
#include "kComponent.h"

namespace k
{
	class Animator : public Component
	{
	public :
		Animator();
		~Animator();

		virtual void Tick() override;

	private:


	};
}