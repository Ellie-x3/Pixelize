#pragma once

#ifdef PL_PLATFORM_WINDOWS
	#ifdef PL_BUILD_DLL
		#define PIXELIZE_API __declspec(dllexport)
	#else
		#define PIXELIZE_API __declspec(dllimport)
	#endif // PL_BUILD_DLL
#else
	#error Pixelize only supports windows
#endif // PL_PLATFORM_WINDOWS
