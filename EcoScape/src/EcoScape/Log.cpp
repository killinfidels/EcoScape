#include "precompiledheaders.h"
#include "Log.h"

namespace EcoScape
{
	void Log::Init()
	{

	}

	void Log::WriteToConsole(Logger lgr, Severity svy, const char* str, ...)
	{
		va_list args; // list of variables
		va_start(args, str); // stores arguements in args, str is the last Required arguement so the rest is the variables

		const char* console; // name of console
		std::string timeColor = "\x1B["; // for setting color \x1B starts all escape, CSI([) n m is for graphics. m terminates
		std::string textColor = "\x1B["; // all text after time? subject to change

		switch (lgr) //sets background color if ECOSCAPE
		{
		case Log::Logger::Core:
			console = "ECOSCAPE";
			break;
		case Log::Logger::Client:
			console = "APP";
			break;
		default:
			break;
		}

		switch (svy) //sets text color based on severity of message
		{
		case Log::Severity::Trace:
			timeColor = "";
			textColor = "";
			break;
		case Log::Severity::Info:
			timeColor = "";
			textColor = textColor + "32m"; // GREEN FG
			break;
		case Log::Severity::Warn:
			timeColor = "";
			textColor = textColor + "33m"; // YELLOW FG
			break;
		case Log::Severity::Error:
			timeColor = "";
			textColor = textColor + "31m"; // RED FG
			break;
		case Log::Severity::Fatal:
			timeColor = timeColor + "91m"; //RED BG
			[[fallthrough]]; // fatal has white text so we fallthrough baby
		default: // default is white so we just clear textcolor
			textColor = "";
			break;
		}

		std::time_t rawTime;
		struct tm* timeStruct;

		time(&rawTime);
		timeStruct = localtime(&rawTime);

		// print time and set colors
		printf("%s[%i:%i:%i] %s%s: ", timeColor.c_str(), timeStruct->tm_hour, timeStruct->tm_min, timeStruct->tm_sec, textColor.c_str(), console);

		// print log
		vprintf(str, args); // hehehe variadrics bitch

		// clear color and newline :)
		printf("\x1B[0m\n");

		va_end(args);
	}

}