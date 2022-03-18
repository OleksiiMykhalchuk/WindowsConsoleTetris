#include "FPS.h"

FPS::FPS(float duration)
{
	m_Duration = duration * 1000;
	wchar_t s[256];
	swprintf_s(s, 256, L"FPS: %3.2f fps", 1.0f/m_Duration);
	SetConsoleTitle(s);
}
