#pragma once

//checks if platform windows, this define is made in the preproccessor for both application and engine
#ifdef ES_PLATFORM_WINDOWS
	#ifdef ES_BUILD_DLL // this one is only in engine
		#define ECOSCAPE_API __declspec(dllexport) //exports dll if engine
	#else
		#define ECOSCAPE_API __declspec(dllexport) //imports if application
	#endif
#else
	#error EcoScape only supports windows!
#endif // ES_PLATFORM_WINDOWS
