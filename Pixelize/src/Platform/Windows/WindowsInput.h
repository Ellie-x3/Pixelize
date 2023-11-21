#pragma once

#include "Pixelize/Input.h"

namespace Pixelize {
	class WindowsInput : public Input {
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;

		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual bool GetMouseXImpl() override;
		virtual bool GetMouseYImpl() override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
	};
}