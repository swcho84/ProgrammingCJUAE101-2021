#include "vector3d.h"

using namespace std;

Vector3D::Vector3D()
{
	
}

Vector3D::Vector3D(Pt3D ptA, Pt3D ptB)
{
	vec3D_.dVecX = ptB.dX - ptA.dX;
	vec3D_.dVecY = ptB.dY - ptA.dY;
	vec3D_.dVecZ = ptB.dZ - ptA.dZ;	
}

Vec3D Vector3D::GetVec3D()
{
	return vec3D_;
}

void Vector3D::SetVec3D(Pt3D ptA, Pt3D ptB)
{
	vec3D_.dVecX = ptB.dX - ptA.dX;
	vec3D_.dVecY = ptB.dY - ptA.dY;
	vec3D_.dVecZ = ptB.dZ - ptA.dZ;	
}

Vec3D Vector3D::CalcVecAdd(Vec3D vecA, Vec3D vecB)
{
	Vec3D vecRes;
	vecRes.dVecX = vecA.dVecX + vecB.dVecX;
	vecRes.dVecY = vecA.dVecY + vecB.dVecY;	
	vecRes.dVecZ = vecA.dVecZ + vecB.dVecZ;	
	return vecRes;
}

Vec3D Vector3D::CalcVecSub(Vec3D vecA, Vec3D vecB)
{
	Vec3D vecRes;
	vecRes.dVecX = vecB.dVecX - vecA.dVecX;
	vecRes.dVecY = vecB.dVecY - vecA.dVecY;	
	vecRes.dVecZ = vecB.dVecZ - vecA.dVecZ;	
	return vecRes;
}
double Vector3D::CalcVecInnerProd(Vec3D vecA, Vec3D vecB)
{
	return ((vecA.dVecX)*(vecB.dVecX) + (vecA.dVecY)*(vecB.dVecY) + (vecA.dVecZ)*(vecB.dVecZ));
}

Vec3D Vector3D::CalcVecCrossProd(Vec3D vecA, Vec3D vecB)
{
	Vec3D vecRes;
	vecRes.dVecX = ((vecA.dVecY)*(vecB.dVecZ)) - ((vecA.dVecZ)*(vecB.dVecY));
	vecRes.dVecY = ((vecA.dVecZ)*(vecB.dVecX)) - ((vecA.dVecX)*(vecB.dVecZ));
	vecRes.dVecZ = ((vecA.dVecX)*(vecB.dVecY)) - ((vecA.dVecY)*(vecB.dVecX));	
	return vecRes;
}

double Vector3D::CalcVecNorm(Vec3D vecInput)
{
	return (sqrt((vecInput.dVecX)*(vecInput.dVecX) + (vecInput.dVecY)*(vecInput.dVecY) + (vecInput.dVecZ)*(vecInput.dVecZ)));
}

Vec3D Vector3D::CalcVecUnit(Vec3D vecInput)
{
	Vec3D vecRes;
	vecRes.dVecX = (vecInput.dVecX)/(CalcVecNorm(vecInput));
	vecRes.dVecY = (vecInput.dVecY)/(CalcVecNorm(vecInput));	
	vecRes.dVecZ = (vecInput.dVecZ)/(CalcVecNorm(vecInput));	
	return vecRes;
}