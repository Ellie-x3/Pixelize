#include <Pixelize.h>

class TestLayer : public Pixelize::Layer {
public:
	TestLayer() : Layer("Test Layer") {}

	void OnUpdate() override {
		if (Pixelize::Input::IsKeyPressed(PL_KEY_SPACE))
			PL_WARN("Space was pressed!");
	}

	void OnEvent(Pixelize::Event& e) override {

	}
};

class Sandbox : public Pixelize::Application {
public:
	Sandbox() {
		PushLayer(new TestLayer());
		PushOverlay(new Pixelize::ImGuiLayer());
	}

	~Sandbox() {
	
	}
};

Pixelize::Application* Pixelize::CreateApplication() {
	return new Sandbox();
}