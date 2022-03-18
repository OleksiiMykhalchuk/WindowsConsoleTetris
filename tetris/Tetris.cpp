#include "Tetris.h"

Tetris::Tetris() : m_Figure(Point(5,1))
{
	m_GameField.Resize(14, 26);
	m_Canvas.Resize(26, 26);
}

void Tetris::OnKeyPressed(int btnCode)
{
		switch (btnCode)
	{
	case 32: // space
		m_Figure.Rotate();
		break;
	case 75: //arrow left
		m_Figure.MoveL();
		break;
	case 77: //arrow right
		m_Figure.MoveR();
		break;
	case 80: //arrow down
		m_Figure.Boost();
		break;
	default:
		break;
	}

	if (m_GameField.HasCollision(m_Figure))
		m_Figure.Restore();
}

void Tetris::Update(double dt)
{
	m_Figure.BackUp();
	m_Figure.Update(dt);
	if (m_GameField.HasCollision(m_Figure))
	{
		m_Figure.Restore();
		m_GameField.Merge(m_Figure);
		m_Figure = Point(5, 1);
		if (m_GameField.HasCollision(m_Figure))
			m_End = true;
	}
	
	m_Canvas.Clear();

	m_GameField.Draw(m_Canvas);
	m_Figure.Draw(m_Canvas);
	m_Canvas.Render();
}

bool Tetris::End()
{
	return m_End;
}
