#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Pixelize {

	class PIXELIZE_API Application {
		public:
			Application();
			virtual ~Application();

			void Run();
	};

	Application* CreateApplication();

}


