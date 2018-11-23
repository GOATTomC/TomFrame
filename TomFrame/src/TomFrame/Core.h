#pragma once

#ifdef TF_PLATFORM_WINDOWS
	#ifdef TF_BUILD_DLL
		#define TOMFRAME_API __declspec(dllexport)
	#else
		#define TOMFRAME_API __declspec(dllimport)
	#endif // TF_BUILD_DLL
#else
	#error TomFrame only supports Windows!
#endif // TF_PLATFORM_WINDOWS
