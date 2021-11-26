#pragma once
#include "global_header.h"

using namespace std;

class CalcVec3D
{
public:
  CalcVec3D();
  Vec3D CalcVecFromPts(Pt3D ptA, Pt3D ptB);
  double CalcVec3DNorm(Vec3D vecA);
  double CalcVec3DInnerProd(Vec3D vecA, Vec3D vecB);
  //Vec3D CalcVec3DCrossProd(Vec3D vecA, Vec3D vecB);
  Vec3D CalcVec3DAdd(Vec3D vecA, Vec3D vecB);
  Vec3D CalcVec3DSub(Vec3D vecA, Vec3D vecB);
  Vec3D CalcVec3DUnit(Vec3D vecA);
};
