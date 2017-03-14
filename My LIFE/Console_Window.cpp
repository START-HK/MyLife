#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include "Console_Window.h"

int Console_Window::m_hConsole = 0;
Console_Window::Console_Window() {
	m_hConsole = 0;
}
Console_Window::Console_Window(Console_Window& other) {

}

Console_Window::~Console_Window() {
	this->Close();
	m_hConsole = 0;
}

void Console_Window::Create() {

	::AllocConsole();
	m_hConsole = ::_open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
	*stdout = *::_fdopen(m_hConsole, "w");
	setvbuf(stdout, NULL, _IONBF, 0);

	return;
}

void Console_Window::Close() {

	if (m_hConsole)
	{
		::_close(m_hConsole);
	}
	return;
}