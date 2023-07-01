#include <Cactus.h>

class Sandbox :public Cactus::Application
{
public:
	Sandbox()
	{
		
	}

	~Sandbox()
	{

	}
};

Cactus::Application* Cactus::CreateApplication()
{
	return new Sandbox();
}