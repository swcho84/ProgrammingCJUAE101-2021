#ifndef POINT3D_H_		// for #pragma once in Linux
#define POINT3D_H_

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

typedef struct 
{
	double dX;
	double dY;
	double dZ;
}Pt3D;

class Point3D
{
public:
	Point3D(){};
	Point3D(double dX, double dY, double dZ)
	{
		pt3D_.dX = dX;
		pt3D_.dY = dY;
		pt3D_.dZ = dZ;		
	};
	~Point3D(){};

public:
	Pt3D GetPt3D()
	{
		return pt3D_;
	};

	void SetPt3D(double dX, double dY, double dZ)
	{
		pt3D_.dX = dX;
		pt3D_.dY = dY;
		pt3D_.dZ = dZ;		
	};

	double CalcDistBtwPt3D(Pt3D ptA, Pt3D ptB)
	{
		return (sqrt((((ptA.dX) - (ptB.dX)) * ((ptA.dX) - (ptB.dX))) +
							 	 (((ptA.dY) - (ptB.dY)) * ((ptA.dY) - (ptB.dY))) +
								 (((ptA.dZ) - (ptB.dZ)) * ((ptA.dZ) - (ptB.dZ)))));
	}	

private:
	Pt3D pt3D_;
};

#endif