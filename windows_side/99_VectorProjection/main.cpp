#include "CalcCrossTrackError.h"
#include "Point.h"

using namespace std;

int main()
{
  // input
  Point ptA3D(-4.0, 0.0, 0.0);
  Point ptB3D(0.0, 2.0, 0.0);
  Point ptC3D(5.0, -2.0, 0.0);

  // calculation
  CalcVec3D lineInfo;
  Vec3D vecLine = lineInfo.CalcVecFromPts(ptA3D.GetPoint(), ptB3D.GetPoint());
  Vec3D vecUnitLine = lineInfo.CalcVec3DUnit(vecLine);
  Vec3D vecA = lineInfo.CalcVecFromPts(ptB3D.GetPoint(), ptC3D.GetPoint());
  
  CalcCrossTrackError calcCrsTrkErr;
  Vec3D vecA2 = calcCrsTrkErr.CalcA2(vecUnitLine, vecA);
  double dCrsTrkErr = calcCrsTrkErr.CalcCrsTrkErr(vecA2);

  // for debugging
  printf("dCrsTrkErr:%.4lf\n", dCrsTrkErr);

  return 0;
}