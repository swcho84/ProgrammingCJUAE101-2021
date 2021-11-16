#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include "RandNum.h"
#include "structure.h"

using namespace std;

class VectorExample : public RandNum
{
public:
  VectorExample();
  ~VectorExample();

public:
  void MainLoop();

private:
  vector<PtDThrD> GenVecThrD(int nRange, int nSize);
  vector<PtDTwoD> GenVecTwoD(int nRange, int nSize);

  vector<int> GenVecInteger(int nRange, int nSize);
  vector<float> GenVecFloat(int nRange, int nSize);
  vector<double> GenVecDouble (int nRange, int nSize);

  void PrintVec(vector<PtDThrD>& vec);
  void PrintVec(vector<PtDTwoD>& vec);
  void PrintVec(vector<int>& vec);
  void PrintVec(vector<float>& vec);
  void PrintVec(vector<double>& vec);
};

