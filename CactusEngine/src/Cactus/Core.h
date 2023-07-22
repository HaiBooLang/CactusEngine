#pragma once

/**
 * 这段代码的目的是定义一种一致的方式，用于在Windows上从动态链接库（DLL）中导出或导入符号。
 * 当构建DLL时，它会导出可以被其他链接到它的程序使用的符号。
 * 当程序链接到DLL时，它需要知道DLL导出了哪些符号以及如何访问它们。
 * __declspec(dllexport) 和 __declspec(dllimport) 关键字用于指定DLL导出或导入哪些符号。
 */
#ifdef CC_PLATFORM_WINDOWS
	#ifdef CC_BUILD_DLL
		#define CACTUS_API __declspec(dllexport)
	#else
		#define CACTUS_API __declspec(dllimport)
	#endif // CC_BUILD_DLL
#else
	#error Cactus only support Windows!
#endif // CC_PLATFORM_WINDOWS

#ifdef CC_ENABLE_ASSERTS
	#define CC_ASSERT(x, ...) { if(!(x)) { CC_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CC_CORE_ASSERT(x, ...) { if(!(x)) { CC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CC_ASSERT(x, ...)
	#define CC_CORE_ASSERT(x, ...)
#endif

/**
 * 这个宏定义的作用是生成一个二进制位模式，其中只有第x位是1，其余位都是0。
 * 这个宏定义通常用于位运算，可以方便地设置或清除某个二进制位。
 */
#define BIT(x) (1 << x)

/**
 * 这个宏定义用于事件系统（Events）中，可以将一个成员函数绑定到一个事件上，并在事件触发时调用该成员函数。
 * 
 * 在C++中，函数对象（仿函数）是一个类，它重载了"()"操作符使得该类的对象可以像函数一样被调用。
 * 由于函数对象是一个类，因此它可以包含状态（在多次调用中可以共享该状态）和行为，并且可以进行优化，以便在编译时进行内联展开（直接嵌入代码没有函数调用的开销）。
 * 相比之下，函数指针是一个指向函数的指针，它不能包含状态和行为，并且很难进行优化，以便在编译时进行内联展开。
 * 
 * std::bind是一个函数模板，可以将一个函数或可调用对象与一组参数绑定，返回一个新的可调用对象。
 * std::bind第一个参数是成员函数的指针，第二个参数是要绑定的对象的指针，第三个参数是占位符，用于指定成员函数的参数。
 * 
 * 在函数式编程中，通过组合现有的函数，我们可以创造出新的函数。标准库中的std::bind就是可以创造闭包（closure）的工具。
 * 闭包（Closure）是一种函数，它可以访问其定义范围内的变量，并将其保存在一个特殊的数据结构中。闭包还可以使用lambda表达式来实现。
 * 这个数据结构可以在函数执行时被访问和修改，即使这些变量在函数执行时已经超出了其定义范围。
 * 通过std::bind，我们可以为同一个类的不同对象可以分派不同的实现，从而实现不同的行为。这种方式使得我们不在需要设计通过继承与虚函数来实现多态。
 * 
 * 程序库的设计不应该给使用者带来不必要的限制（耦合），而继承是仅次于最强的一种耦合（最强耦合的是友元）。
 */
#define CC_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)