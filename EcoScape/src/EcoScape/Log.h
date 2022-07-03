#pragma once
#include "Core.h"

namespace EcoScape
{
	class ECOSCAPE_API Log
	{
	public:
		void Init();

		enum class Severity
		{
			Trace,
			Info,
			Warn,
			Error,
			Fatal
		};

		enum class Logger
		{
			Core,
			Client
		};

		static void WriteToConsole(Logger lgr, Severity svy, const char* str, ...);

	private:

	};
}

//core log macros
#define ES_CORE_TRACE(...)   ::EcoScape::Log::WriteToConsole(EcoScape::Log::Logger::Core, EcoScape::Log::Severity::Trace, __VA_ARGS__)
#define ES_CORE_INFO(...)    ::EcoScape::Log::WriteToConsole(EcoScape::Log::Logger::Core, EcoScape::Log::Severity::Info, __VA_ARGS__)
#define ES_CORE_WARN(...)    ::EcoScape::Log::WriteToConsole(EcoScape::Log::Logger::Core, EcoScape::Log::Severity::Warn, __VA_ARGS__)
#define ES_CORE_ERROR(...)   ::EcoScape::Log::WriteToConsole(EcoScape::Log::Logger::Core, EcoScape::Log::Severity::Error, __VA_ARGS__)
#define ES_CORE_FATAL(...)   ::EcoScape::Log::WriteToConsole(EcoScape::Log::Logger::Core, EcoScape::Log::Severity::Fatal, __VA_ARGS__)
							
//app log macros								
#define ES_TRACE(...)        ::EcoScape::Log::WriteToConsole(EcoScape::Log::Logger::Client, EcoScape::Log::Severity::Trace, __VA_ARGS__)
#define ES_INFO(...)         ::EcoScape::Log::WriteToConsole(EcoScape::Log::Logger::Client, EcoScape::Log::Severity::Info, __VA_ARGS__)
#define ES_WARN(...)         ::EcoScape::Log::WriteToConsole(EcoScape::Log::Logger::Client, EcoScape::Log::Severity::Warn, __VA_ARGS__)
#define ES_ERROR(...)        ::EcoScape::Log::WriteToConsole(EcoScape::Log::Logger::Client, EcoScape::Log::Severity::Error, __VA_ARGS__)
#define ES_FATAL(...)        ::EcoScape::Log::WriteToConsole(EcoScape::Log::Logger::Client, EcoScape::Log::Severity::Fatal, __VA_ARGS__)