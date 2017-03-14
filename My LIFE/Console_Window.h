#ifndef _CONSOLE_WINDOW_H
#define _CONSOLE_WINDOW_H
class Console_Window
{
public:
	Console_Window();
	Console_Window(Console_Window&);
	~Console_Window();
	static void Create();
	static void Close();
private:
	static int m_hConsole;
};
#endif

