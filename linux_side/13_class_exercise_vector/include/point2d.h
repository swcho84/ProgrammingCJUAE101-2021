#ifndef POINT2D_H_		// for #pragma once in Linux
#define POINT2D_H_

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

typedef struct 
{
	double dX;
	double dY;
}Pt2D;

class Point2D
{
public:
	Point2D(){};
	Point2D(double dX, double dY)
	{
		pt2D_.dX = dX;
		pt2D_.dY = dY;
	};
	~Point2D(){};

public:
	Pt2D GetPt2D()
	{
		return pt2D_;
	};

	void SetPt2D(double dX, double dY)
	{
		pt2D_.dX = dX;
		pt2D_.dY = dY;		
	};

	double CalcDistBtwPt2D(Pt2D ptA, Pt2D ptB)
	{
		return (sqrt((((ptA.dX) - (ptB.dX)) * ((ptA.dX) - (ptB.dX))) +
							 	 (((ptA.dY) - (ptB.dY)) * ((ptA.dY) - (ptB.dY)))));
	}

private:
	Pt2D pt2D_;
};

#endif