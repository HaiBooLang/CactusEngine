#include <Cactus.h>

class ExampleLayer : public Cactus::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Cactus::Input::IsKeyPressed(CC_KEY_TAB))
			CC_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Cactus::Event& event) override
	{
		if (event.GetEventType() == Cactus::EventType::KeyPressed)
		{
			Cactus::KeyPressedEvent& e = (Cactus::KeyPressedEvent&)event;
			if (e.GetKeyCode() == CC_KEY_TAB)
				CC_TRACE("Tab key is pressed (event)!");
			CC_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class Sandbox :public Cactus::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Cactus::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Cactus::Application* Cactus::CreateApplication()
{
	return new Sandbox();
}