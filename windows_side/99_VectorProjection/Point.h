#pragma once
#include "global_header.h"

using namespace std;

class Point
{
public:
  Point(double dX, double dY, double dZ);
  Pt3D GetPoint();
  void SetPoint(double dX, double dY, double dZ);

private:
  Pt3D pt3D_;
};

