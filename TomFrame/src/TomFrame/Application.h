#pragma once
#include "Core.h"
#include <string>

namespace TomFrame
{
	class WindowSettings;
}

namespace TomFrame {
	class World;
	class TOMFRAME_API Application
	{
	public:
		Application();
		virtual ~Application();

		/*Runs the engine*/
		void Run();
		
	protected:
		/*Contains all the information settings about the application window*/
		WindowSettings* p_WindowSettings;
	};

	/*To be defined in a TomFrame client*/
	Application* CreateApplication(World* world);
}

