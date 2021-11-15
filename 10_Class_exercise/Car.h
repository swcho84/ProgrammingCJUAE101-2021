#pragma once
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// abstracted class, car
class Car
{
public:
  Car();
  Car(int nNum, double dGas);

public:
  static int nSumCarClass;
  void CurrShow();
  static void CurrSumShow();
  int GetCarNum();
  double GetCarGas();
  void SetCarNum(int nNumInput);
  void SetCarGas(double dGasInput);

private:
  int nNum_;
  double dGas_;
};

