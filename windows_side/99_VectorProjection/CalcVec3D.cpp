#include "CalcVec3D.h"

using namespace std;

CalcVec3D::CalcVec3D()
{

}

Vec3D CalcVec3D::CalcVecFromPts(Pt3D ptA, Pt3D ptB)
{
  Vec3D vecRes;
  vecRes.dI = ptA.dX - ptB.dX;
  vecRes.dJ = ptA.dY - ptB.dY;
  vecRes.dK = ptA.dZ - ptB.dZ;
  return vecRes;
}

double CalcVec3D::CalcVec3DNorm(Vec3D vecA)
{
  double dNormRes;
  dNormRes = sqrt(((vecA.dI) * (vecA.dI)) + 
	              ((vecA.dJ) * (vecA.dJ)) + 
	              ((vecA.dK) * (vecA.dK)));
  return dNormRes;
}

double CalcVec3D::CalcVec3DInnerProd(Vec3D vecA, Vec3D vecB)
{
  double dInnerProdRes;
  dInnerProdRes = ((vecA.dI) * (vecB.dI)) +
			   	  ((vecA.dJ) * (vecB.dJ)) +
				  ((vecA.dK) * (vecB.dK));
  return dInnerProdRes;
}

//Vec3D CalcVec3D::CalcVec3DCrossProd(Vec3D vecA, Vec3D vecB)
//{
//  Vec3D vecCrossProdRes;
//
//  return vecCrossProdRes;
//}

Vec3D CalcVec3D::CalcVec3DAdd(Vec3D vecA, Vec3D vecB)
{
  Vec3D vecAddRes;
  vecAddRes.dI = vecA.dI + vecB.dI;
  vecAddRes.dJ = vecA.dJ + vecB.dJ;
  vecAddRes.dK = vecA.dK + vecB.dK;
  return vecAddRes;
}

Vec3D CalcVec3D::CalcVec3DSub(Vec3D vecA, Vec3D vecB)
{
  Vec3D vecSubRes;
  vecSubRes.dI = vecA.dI - vecB.dI;
  vecSubRes.dJ = vecA.dJ - vecB.dJ;
  vecSubRes.dK = vecA.dK - vecB.dK;
  return vecSubRes;
}

Vec3D CalcVec3D::CalcVec3DUnit(Vec3D vecA)
{
  Vec3D vecUnitRes;
  double dNorm = CalcVec3DNorm(vecA);
  vecUnitRes.dI = (vecA.dI) / (dNorm);
  vecUnitRes.dJ = (vecA.dJ) / (dNorm);
  vecUnitRes.dK = (vecA.dK) / (dNorm);
  return vecUnitRes;
}