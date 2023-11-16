#include "plpch.h"
#include "Application.h"

#include "Pixelize/Events/ApplicationEvent.h"
#include "Pixelize/Log.h"

namespace Pixelize {
	Application::Application() {
	
	}

	Application::~Application() {
	
	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		PL_TRACE(e);

		while (true);
	}
}