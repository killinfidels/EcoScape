#include <EcoScape.h>

class Sandbox : public EcoScape::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

//definition for CreateApp 
EcoScape::Application* EcoScape::CreateApplication()
{
	return new Sandbox();
}