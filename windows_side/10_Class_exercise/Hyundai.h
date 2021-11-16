#pragma once
#include "Car.h"

using namespace std;

// derived class, hyundai
class Hyundai : public Car
{
public:
  Hyundai(string strCarName, int nNumInput, double dGasInput);
  void CurrSumStatus();
};

