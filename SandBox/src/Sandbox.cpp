#include <Pixelize.h>

class Sandbox : public Pixelize::Application {
public:
	Sandbox() {
	
	}

	~Sandbox() {
	
	}
};

Pixelize::Application* Pixelize::CreateApplication() {
	return new Sandbox();
}