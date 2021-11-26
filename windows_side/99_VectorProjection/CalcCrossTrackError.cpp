#include "CalcCrossTrackError.h"

using namespace std;

double CalcCrossTrackError::CalcCrsTrkErr(Vec3D vecA2)
{
  return calcVec3D_.CalcVec3DNorm(vecA2);
}

Vec3D CalcCrossTrackError::CalcA2(Vec3D vecUnitLine, Vec3D vecA)
{
  Vec3D vecResA2;
  vecResA2.dI = vecA.dI - (calcVec3D_.CalcVec3DInnerProd(vecA, vecUnitLine)) * (vecUnitLine.dI);
  vecResA2.dJ = vecA.dJ - (calcVec3D_.CalcVec3DInnerProd(vecA, vecUnitLine)) * (vecUnitLine.dJ);
  vecResA2.dK = vecA.dK - (calcVec3D_.CalcVec3DInnerProd(vecA, vecUnitLine)) * (vecUnitLine.dK);
  return vecResA2;
}