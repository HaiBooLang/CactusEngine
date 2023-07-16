#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Cactus {

	class CACTUS_API Log
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
#define CC_CORE_TRACE(...)	::Cactus::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CC_CORE_INFO(...)	::Cactus::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CC_CORE_WARN(...)	::Cactus::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CC_CORE_ERROR(...)	::Cactus::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CC_CORE_FATAL(...)	::Cactus::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define CC_TRACE(...)		::Cactus::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CC_INFO(...)		::Cactus::Log::GetClientLogger()->info(__VA_ARGS__)
#define CC_WARN(...)		::Cactus::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CC_ERROR(...)		::Cactus::Log::GetClientLogger()->error(__VA_ARGS__)
#define CC_FATAL(...)		::Cactus::Log::GetClientLogger()->fatal(__VA_ARGS__)