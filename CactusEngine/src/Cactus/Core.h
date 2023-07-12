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

#define BIT(x) (1 << x)