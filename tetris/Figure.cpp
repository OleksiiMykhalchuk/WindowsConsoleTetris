#include "Figure.h"

Figure::Figure(Point position)
{
	this->m_Position = position;
	m_Body = Generate();
}

void Figure::Update(double dt)
{
	m_TimeFromLastUpdate += dt;
	if (m_TimeFromLastUpdate <= m_TimeForUpdate) return;
	m_TimeForUpdate = 100;
	m_TimeFromLastUpdate = 0;
	
	
	++m_Position.y;
}

void Figure::Draw(Canvas& canvas)
{
	for (const Point& point : m_Body[m_CurrentRotate])
	{
		canvas.SetChar(point.x + m_Position.x, point.y + m_Position.y, 0x25D8);
	}
}

void Figure::MoveR()
{
	m_Position.x++;
}

void Figure::MoveL()
{
	m_Position.x--;
}

const std::vector<Point>& Figure::GetBody() const
{
	return m_Body[m_CurrentRotate];
}

Point Figure::GetPosition() const
{
	return m_Position;
}

void Figure::BackUp()
{
	m_PositionBackUp = m_Position;
	m_CurrentRotateBackUp = m_CurrentRotate;
}

void Figure::Restore()
{
	m_Position = m_PositionBackUp;
	m_CurrentRotate = m_CurrentRotateBackUp;
}

void Figure::Boost()
{
	m_TimeForUpdate = 1;
}

void Figure::Rotate()
{
	++m_CurrentRotate;
	if (m_CurrentRotate >= m_Body.size())
		m_CurrentRotate = 0;
}

std::vector<std::vector<Point>> Figure::Generate()
{
	switch (rand()%5)
	{
	case 0:
		return { { Point(0,0),Point(1,0),Point(2,0),Point(3,0)},
		{ Point(0,0),Point(0,1),Point(0,2),Point(0,3)} };
		
	case 1:
		return { { Point(0,0),Point(1,0),Point(1,1),Point(0,1)} };
		
	case 2:
		return { { Point(0,0),Point(1,0),Point(2,0),Point(1,1)},
		{ Point(1,0),Point(1,1),Point(1,2),Point(0,1)}, 
		{ Point(0,1),Point(1,1),Point(2,1),Point(1,0)},
		{ Point(0,0),Point(0,1),Point(0,2),Point(1,1)} };
	case 3:
		return { {Point(0, 0), Point(0, 1), Point(0,2), Point(1,0)},
		{Point(0, 0), Point(1, 0), Point(2,0), Point(2,1)}, 
		{Point(1, 0), Point(1, 1), Point(1,2), Point(0,2)},
		{Point(0, 1), Point(1, 1), Point(2,1), Point(0,0)} };
	case 4:
		return { {Point(1,0),Point(1,1),Point(1,2),Point(0,0)},
		{Point(0,1),Point(1,1),Point(2,1),Point(2,0)}, 
		{Point(0,0),Point(0,1),Point(0,2),Point(1,2)}, 
		{Point(0,0),Point(1,0),Point(2,0),Point(0,1)} };
		}
	
}
