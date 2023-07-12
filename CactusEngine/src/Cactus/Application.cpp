#include "Application.h"

#include "Log.h"
#include "Events/ApplicationEvent.h"

namespace Cactus {

	Application::Application()
	{

	};

	Application::~Application()
	{

	};

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			CC_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			CC_TRACE(e);
		}

		while (true);
	}
}