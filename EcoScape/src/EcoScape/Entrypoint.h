#pragma once

#ifdef ES_PLATFORM_WINDOWS

//external from Application.h
extern EcoScape::Application* EcoScape::CreateApplication();

int main(int argc, char** argv)
{
	ES_CORE_WARN("We ballin!");

	ES_TRACE("FARTS!?");


	auto app = EcoScape::CreateApplication();
	app->Run();
	delete app;
}

#endif // ES_PLATFORM_WINDOWS
