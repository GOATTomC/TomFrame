#include "Logger.h"
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <fstream>

void TomFrame::Debug::Logger::Log(std::string output)
{
	//Print message to console
	std::cout << output << std::endl;
}

void TomFrame::Debug::Logger::Log(float output)
{
	std::cout << output << std::endl;
}

void TomFrame::Debug::Logger::LogError(std::string output)
{
	//Print message to console
	Log(output);

	//Get current time and store in char array
	std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
	std::time_t timeNow = std::chrono::system_clock::to_time_t(currentTime);
	char string[26];
	ctime_s(string, sizeof(string), &timeNow);

	//Write message to log file
	std::ofstream logFile;
	logFile.open("ErrorLogs.txt", std::ios::app);
	logFile << "ERROR: " << output << "DATE OF ERROR: " << string << std::endl;
	logFile.close();

}

