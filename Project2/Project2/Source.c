#include <Windows.h>
#pragma comment(linker,"/ENTRY:main")
#define SIZEBUF 12
void main()
{
	HANDLE Output = GetStdHandle(STD_OUTPUT_HANDLE);
	wchar_t buff[13] = { 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd' };
	WriteConsole(Output, buff, SIZEBUF, 0, 0);
}