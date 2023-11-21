#pragma once

#include <Pixelize/Core.h>

namespace Pixelize {
	class PIXELIZE_API Input {
	public:
		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

		inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		inline static bool GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static bool GetMouseY() { return s_Instance->GetMouseXImpl(); }
		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;

		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual bool GetMouseXImpl() = 0;
		virtual bool GetMouseYImpl() = 0;
		virtual std::pair<float,float> GetMousePositionImpl() = 0;
	private:
		static Input* s_Instance;
	};
}