#include "plpch.h"
#include "Application.h"

#include "Pixelize/Log.h"

#include <GLFW/glfw3.h>

namespace Pixelize {

#define BIND_EVENT_FN(x) std::bind(x, this, std::placeholders::_1)
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(&Application::OnEvent));
	}

	Application::~Application() {
	
	}

	void Application::Run() {
		while (m_IsRunning) {
			glClearColor(0.7, 0.83, 0.88, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FN(&Application::OnWindowClosed));
		PL_CORE_TRACE("{0}", e);  	
	}

	bool Application::OnWindowClosed(WindowClosedEvent& e) {
		m_IsRunning = false;
		return true;
	}
}