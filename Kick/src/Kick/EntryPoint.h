#pragma once

#ifdef KC_PLATFORM_WINDOWS

extern Kick::Application* Kick::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Kick::CreateApplication();
	app->Run();
	delete app;
}

#endif