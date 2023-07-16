#pragma once

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

#define BIT(x) (1 << x)