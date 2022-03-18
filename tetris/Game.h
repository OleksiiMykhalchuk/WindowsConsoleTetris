#pragma once
#include <chrono>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "FPS.h"
#include <thread>

class Game
{
	using Clock = std::chrono::system_clock;
	using Time = std::chrono::time_point<Clock>;
	friend class FPS;
public:
	Game();

	virtual void OnKeyPressed(int btnCode) = 0; 
	virtual void Update(double dt) = 0;
	virtual bool End() = 0;

	void Run();

private:
	HANDLE m_ConsoleIn;
	
};

