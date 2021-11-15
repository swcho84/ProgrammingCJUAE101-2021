#include "Car.h"

using namespace std;

// initializing the static variable
int Car::nSumCarClass = 0;

// class constructor, no input
Car::Car()
{
  // initializing class variables
  nNum_ = 0;
  dGas_ = 0.0;
  nSumCarClass++;

  // for debugging
  printf("CarClass has been built..::default\n");
}

// class constructor, with input
Car::Car(int nNumInput, double dGasInput)
{
  // initializing class variables
  nNum_ = nNumInput;
  dGas_ = dGasInput;
  nSumCarClass++;

  // for debugging
  printf("CarClass has been built..::specific(nNum:%d,dGas:%.4lf)\n\n", nNum_, dGas_);
}

// checking the car class status
void Car::CurrShow()
{
  printf("Car::(num,gas)=(%d,%.4lf)\n", nNum_, dGas_);
}

// checking the car class summation status
void Car::CurrSumShow()
{
  printf("CurrSumCar=(%d)\n", nSumCarClass);
}

// getting the car number variable
int Car::GetCarNum()
{
  return nNum_;
}

// getting the car number variable
double Car::GetCarGas()
{
  return dGas_;
}

// setting the car number variable
void Car::SetCarNum(int nNumInput)
{
  nNum_ = nNumInput;
}

// setting the car gas variable
void Car::SetCarGas(double dGasInput)
{
  dGas_ = dGasInput;
}
