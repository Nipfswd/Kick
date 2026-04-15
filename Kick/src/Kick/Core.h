#pragma once

#ifdef KC_PLATFORM_WINDOWS
	#ifdef KC_BUILD_DLL
		#define KICK_API __declspec(dllexport)
	#else
		#define KICK_API __declspec(dllimport)
	#endif
#else
	#error Kick only supports Windows!
#endif