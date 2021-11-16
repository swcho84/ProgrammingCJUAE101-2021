#pragma once
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include "RandNum.h"
#include "structure.h"

using namespace std;

class SortExample : public RandNum
{
public:
  SortExample();
  ~SortExample();

public:
  void MainLoop();

private:
  tuple<vector<PtDTwoD>, vector<PtDThrD>> GetPoints(int nRange, int nSize);
  vector<PtDThrD> GenVecThrD(int nRange, int nSize);
  vector<PtDTwoD> GenVecTwoD(int nRange, int nSize);
  void PrintVec(vector<PtDThrD>& vec);
  void PrintVec(vector<PtDTwoD>& vec);

private:
  static bool Sort2DX(const PtDTwoD& a, const PtDTwoD& b);
  static bool Sort3DZ(const PtDThrD& a, const PtDThrD& b);
};

