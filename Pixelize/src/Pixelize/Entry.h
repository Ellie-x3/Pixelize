#pragma once

#ifdef PL_PLATFORM_WINDOWS

extern Pixelize::Application* Pixelize::CreateApplication();

int main(int argc, char** argv) {
	Pixelize::Log::Init();
	PL_CORE_WARN("Initilized Log!");
	PL_CLIENT_INFO("Sup!");

	int a = 5;
	PL_CORE_ERROR("Error: {0}", a);

	auto app = Pixelize::CreateApplication();
	app->Run();
	delete app;
}
#endif