#pragma once
#include "kUiBase.h"

namespace k
{
	class Panel : public UiBase
	{
	public:
		Panel(eUIType type);
		~Panel();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

	private:
		

	};
}
