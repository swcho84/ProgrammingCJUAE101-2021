#include "vector2d.h"

using namespace std;

Vector2D::Vector2D()
{
	
}

Vector2D::Vector2D(Pt2D ptA, Pt2D ptB)
{
	vec2D_.dVecX = ptB.dX - ptA.dX;
	vec2D_.dVecY = ptB.dY - ptA.dY;
}

Vec2D Vector2D::GetVec2D()
{
	return vec2D_;
}

void Vector2D::SetVec2D(Pt2D ptA, Pt2D ptB)
{
	vec2D_.dVecX = ptB.dX - ptA.dX;
	vec2D_.dVecY = ptB.dY - ptA.dY;
}

Vec2D Vector2D::CalcVecAdd(Vec2D vecA, Vec2D vecB)
{
	Vec2D vecRes;
	vecRes.dVecX = vecA.dVecX + vecB.dVecX;
	vecRes.dVecY = vecA.dVecY + vecB.dVecY;	
	return vecRes;
}

Vec2D Vector2D::CalcVecSub(Vec2D vecA, Vec2D vecB)
{
	Vec2D vecRes;
	vecRes.dVecX = vecB.dVecX - vecA.dVecX;
	vecRes.dVecY = vecB.dVecY - vecA.dVecY;	
	return vecRes;
}
double Vector2D::CalcVecInnerProd(Vec2D vecA, Vec2D vecB)
{
	return ((vecA.dVecX)*(vecB.dVecX) + (vecA.dVecY)*(vecB.dVecY));
}

Vec3D Vector2D::CalcVecCrossProd(Vec2D vecA, Vec2D vecB)
{
	Vec3D vecRes;
	vecRes.dVecX = 0.0;
	vecRes.dVecY = 0.0;
	vecRes.dVecZ = ((vecA.dVecX)*(vecB.dVecY)) - ((vecA.dVecY)*(vecB.dVecX));	
	return vecRes;
}

double Vector2D::CalcVecNorm(Vec2D vecInput)
{
	return (sqrt((vecInput.dVecX)*(vecInput.dVecX) + (vecInput.dVecY)*(vecInput.dVecY)));
}

Vec2D Vector2D::CalcVecUnit(Vec2D vecInput)
{
	Vec2D vecRes;
	vecRes.dVecX = (vecInput.dVecX)/(CalcVecNorm(vecInput));
	vecRes.dVecY = (vecInput.dVecY)/(CalcVecNorm(vecInput));	
	return vecRes;
}