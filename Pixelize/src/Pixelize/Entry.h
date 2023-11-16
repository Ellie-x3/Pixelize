#pragma once

#ifdef PL_PLATFORM_WINDOWS

extern Pixelize::Application* Pixelize::CreateApplication();

int main(int argc, char** argv) {
	Pixelize::Log::Init();
	PL_CORE_WARN("Initilized Log!");

	auto app = Pixelize::CreateApplication();
	app->Run();
	delete app;
}
#endif