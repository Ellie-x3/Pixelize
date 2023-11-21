#include "plpch.h"
#include "Application.h"

#include "Pixelize/Log.h"

#include <glad/glad.h>

#include "Input.h"


namespace Pixelize {

#define BIND_EVENT_FN(x) std::bind(x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application() {
		PL_ASSERT(!s_Instance, "Application instance already exists")

		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(&Application::OnEvent));
	}

	Application::~Application() {
	
	}

	void Application::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay) {
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::Run() {
		while (m_IsRunning) {
			glClearColor(0.7, 0.83, 0.88, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();
			//auto [x, y] = Input::GetMousePosition();

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e) { 
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FN(&Application::OnWindowClosed));

		if(e.GetName() != std::string("MouseMoved"))
			PL_CORE_TRACE("{0}", e);  

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	bool Application::OnWindowClosed(WindowClosedEvent& e) {
		m_IsRunning = false;
		return true;
	}
}