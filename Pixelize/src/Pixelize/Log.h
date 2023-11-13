#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Pixelize {
	class PIXELIZE_API Log {
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define PL_CORE_FATAL(...)   ::Pixelize::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define PL_CORE_ERROR(...)   ::Pixelize::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PL_CORE_WARN(...)    ::Pixelize::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PL_CORE_INFO(...)    ::Pixelize::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PL_CORE_TRACE(...)   ::Pixelize::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define PL_CLIENT_FATAL(...) ::Pixelize::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define PL_CLIENT_ERROR(...) ::Pixelize::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PL_CLIENT_WARN(...)  ::Pixelize::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PL_CLIENT_INFO(...)  ::Pixelize::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PL_CLIENT_TRACE(...) ::Pixelize::Log::GetCoreLogger()->trace(__VA_ARGS__)

