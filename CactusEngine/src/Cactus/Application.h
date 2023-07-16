#pragma once

#include "Core.h"
#include "Application.h"
#include "Cactus/Window.h"
#include "Cactus/Events/ApplicationEvent.h"

namespace Cactus{

	class CACTUS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClosed(WindowCloseEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT (SandboxApp.cpp)
	Application* CreateApplication();
}

