#pragma once

#include "ccpch.h"
#include "Cactus/Core.h"

namespace Cactus {

	enum class EventType
	{
		None = 0,
		WindowClose,		WindowResize,			WindowFocus,	WindowLostFocus,	WinodeMoved,
		AppTick,			AppUpdate,				AppRender,
		KeyPressed,			KeyReleased,
		MouseButtonPressed,	MouseButtonReleased,	MouseMoved,		MouseScrolled
		// Gamepad
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
		// EventCategoryGamepad		= BIT(5)
	};

#define EVENT_CLASS_TYPE(type)	static	EventType	GetStaticType()		{ return EventType::##type; }\
								virtual EventType	GetEventType()		const override { return GetStaticType(); }\
								virtual const char* GetName()			const override { return #type; }

#define EVENT_CLASS_CATEGORY(category)	virtual int GetCategoryFlags()	const override { return category; }

	class CACTUS_API Event
	{
	public:
		virtual	EventType	GetEventType()		const = 0;
		virtual int			GetCategoryFlags()	const = 0;
		virtual	const char* GetName()			const = 0;
		virtual std::string	ToString()			const { return GetName(); }

		inline	bool		IsInCategory(EventCategory category)	{ return GetCategoryFlags() & category; }
	public:
		bool Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}


