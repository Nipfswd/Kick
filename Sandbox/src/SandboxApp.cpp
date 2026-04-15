#include <Kick.h>

class Sandbox : public Kick::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Kick::Application* Kick::CreateApplication()
{
	return new Sandbox();
}