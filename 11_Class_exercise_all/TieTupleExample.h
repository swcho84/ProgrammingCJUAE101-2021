#pragma once
#include <stdio.h>
#include <iostream>
#include <tuple>
#include "RandNum.h"
#include "structure.h"

using namespace std;

class TieTupleExample : public RandNum
{
public:
  TieTupleExample();
  ~TieTupleExample();

public:
  void MainLoop();

private:
  tuple<vector<PtDTwoD>, vector<PtDThrD>> GetPoints(int nRange, int nSize);
  vector<PtDThrD> GenVecThrD(int nRange, int nSize);
  vector<PtDTwoD> GenVecTwoD(int nRange, int nSize);
  void PrintVec(vector<PtDThrD>& vec);
  void PrintVec(vector<PtDTwoD>& vec);
};

