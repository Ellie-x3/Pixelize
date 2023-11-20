#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Pixelize/Window.h"
#include "Pixelize/Events/ApplicationEvent.h"
#include "Pixelize/LayerStack.h"

namespace Pixelize {

	class PIXELIZE_API Application {
		public:
			Application();
			virtual ~Application();

			void Run();

			void OnEvent(Event& e);

			void PushLayer(Layer* layer);
			void PushOverlay(Layer* overlay);

			inline Window& GetWindow() { return *m_Window; }

			inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClosed(WindowClosedEvent& e);

		bool m_IsRunning = true;
		std::unique_ptr<Window> m_Window;

		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();

}


