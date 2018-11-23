#pragma once
#include "Core.h"


namespace TomFrame 
{
	/*Contains information about the size of the application window*/
	struct TOMFRAME_API ScreenSize
	{
	public:
		int Width;
		int Height;

		ScreenSize()
		{
			Width = 0;
			Height = 0;
		}

		ScreenSize(int width, int height)
			: Width(width), Height(height)
		{}


	};

	class TOMFRAME_API WindowSettings
	{
	public:
		WindowSettings();
		~WindowSettings();

		/*Sets the applications window text*/
		void SetWindowText(const char* windowText);
		/*Gets the applications window text*/
		const char* GetWindowText();

		/*Sets the applications screen size on the start of the application*/
		void SetScreenSize(int width, int height);
		/*Gets the applications screen size*/
		ScreenSize GetScreenSize();

	private:
		/*Holds the application window text*/
		const char* m_WindowText;
		/*Holds the application window size*/
		ScreenSize m_ScreenSize;
	};
}
