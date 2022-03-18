#pragma once
#include <vector>
#include "Canvas.h"
#include <thread>

struct Point
{
	Point(){}
	Point(int _x, int _y):x(_x),y(_y){}
	int x;
	int y;
};
class Figure
{
public:
	
	Figure(Point position);
	void Update(double dt);
	void Draw(Canvas& canvas);
	void MoveR();
	void MoveL();
	const std::vector<Point>& GetBody() const;
	Point GetPosition() const;

	void BackUp();
	void Restore();
	void Boost();
	void Rotate();
	std::vector<std::vector<Point>> Generate();
private:
	Point m_Position;
	Point m_PositionBackUp;
	double m_TimeFromLastUpdate = 0;
	double m_TimeForUpdate = 100;
	std::vector<std::vector<Point>> m_Body;
	size_t m_CurrentRotate = 0;
	size_t m_CurrentRotateBackUp = 0;
	
};

