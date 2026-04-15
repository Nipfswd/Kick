#pragma once

#ifdef KC_PLATFORM_WINDOWS

extern Kick::Application* Kick::CreateApplication();

int main(int argc, char** argv)
{
	Kick::Log::Init();
	KC_CORE_WARN("Initialized Log!");
	int a = 5;
	KC_INFO("Hello! Var={0}", a);

	auto app = Kick::CreateApplication();
	app->Run();
	delete app;
}

#endif