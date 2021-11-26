#ifndef POLYGON_H_		// for #pragma once in Linux
#define POLYGON_H_

#include <stdio.h>
#include <iostream>
#include <cmath>

#define PI 3.141592

using namespace std;

typedef struct 
{
	double dX;
	double dY;
}Pt2D;

class Polygon
{
public:
	Polygon(){};
	~Polygon(){};

	virtual double CalcArea(){};
	virtual double CalcPeriMeter(){};

	double CalcDistBtwPts(Pt2D ptA, Pt2D ptB)
	{
		return sqrt(((ptA.dX - ptB.dX)*(ptA.dX - ptB.dX)) + 
								((ptA.dY - ptB.dY)*(ptA.dY - ptB.dY)));
	}
};

#endif