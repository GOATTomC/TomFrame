#pragma once
#include <string>
#include "../core.h"

namespace TomFrame
{
	namespace Debug
	{
		class TOMFRAME_API Logger
		{
		public:
			Logger();
			~Logger();

			/*Prints a message to the console*/
			static void Log(std::string output);
			static void Log(float output);

			/*Prints an error message to the console and writes it to an error log*/
			static void LogError(std::string output);
		};
	}
}