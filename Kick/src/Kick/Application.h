#pragma once

#include "Core.h"

namespace Kick {

	class KICK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}