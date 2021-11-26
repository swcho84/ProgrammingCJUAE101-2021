#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(double dX1, double dY1, double dX2, double dY2)
{
	rect_.ptTopLeft.dX = dX1;
	rect_.ptTopLeft.dY = dY1;
	rect_.ptBottomRight.dX = dX2;
	rect_.ptBottomRight.dY = dY2;
	rect_.dWidth = abs(rect_.ptBottomRight.dX - rect_.ptTopLeft.dX);
	rect_.dHeight = abs(rect_.ptBottomRight.dY - rect_.ptTopLeft.dY);	
}

double Rectangle::GetRectangleArea()
{
	return CalcArea(rect_);
}

double Rectangle::GetRectanglePerimeter()
{
	return CalcPerimeter(rect_);
}

double Rectangle::CalcArea(Rectangle2D rectInput)
{
	return ((rectInput.dWidth) * (rectInput.dHeight));
}

double Rectangle::CalcPerimeter(Rectangle2D rectInput)
{
	return (2.0) * (((rectInput.dWidth) + (rectInput.dHeight)));
}