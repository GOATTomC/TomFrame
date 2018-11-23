#pragma once
#include "Core.h"

namespace TomFrame {

	class TOMFRAME_API Application
	{
	public:
		Application();
		virtual ~Application();

		/*Runs the engine*/
		void Run();
		
	};

	/*To be defined in a TomFrame client*/
	Application* CreateApplication();
}

