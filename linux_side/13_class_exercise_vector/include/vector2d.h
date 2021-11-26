#ifndef VECTOR2D_H_		// for #pragma once in Linux
#define VECTOR2D_H_

#include <stdio.h>
#include <iostream>
#include <cmath>
#include "vector_calculation.h"

using namespace std;

class Vector2D : public Point2D, public VectorCalculation
{
public:
	Vector2D();
	Vector2D(Pt2D ptA, Pt2D ptB);

public:
	Vec2D GetVec2D();
	void SetVec2D(Pt2D ptA, Pt2D ptB);

public:
	Vec2D CalcVecAdd(Vec2D vecA, Vec2D vecB);
	Vec2D CalcVecSub(Vec2D vecA, Vec2D vecB);
	double CalcVecInnerProd(Vec2D vecA, Vec2D vecB);
	Vec3D CalcVecCrossProd(Vec2D vecA, Vec2D vecB);
	double CalcVecNorm(Vec2D vecInput);
	Vec2D CalcVecUnit(Vec2D vecInput);		

private:
	Vec2D vec2D_;
};

#endif