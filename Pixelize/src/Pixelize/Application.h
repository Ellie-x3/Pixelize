#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Pixelize/Window.h"
#include "Pixelize/Events/ApplicationEvent.h"

namespace Pixelize {

	class PIXELIZE_API Application {
		public:
			Application();
			virtual ~Application();

			void Run();

			void OnEvent(Event& e);
	private:
		bool OnWindowClosed(WindowClosedEvent& e);

		bool m_IsRunning = true;
		std::unique_ptr<Window> m_Window;
	};

	Application* CreateApplication();

}


