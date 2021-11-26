#ifndef VECTOR_CACULATION_H_		// for #pragma once in Linux
#define VECTOR_CACULATION_H_

#include <stdio.h>
#include <iostream>
#include <cmath>
#include "point2d.h"
#include "point3d.h"

using namespace std;

typedef struct 
{
	double dVecX;
	double dVecY;
}Vec2D;

typedef struct 
{
	double dVecX;
	double dVecY;
	double dVecZ;
}Vec3D;

class VectorCalculation
{
public:
	VectorCalculation(){};
	~VectorCalculation(){};
	
public:
	virtual void CalcVecAdd(){};
	virtual void CalcVecSub(){};
	virtual void CalcVecInnerProd(){};
	virtual void CalcVecCrossProd(){};
	virtual void CalcVecNorm(){};
	virtual void CalcVecUnit(){};	
};

#endif