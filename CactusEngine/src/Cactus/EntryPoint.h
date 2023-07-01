#pragma once

#ifdef CC_PLATFORM_WINDOWS

extern Cactus::Application* Cactus::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Cactus::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error Cactus only support Windows!
#endif // CC_PLATFORM_WINDOWS
