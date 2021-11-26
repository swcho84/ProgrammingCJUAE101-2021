#include "Point.h"

using namespace std;

Point::Point(double dX, double dY, double dZ)
{
  pt3D_.dX = dX;
  pt3D_.dY = dY;
  pt3D_.dZ = dZ;
}

Pt3D Point::GetPoint()
{
  return pt3D_;
}

void Point::SetPoint(double dX, double dY, double dZ)
{
  pt3D_.dX = dX;
  pt3D_.dY = dY;
  pt3D_.dZ = dZ;
}