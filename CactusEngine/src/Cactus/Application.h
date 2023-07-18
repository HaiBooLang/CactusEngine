#pragma once

#include "Core.h"

#include "Cactus/Window.h"
#include "Cactus/LayerStack.h"
#include "Cactus/Events/Event.h"
#include "Cactus/Events/ApplicationEvent.h"

namespace Cactus {

	class CACTUS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClosed(WindowCloseEvent& e);
	private:
		bool m_Running = true;
		LayerStack m_LayerStack;
		std::unique_ptr<Window> m_Window;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT (SandboxApp.cpp)
	Application* CreateApplication();
}

