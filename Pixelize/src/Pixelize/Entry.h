#pragma once

#ifdef PL_PLATFORM_WINDOWS

extern Pixelize::Application* Pixelize::CreateApplication();

int main(int argc, char** argv) {
	auto app = Pixelize::CreateApplication();
	app->Run();
	delete app;
}
#endif