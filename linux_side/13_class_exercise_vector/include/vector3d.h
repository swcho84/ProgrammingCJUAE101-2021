#ifndef VECTOR3D_H_		// for #pragma once in Linux
#define VECTOR3D_H_

#include <stdio.h>
#include <iostream>
#include <cmath>
#include "vector_calculation.h"

using namespace std;

class Vector3D : public Point3D, public VectorCalculation
{
public:
	Vector3D();
	Vector3D(Pt3D ptA, Pt3D ptB);

public:
	Vec3D GetVec3D();
	void SetVec3D(Pt3D ptA, Pt3D ptB);

public:
	Vec3D CalcVecAdd(Vec3D vecA, Vec3D vecB);
	Vec3D CalcVecSub(Vec3D vecA, Vec3D vecB);
	double CalcVecInnerProd(Vec3D vecA, Vec3D vecB);
	Vec3D CalcVecCrossProd(Vec3D vecA, Vec3D vecB);
	double CalcVecNorm(Vec3D vecInput);
	Vec3D CalcVecUnit(Vec3D vecInput);		

private:
	Vec3D vec3D_;
};

#endif