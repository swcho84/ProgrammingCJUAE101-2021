#include "circle.h"

using namespace std;

Circle::Circle(double dX, double dY, double dRadius)
{
	circle_.ptCen.dX = dX;
	circle_.ptCen.dY = dY;
	circle_.dRadius = dRadius;
}

double Circle::GetCircleArea()
{
	return CalcArea(circle_);
}

double Circle::GetCirclePerimeter()
{
	return CalcPerimeter(circle_);
}

double Circle::CalcArea(Circle2D circleInput)
{
	return (PI) * (circleInput.dRadius) * (circleInput.dRadius);
}

double Circle::CalcPerimeter(Circle2D circleInput)
{
	return 2 * (PI) * (circleInput.dRadius);
}