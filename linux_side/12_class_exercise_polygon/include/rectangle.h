#include "polygon.h"

using namespace std;

typedef struct 
{
	Pt2D ptTopLeft;
	Pt2D ptBottomRight;
	double dWidth;
	double dHeight;
} Rectangle2D;

class Rectangle : public Polygon
{
public:
	Rectangle(double dX1, double dY1, double dX2, double dY2);

public:
	double GetRectangleArea();
	double GetRectanglePerimeter();

private:
	double CalcArea(Rectangle2D rectInput);
	double CalcPerimeter(Rectangle2D rectInput);

	Rectangle2D rect_;
};