#include "polygon.h"

using namespace std;

typedef struct 
{
	Pt2D ptA;
	Pt2D ptB;
	Pt2D ptC;
} Triangle2D;

class Triangle : public Polygon
{
public:
	Triangle(double dX1, double dY1, double dX2, double dY2, double dX3, double dY3);

public:
	double GetTriangleArea();
	double GetTrianglePerimeter();

private:
	double CalcArea(Triangle2D triangleInput);
	double CalcPerimeter(Triangle2D triangleInput);

	Triangle2D triangle_;
};