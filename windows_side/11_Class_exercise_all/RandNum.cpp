#include "RandNum.h"

using namespace std;

// generating the seed number using the time clock information
void RandNum::GenRandSeed()
{
  // generating the random number using the time seed
  srand((unsigned int)(time(NULL)));
  return;
}

// generating the random number, integer type
int RandNum::GenRandIntNum(int nRange)
{
  int nRes = 0;
  int nNum = rand();
  nRes = ((int)(nNum) % (nRange)) + 1;
  return nRes;
}

// generating the random number, float type
float RandNum::GenRandFloatNum(int nRange)
{
  uniform_real_distribution<float> distribution(0.0, 1.0);
  return ((float)(GenRandIntNum(nRange)) + (distribution(generator_)));
}

// generating the random number, double type
double RandNum::GenRandDoubleNum(int nRange)
{
  uniform_real_distribution<double> distribution(0.0, 1.0);
  return ((double)(GenRandIntNum(nRange)) + (distribution(generator_)));
}