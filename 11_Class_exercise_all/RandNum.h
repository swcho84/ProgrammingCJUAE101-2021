#pragma once
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <random>

using namespace std;

class RandNum
{
public:
  void GenRandSeed();
  int GenRandIntNum(int nRange);
  float GenRandFloatNum(int nRange);
  double GenRandDoubleNum(int nRange);

private:
  default_random_engine generator_;
};

