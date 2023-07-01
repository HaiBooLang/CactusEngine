#pragma once

#include"Core.h"

namespace Cactus{

	class CACTUS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();	
	};

	// To be defined in CLIENT (SandboxApp.cpp)
	Application* CreateApplication();
}

