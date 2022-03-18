#include "Game.h"


Game::Game()
{
	m_ConsoleIn = GetStdHandle(STD_INPUT_HANDLE);
	printf("Game Constructor\n");
}



void Game::Run()
{
	Time last = Clock::now();
	
	while (true)
	{
		while (!End())
		{
			Time now = Clock::now();
			std::chrono::duration<float> elapsed = now - last;

			FPS fps(elapsed.count());
			
		
			if (_kbhit())
			{
				OnKeyPressed(_getch()); 
				if (!FlushConsoleInputBuffer(m_ConsoleIn))
					std::cout << "FlushConsoleInputBuffer failed with error " << GetLastError() << std::endl;

			}
			
			
			Update(static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now()-last).count()));
			
			last = Clock::now();
			
			
		}

	}
	

}
