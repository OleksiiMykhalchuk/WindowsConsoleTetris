#include "Canvas.h"

Canvas::Canvas()
{
	m_ScreenWidth = 60;
	m_ScreenHeight = 60;

	m_ConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);

}

Canvas::~Canvas()
{
	delete[] m_Buffer;
}

void Canvas::SetChar(int x, int y, wchar_t c)
{
	m_Buffer[y * m_ScreenWidth + x].Char.UnicodeChar = c;
	m_Buffer[y * m_ScreenWidth + x].Attributes = 0x000F;
}

wchar_t Canvas::GetChar(int x, int y)
{
	return L'\0';
}

void Canvas::Resize(int height, int width)
{
	m_ScreenWidth = width;
	m_ScreenHeight = height;

	m_WriteRegion = { 0,0,1,1 };
	SetConsoleWindowInfo(m_ConsoleOut, TRUE, &m_WriteRegion);

	m_BufferCoord = { (short)height, (short)width };

	SetConsoleScreenBufferSize(m_ConsoleOut, m_BufferCoord);

	SetConsoleActiveScreenBuffer(m_ConsoleOut);

	// Set the font size now that the screen buffer has been assigned to the console
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 12;
	cfi.dwFontSize.Y = 12;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;

	SetCurrentConsoleFontEx(m_ConsoleOut, false, &cfi);

	m_WriteRegion = { 0,0,(short)width - 1,(short)height - 1 };
	SetConsoleWindowInfo(m_ConsoleOut, TRUE, &m_WriteRegion);

	m_Buffer = new CHAR_INFO[width * height];
	memset(m_Buffer, 0, sizeof(CHAR_INFO) * width * height);

	
}

void Canvas::Render()
{
	WriteConsoleOutput(m_ConsoleOut, m_Buffer, { (short)m_ScreenWidth, (short)m_ScreenHeight }, { 0,0 }, &m_WriteRegion);
}

void Canvas::Clear()
{
	for (size_t x = 0; x < m_ScreenWidth; x++)
	{
		for (size_t y = 0; y < m_ScreenHeight; y++)
		{
			SetChar(x, y, L' ');
		}
	}
}
