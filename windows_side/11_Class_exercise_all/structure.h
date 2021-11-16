#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;

typedef struct
{
  double dX;
  double dY;
} PtDTwoD;

typedef struct
{
  double dX;
  double dY;
  double dZ;
} PtDThrD;

typedef struct
{
  PtDTwoD ptCen;
  double dR;
} Circle;

typedef struct
{
  PtDTwoD ptLt;
  PtDTwoD ptRb;
  double dWidth;
  double dHeight;
} RectAngle;

typedef struct
{
  PtDTwoD pt1;
  PtDTwoD pt2;
  PtDTwoD pt3;
} TriAngle;