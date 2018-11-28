#include "WindowSettings.h"


TomFrame::WindowSettings::WindowSettings()
{

}

TomFrame::WindowSettings::~WindowSettings()
{

}

void TomFrame::WindowSettings::SetWindowText(const char* windowText)
{
	m_WindowText = windowText;
}

const char* TomFrame::WindowSettings::GetWindowText()
{
	return m_WindowText;
}

void TomFrame::WindowSettings::SetFullScreen(bool value)
{
	m_IsFullScreen = value;
}

bool TomFrame::WindowSettings::GetFullScreen()
{
	return m_IsFullScreen;
}

void TomFrame::WindowSettings::SetScreenSize(int width, int height)
{
	m_ScreenSize = ScreenSize(width, height);
}

TomFrame::ScreenSize TomFrame::WindowSettings::GetScreenSize()
{
	return m_ScreenSize;
}

