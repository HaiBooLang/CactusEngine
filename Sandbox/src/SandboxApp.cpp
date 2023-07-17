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
		CC_INFO("ExampleLayer::Update");
	}

	void OnEvent(Cactus::Event& event) override
	{
		CC_TRACE("{0}", event);
	}

};

class Sandbox :public Cactus::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Cactus::Application* Cactus::CreateApplication()
{
	return new Sandbox();
}