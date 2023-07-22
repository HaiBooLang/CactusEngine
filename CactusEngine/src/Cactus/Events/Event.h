#pragma once

#include "ccpch.h"
#include "Cactus/Core.h"

/**
 * 在应用程序中，事件是指在特定时间发生的动作或状态变化。例如，用户单击鼠标、按下键盘、窗口大小改变等都可以被视为事件。
 * 事件是应用程序与用户交互的重要方式，它可以触发应用程序中的特定操作或行为。
 * 
 * 为了处理这些事件，我们需要定义一些事件类来表示不同类型的事件。事件类通常包含一些属性。
 * 当事件发生时，应用程序会创建相应的事件对象，并将其传递给事件处理器函数进行处理。
 * 
 * 设计事件类的好处在于，它可以将事件的处理逻辑与应用程序的其他部分分离开来。
 * 通过定义不同类型的事件类，我们可以将事件的处理逻辑封装在事件处理器函数中，从而使应用程序的代码更加模块化和可维护。
 * 此外，事件类还可以提供一些有用的方法，例如将事件对象转换为字符串表示形式，以便于调试和日志记录。
 */
namespace Cactus {

	enum class EventType
	{
		None = 0,
		WindowClose,		WindowResize,		WindowFocus,	WindowLostFocus,	WinodeMoved,
		AppTick,			AppUpdate,			AppRender,
		KeyPressed,			KeyReleased,		KeyTyped,
		MouseButtonPressed,	MouseButtonReleased,MouseMoved,		MouseScrolled
		// Gamepad
	};

	/**
	 * EventCategory是一个枚举类型，它定义了所有可能的事件类型。
	 * 每个类别都由一个位标志表示，可以使用按位运算符组合其他标志。
	 * EventCategory枚举提供了一种方便的方式来分类应用程序中可能发生的不同类型的事件（IsInCategory(EventCategory category)）。
	 */
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

/**
 * EVENT_CLASS_TYPE宏为事件类定义了三个成员函数：GetStaticType、GetEventType和GetName。这些函数用于检索事件类的信息。
 * GetStaticType函数是一个静态成员函数，它返回事件类的类型。它使用EventType枚举实现，该枚举表示应用程序中可能发生的不同类型的事件。
 * EventType::##type是一个预处理器宏，它用于将EventType枚举中的枚举值与事件类的名称连接起来，以生成事件类的类型。
 * GetEventType函数是一个虚成员函数，它返回事件类的类型。它使用GetStaticType函数实现，该函数将事件类的类型作为EventType值返回。
 * GetName函数是一个虚成员函数，它返回事件类的名称。它使用#type预处理器指令实现，该指令将事件类的名称扩展为字符串字面量。
 */
#define EVENT_CLASS_TYPE(type)	static	EventType	GetStaticType()		{ return EventType::##type; }\
								virtual EventType	GetEventType()		const override { return GetStaticType(); }\
								virtual const char* GetName()			const override { return #type; }

#define EVENT_CLASS_CATEGORY(category)	virtual int GetCategoryFlags()	const override { return category; }

	class CACTUS_API Event
	{
	public:
		virtual	EventType	GetEventType()		const = 0;
		virtual int			GetCategoryFlags()	const = 0;		

		inline	bool		IsInCategory(EventCategory category)	{ return GetCategoryFlags() & category; }
		
		// ------------仅调试用------------
		virtual	const char* GetName()			const = 0;
		virtual std::string	ToString()			const { return GetName(); }
	public:
		bool Handled = false;
	};

	/**
	 * 在EventDispatcher类中，使用了一个函数模板EventFn，它是一个std::function对象，用于包装事件处理器函数。
	 * EventDispatcher类的构造函数接受一个事件对象作为参数，用于将事件分发给对应的事件处理器。
	 * EventDispatcher类还定义了一个模板函数Dispatch，用于将事件分发给对应的事件处理器。
	 * Dispatch函数首先检查事件的类型是否与模板参数类型匹配，如果匹配，则将事件转换为模板参数类型，并调用事件处理器函数；
	 * 如果不匹配，则返回false。Dispatch函数的返回值表示事件是否已处理。
	 *
	 * std::function是一个函数对象的包装器，它可以包装任何可调用对象，包括函数指针、函数对象和Lambda表达式等。
	 * std::function对象可以像函数一样被调用，并且可以在运行时动态地绑定到不同的可调用对象。
	 * 使用std::function可以将不同类型的事件处理器函数统一封装成一个对象，从而方便地进行传递和调用。
	 * 这使得std::function对象非常灵活，可以用于实现回调函数、事件处理器等。
	 *
	 * 事件处理器是一种用于处理事件的函数指针、函数对象或Lambda表达式等可调用对象。
	 * 事件处理器通常接受一个事件对象作为参数，并返回一个bool类型的值，表示事件是否已处理。
	 * 事件处理器可以访问事件对象的属性和方法，从而实现对事件的处理。
	 * 事件处理器通常被注册到事件分发器中（ImGuiLayer），当事件发生时，事件分发器会将事件分发给对应的事件处理器进行处理。
	 * 在事件驱动的程序中，事件处理器是非常重要的组成部分。它们可以响应用户的操作、系统的事件和其他程序的消息等。
	 * 事件处理器通常被设计为可重入的，这意味着它们可以在任何时间被调用，并且可以安全地在多个线程中同时执行。
	 */
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
				/**
				 * *(T*)&m_Event是一种类型转换操作，它将m_Event对象转换为类型为T的引用。
				 * 这种类型转换通常被用于将事件对象转换为特定类型的事件，并将其传递给对应的事件处理器函数。
				 * 在进行这种类型转换操作时，需要确保转换后的类型与原始类型具有相同的内存布局和对齐方式，以避免出现潜在的问题。
				 */
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


