#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define MAXSIZE 50

int main(void)
{
	// assigning variables
	int nSize = 0;
	float x[MAXSIZE] = {}, y[MAXSIZE] = {};	
	float fSumX = 0, fSumX2 = 0, fSumY = 0, fSumXY = 0;
	float fSlope = 0, fBias = 0;

	// assigning data size
	printf("How many data points?\n");
	scanf("%d", &nSize);

	// interaction
	printf("Enter data:\n");
	for(int i = 1; i <= nSize; i++)
	{
		printf("x[%d] = ", i);
		scanf("%f", &x[i]);
		printf("y[%d]=",i);
		scanf("%f", &y[i]);
	}

	// calculating the equation terms
	for(int i = 1; i <= nSize; i++)
	{
		fSumX += x[i];
		fSumX2 += x[i]*x[i];
		fSumY += y[i];
		fSumXY += x[i]*y[i];
	}

	// calculating the slope and bias, analytical linear regression
	fBias = ((float)(nSize) * (fSumXY) - (fSumX) * (fSumY))/((float)(nSize) * (fSumX2) - (fSumX) * (fSumX));
	fSlope = (fSumY - ((fBias) * (fSumX)))/((float)(nSize));
	
	// for debugging
	printf("Values are: slope = %.4f and bias = %.4f\n", fSlope, fBias);
	printf("Equation of best fit is: y = %.4f + %.4fx\n", fSlope, fBias);

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}

