#include "polygon.h"

using namespace std;

typedef struct 
{
	Pt2D ptCen;
	double dRadius;
} Circle2D;

class Circle : public Polygon
{
public:
	Circle(double dX, double dY, double dRadius);

public:
	double GetCircleArea();
	double GetCirclePerimeter();

private:
	double CalcArea(Circle2D circleInput);
	double CalcPerimeter(Circle2D circleInput);

	Circle2D circle_;
};