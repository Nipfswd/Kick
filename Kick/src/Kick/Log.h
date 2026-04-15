#pragma once

#include <memory>

#include "Core.h"
#include <spdlog/spdlog.h>

namespace Kick {

	class KICK_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define KC_CORE_TRACE(...)   ::Kick::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KC_CORE_INFO(...)    ::Kick::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KC_CORE_WARN(...)    ::Kick::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KC_CORE_ERROR(...)   ::Kick::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KC_CORE_FATAL(...)   ::Kick::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define KC_TRACE(...)        ::Kick::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KC_INFO(...)         ::Kick::Log::GetClientLogger()->info(__VA_ARGS__)
#define KC_WARN(...)         ::Kick::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KC_ERROR(...)        ::Kick::Log::GetClientLogger()->error(__VA_ARGS__)
#define KC_FATAL(...)		 ::Kick::Log::GetClientLogger()->fatal(__VA_ARGS__)