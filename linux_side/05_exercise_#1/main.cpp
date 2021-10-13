#include <stdio.h>

// calculating the vector addition
double* Calc2DVecAdd(double *dPvecA, double *dPvecB)
{
	static double dArrVecAdd[2] = {};
	for (unsigned int i = 0; i < 2; i++)
		dArrVecAdd[i] = dPvecA[i] + dPvecB[i];
	return dArrVecAdd;
}

// calculating the vector subtraction
double* Calc2DVecSub(double *dPvecA, double *dPvecB)
{
	static double dArrVecSub[2] = {};
	for (unsigned int i = 0; i < 2; i++)
		dArrVecSub[i] = dPvecA[i] - dPvecB[i];
	return dArrVecSub;
}

// calculating the vector inner product
double Calc2DVecInnerProd(double *dPvecA, double *dPvecB)
{
	static double dArrVecInnerProd = 0.0;
	for (unsigned int i = 0; i < 2; i++)
		dArrVecInnerProd += (dPvecA[i] * dPvecB[i]);
	return dArrVecInnerProd;
}

// calculating the vector cross product
double* Calc2DCrossProd(double *dPvecA, double *dPvecB)
{
	static double dArrVecCrossProd[3] = {};
	dArrVecCrossProd[0] = 0.0;
	dArrVecCrossProd[1] = 0.0;	
	dArrVecCrossProd[2] = ((dPvecA[0]) * (dPvecB[1])) - ((dPvecA[1]) * (dPvecB[0]));		
	return dArrVecCrossProd;
}

// generating the input information
void Gen2DVecInput(double *dInput)
{
	printf("Input two numbers (double):\n");
	scanf("%lf %lf", (dInput), (dInput + 1));
}

// main function
int main(void)
{
	// initializing variables (array and point)
	double dArrVecA[2] = {};
	double dArrVecB[2] = {};
	double *dPvecA = dArrVecA;
	double *dPvecB = dArrVecB;
	
	// generating the input information
	Gen2DVecInput(dPvecA);
	Gen2DVecInput(dPvecB);

	// calculating the vector addition, subtraction, inner product, cross product
	double *dPvecAddAB = Calc2DVecAdd(dPvecA, dPvecB);
	double *dPvecSubAB = Calc2DVecSub(dPvecA, dPvecB);
	double dVecInnerProd = Calc2DVecInnerProd(dPvecA, dPvecB);
	double *dPvecCrossProd = Calc2DCrossProd(dPvecA, dPvecB);

	// for debugging
	printf("\n2D vector calculation result\n");
	printf("VecAdd:(%.4lf, %.4lf)\n", *(dPvecAddAB), *(dPvecAddAB + 1));
	printf("VecSub:(%.4lf, %.4lf)\n", *(dPvecSubAB), *(dPvecSubAB + 1));
	printf("VecInnerProduct:(%.4lf)\n", dVecInnerProd);
	printf("VecCrossProduct:(%.4lf, %.4lf, %.4lf)\n", *(dPvecCrossProd), *(dPvecCrossProd + 1), *(dPvecCrossProd + 2));

  // end of program..
  printf("\nEnd of the program..\n");

	// pause function (windows: system("pause");
	getchar();	
  return 0;
}