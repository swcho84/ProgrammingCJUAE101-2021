#include "Hyundai.h"

using namespace std;

// making the hundai motors car
Hyundai::Hyundai(string strCarName, int nNumInput, double dGasInput) 
{
  // setting the number and gas status
  this->SetCarNum(nNumInput);
  this->SetCarGas(dGasInput);

  // for debugging
  printf("Hyundai::%s has been built..::specific(nNum:%d,dGas:%.4lf)\n\n", strCarName.c_str(),
	this->GetCarNum(), this->GetCarGas());
}

// checking the summation status
void Hyundai::CurrSumStatus()
{
  return this->CurrSumShow();
}