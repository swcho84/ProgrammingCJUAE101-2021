#include "triangle.h"

using namespace std;

Triangle::Triangle(double dX1, double dY1, double dX2, double dY2, double dX3, double dY3)
{
	triangle_.ptA.dX = dX1;
	triangle_.ptA.dY = dY1;
	triangle_.ptB.dX = dX2;
	triangle_.ptB.dY = dY2;
	triangle_.ptC.dX = dX3;
	triangle_.ptC.dY = dY3;		
}

double Triangle::GetTriangleArea()
{
	return CalcArea(triangle_);
}

double Triangle::GetTrianglePerimeter()
{
	return CalcPerimeter(triangle_);
}

double Triangle::CalcArea(Triangle2D triangleInput)
{
	// calculating the arbitrary area using the vector cross product
	double dVecAX = triangle_.ptB.dX - triangle_.ptA.dX;
	double dVecAY = triangle_.ptB.dY - triangle_.ptA.dY;
	double dVecBX = triangle_.ptC.dX - triangle_.ptA.dX;
	double dVecBY = triangle_.ptC.dY - triangle_.ptA.dY;
	return (0.5)*(abs(((dVecAX) * (dVecBY)) - ((dVecBX) * (dVecAY))));
}

double Triangle::CalcPerimeter(Triangle2D triangleInput)
{
	double dDistAB = this->CalcDistBtwPts(triangleInput.ptA, triangleInput.ptB);
	double dDistBC = this->CalcDistBtwPts(triangleInput.ptB, triangleInput.ptC);
	double dDistCA = this->CalcDistBtwPts(triangleInput.ptC, triangleInput.ptA);
	return (dDistAB) + (dDistBC) + (dDistCA);
}