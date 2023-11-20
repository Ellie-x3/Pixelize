#pragma once

#ifdef PL_PLATFORM_WINDOWS
	#ifdef PL_BUILD_DLL
		#define PIXELIZE_API __declspec(dllexport)
	#else
		#define PIXELIZE_API __declspec(dllimport)
	#endif // PL_BUILD_DLL
#else
	//#error Pixelize only supports windows
#endif // PL_PLATFORM_WINDOWS

#ifdef PL_ENABLE_ASSERTS
	#define PL_ASSERT(x, ...) { if(!(x)) { PL_ERROR("Assertion Failed {0}", __VA_ARGS__); __debugbreak(); } }
	#define PL_CORE_ASSERT(x, ...) { if(!(x)) { PL_ERROR("Assertion Failed {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define PL_ASSERT(x, ...) 
	#define PL_CORE_ASSERT(x, ...) 
#endif

#define BIT(x) (1 << x)

#define PL_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1) 