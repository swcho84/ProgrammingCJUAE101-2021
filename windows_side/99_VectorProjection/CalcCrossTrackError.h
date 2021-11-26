#pragma once
#include "global_header.h"
#include "CalcVec3D.h"

using namespace std;

class CalcCrossTrackError 
{
public:
  double CalcCrsTrkErr(Vec3D vecA2);
  Vec3D CalcA2(Vec3D vecUnitLine, Vec3D vecA);

private:
  CalcVec3D calcVec3D_;
};

