#pragma once

#ifdef CC_PLATFORM_WINDOWS

extern Cactus::Application* Cactus::CreateApplication();

int main(int argc, char** argv)
{
	Cactus::Log::Init();
	CC_CORE_WARN("Initialized Log!");
	CC_INFO("Hello!");

	auto app = Cactus::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error Cactus only support Windows!
#endif // CC_PLATFORM_WINDOWS
