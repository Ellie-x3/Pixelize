#include <Pixelize.h>

class ExampleLayer : public Pixelize::Layer {
public:
	ExampleLayer() : Layer("Example Layer") {}

	void OnUpdate() override {
		//PL_INFO("ExampleLayer::Update");
	}

	void OnEvent(Pixelize::Event& e) override {
		//PL_TRACE("{0}", e);
	}
};

class Sandbox : public Pixelize::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Pixelize::ImGuiLayer());
	}

	~Sandbox() {
	
	}
};

Pixelize::Application* Pixelize::CreateApplication() {
	return new Sandbox();
}