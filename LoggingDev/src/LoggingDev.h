#pragma once
#include <iostream>
#include <ctime> //time
#include <string>
#include <cstdarg> //variadic functions

class Log
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

	static void WriteToConsole(Logger lgr, Severity svy, std::string str, ...);

private:

};

//core log macros
#define ES_CORE_TRACE(...)   ::Log::WriteToConsole(Log::Logger::Core, Log::Severity::Trace, __VA_ARGS__)
#define ES_CORE_INFO(...)    ::Log::WriteToConsole(Log::Logger::Core, Log::Severity::Info, __VA_ARGS__)
#define ES_CORE_WARN(...)    ::Log::WriteToConsole(Log::Logger::Core, Log::Severity::Warn, __VA_ARGS__)
#define ES_CORE_ERROR(...)   ::Log::WriteToConsole(Log::Logger::Core, Log::Severity::Error, __VA_ARGS__)
#define ES_CORE_FATAL(...)   ::Log::WriteToConsole(Log::Logger::Core, Log::Severity::Fatal, __VA_ARGS__)
														
//app log macros										
#define ES_TRACE(...)        ::Log::WriteToConsole(Log::Logger::Client, Log::Severity::Trace, __VA_ARGS__)
#define ES_INFO(...)         ::Log::WriteToConsole(Log::Logger::Client, Log::Severity::Info, __VA_ARGS__)
#define ES_WARN(...)         ::Log::WriteToConsole(Log::Logger::Client, Log::Severity::Warn, __VA_ARGS__)
#define ES_ERROR(...)        ::Log::WriteToConsole(Log::Logger::Client, Log::Severity::Error, __VA_ARGS__)
#define ES_FATAL(...)        ::Log::WriteToConsole(Log::Logger::Client, Log::Severity::Fatal, __VA_ARGS__)