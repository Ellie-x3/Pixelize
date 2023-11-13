#pragma once

#include "Core.h"

namespace Pixelize {

	class PIXELIZE_API Application {
		public:
			Application();
			virtual ~Application();

			void Run();
	};

	Application* CreateApplication();

}


