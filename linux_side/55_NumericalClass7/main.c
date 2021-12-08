#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define LearningRate		0.0001

// define the target function, for the toy problem
double func(double x)
{
	// easy equation
	// return ((x + 4) * (x + 4));

	// hard equation
	return (x*log(x) - sqrt(x));
}

// define the df/dx function, analytic solution
double dfdx(double x)
{
	// easy equation
	// return ((2.0) * (x + 4));

	// hard equation
	return (log(x) + 1.0 - (1.0)/(2.0 * sqrt(x)));
}

// generating the seed number using the time clock information
void GenRandSeed()
{
  // generating the random number using the time seed
  srand((unsigned int)(time(NULL)));
  return;
}

// generating the random number, integer type
int GenRandIntNum(int nRange)
{
  int nRes = 0;
  int nNum = rand();
  nRes = ((int)(nNum) % (nRange));
  return nRes;
}

// generating the random number, double type
double GenRandDoubleNum()
{
  int nRes = GenRandIntNum(9);
  double dRes = ((double)(nRes)) + (((double)(GenRandIntNum(RAND_MAX)))/RAND_MAX);
  return dRes;
}

int main(void)
{
  // generating the seed number using the time clock information
  GenRandSeed();

	// setting the initial value, for easy equation
	double dXCurrState = (50.0) - (GenRandDoubleNum()) * (50.0);

	// setting the initial value, for hard equation, only x > 0
	// double dXCurrState = (10.0) * GenRandDoubleNum();

	// calculating the minimum state using Gradient descent method
	double dErrorState = RAND_MAX;
	double dXPrevState = 0;
	int nCounter = 0;
	while (dErrorState > 10e-5)
	{
		// calculating the analytical gradient descent
		dXCurrState = dXCurrState - (LearningRate) * (dfdx(dXCurrState));
		dErrorState = fabs(dfdx(dXCurrState));

		// for debugging
		printf("[%d](xcurr, xprev, f(x), error):(%.4lf,%.4lf,%.4lf,%.4lf)\n", nCounter, dXCurrState, dXPrevState, func(dXCurrState), dErrorState);
		dXPrevState = dXCurrState;		
		nCounter++;
	}

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}