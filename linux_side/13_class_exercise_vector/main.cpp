#include "vector2d.h"
#include "vector3d.h"

using namespace std;

int main()
{
	// arbitrary 2D Points
	Point2D ptCalc2D;
	Point2D ptA2D(0.0, 5.0);
	Point2D ptB2D(2.0, 4.0);	
	Point2D ptC2D(-2.0, -4.0);
	Point2D ptD2D(-5.0, -3.0);		

	// calculating 2D distance
	double dDist2DAB = ptCalc2D.CalcDistBtwPt2D(ptA2D.GetPt2D(), ptB2D.GetPt2D());
	double dDist2DCD = ptCalc2D.CalcDistBtwPt2D(ptC2D.GetPt2D(), ptD2D.GetPt2D());	

	// arbitrary 2D vector
	Vector2D vecCalc2D;
	Vector2D vecA2D(ptA2D.GetPt2D(), ptB2D.GetPt2D());
	Vector2D vecB2D(ptC2D.GetPt2D(), ptD2D.GetPt2D());

	// 2D vector calculation
	Vec2D vecAdd2D = vecCalc2D.CalcVecAdd(vecA2D.GetVec2D(), vecB2D.GetVec2D());
	Vec2D vecSub2D = vecCalc2D.CalcVecSub(vecA2D.GetVec2D(), vecB2D.GetVec2D());
	Vec3D vecCross2D = vecCalc2D.CalcVecCrossProd(vecA2D.GetVec2D(), vecB2D.GetVec2D());
	double dVecInnerProd2D = vecCalc2D.CalcVecInnerProd(vecA2D.GetVec2D(), vecB2D.GetVec2D());
	Vec2D vecUnitA2D = vecCalc2D.CalcVecUnit(vecA2D.GetVec2D());
	Vec2D vecUnitB2D = vecCalc2D.CalcVecUnit(vecB2D.GetVec2D());

	// for debugging
	printf("2D::pointA(%.4lf,%.4lf)\n", ptA2D.GetPt2D().dX, ptA2D.GetPt2D().dY);
	printf("2D::pointB(%.4lf,%.4lf)\n", ptB2D.GetPt2D().dX, ptB2D.GetPt2D().dY);
	printf("2D::pointC(%.4lf,%.4lf)\n", ptC2D.GetPt2D().dX, ptC2D.GetPt2D().dY);
	printf("2D::pointD(%.4lf,%.4lf)\n", ptD2D.GetPt2D().dX, ptD2D.GetPt2D().dY);
	printf("\n");
	printf("2D::vecA(%.4lf,%.4lf)\n", vecA2D.GetVec2D().dVecX, vecA2D.GetVec2D().dVecY);
	printf("2D::vecB(%.4lf,%.4lf)\n", vecB2D.GetVec2D().dVecX, vecB2D.GetVec2D().dVecY);
	printf("\n");
	printf("2D::vec::UnitA(%.4lf,%.4lf)\n", vecUnitA2D.dVecX, vecUnitA2D.dVecY);
	printf("2D::vec::UnitB(%.4lf,%.4lf)\n", vecUnitB2D.dVecX, vecUnitB2D.dVecY);	
	printf("\n");
	printf("2D::vec::AddAB(%.4lf,%.4lf)\n", vecAdd2D.dVecX, vecAdd2D.dVecY);
	printf("2D::vec::SubAB(%.4lf,%.4lf)\n", vecSub2D.dVecX, vecSub2D.dVecY);
	printf("2D::vec::InnerProd(%.4lf)\n", dVecInnerProd2D);
	printf("2D::vec::CrossAB(%.4lf,%.4lf,%.4lf)\n", vecCross2D.dVecX, vecCross2D.dVecY, vecCross2D.dVecZ);
	printf("\n\n");	

	// arbitrary 3D Points
	Point3D ptCalc3D;
	Point3D ptA3D(0.0, 5.0, 3.0);
	Point3D ptB3D(2.0, 4.0, 2.0);	
	Point3D ptC3D(-2.0, -4.0, 1.0);
	Point3D ptD3D(-5.0, -3.0, -3.0);		

	// calculating 3D distance
	double dDist3DAB = ptCalc3D.CalcDistBtwPt3D(ptA3D.GetPt3D(), ptB3D.GetPt3D());
	double dDist3DCD = ptCalc3D.CalcDistBtwPt3D(ptC3D.GetPt3D(), ptD3D.GetPt3D());	

	// arbitrary 3D vector
	Vector3D vecCalc3D;
	Vector3D vecA3D(ptA3D.GetPt3D(), ptB3D.GetPt3D());
	Vector3D vecB3D(ptC3D.GetPt3D(), ptD3D.GetPt3D());

	// 3D vector calculation
	Vec3D vecAdd3D = vecCalc3D.CalcVecAdd(vecA3D.GetVec3D(), vecB3D.GetVec3D());
	Vec3D vecSub3D = vecCalc3D.CalcVecSub(vecA3D.GetVec3D(), vecB3D.GetVec3D());
	Vec3D vecCross3D = vecCalc3D.CalcVecCrossProd(vecA3D.GetVec3D(), vecB3D.GetVec3D());
	double dVecInnerProd3D = vecCalc3D.CalcVecInnerProd(vecA3D.GetVec3D(), vecB3D.GetVec3D());
	Vec3D vecUnitA3D = vecCalc3D.CalcVecUnit(vecA3D.GetVec3D());
	Vec3D vecUnitB3D = vecCalc3D.CalcVecUnit(vecB3D.GetVec3D());

		// for debugging
	printf("3D::pointA(%.4lf,%.4lf,%.4lf)\n", ptA3D.GetPt3D().dX, ptA3D.GetPt3D().dY, ptA3D.GetPt3D().dZ);
	printf("3D::pointB(%.4lf,%.4lf,%.4lf)\n", ptB3D.GetPt3D().dX, ptB3D.GetPt3D().dY, ptB3D.GetPt3D().dZ);
	printf("3D::pointC(%.4lf,%.4lf,%.4lf)\n", ptC3D.GetPt3D().dX, ptC3D.GetPt3D().dY, ptC3D.GetPt3D().dZ);
	printf("3D::pointD(%.4lf,%.4lf,%.4lf)\n", ptD3D.GetPt3D().dX, ptD3D.GetPt3D().dY, ptD3D.GetPt3D().dZ);
	printf("\n");
	printf("3D::vecA(%.4lf,%.4lf,%.4lf)\n", vecA3D.GetVec3D().dVecX, vecA3D.GetVec3D().dVecY, vecA3D.GetVec3D().dVecZ);
	printf("3D::vecB(%.4lf,%.4lf,%.4lf)\n", vecB3D.GetVec3D().dVecX, vecB3D.GetVec3D().dVecY, vecB3D.GetVec3D().dVecZ);
	printf("\n");
	printf("3D::vec::UnitA(%.4lf,%.4lf,%.4lf)\n", vecUnitA3D.dVecX, vecUnitA3D.dVecY, vecUnitA3D.dVecZ);
	printf("3D::vec::UnitB(%.4lf,%.4lf,%.4lf)\n", vecUnitB3D.dVecX, vecUnitB3D.dVecY, vecUnitB3D.dVecZ);	
	printf("\n");
	printf("3D::vec::AddAB(%.4lf,%.4lf,%.4lf)\n", vecAdd3D.dVecX, vecAdd3D.dVecY, vecAdd3D.dVecZ);
	printf("3D::vec::SubAB(%.4lf,%.4lf,%.4lf)\n", vecSub3D.dVecX, vecSub3D.dVecY, vecSub3D.dVecZ);
	printf("3D::vec::InnerProd(%.4lf)\n", dVecInnerProd3D);
	printf("3D::vec::CrossAB(%.4lf,%.4lf,%.4lf)\n", vecCross3D.dVecX, vecCross3D.dVecY, vecCross3D.dVecZ);
	printf("\n\n");	

	// pause function (windows: system("pause");)
	getchar();
	return 0;
}