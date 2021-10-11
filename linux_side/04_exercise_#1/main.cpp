#include <stdio.h>

// calculating the factorial loop 
int CalcFactorLoop(int nInput)
{
  int nRes = 1;

	for (int i = 1; i <= nInput; i++)
		nRes *= i;
  
	return nRes;
}

// calculating the binomial coefficient, using the factorial loop 
int CalcBinomialCoeffLoop(int nN, int nK)
{
	return (CalcFactorLoop(nN))/(CalcFactorLoop(nK) * CalcFactorLoop(nN - nK));
}

// calculating the binomial coefficient, using the recursive function
int CalcFactorialRecursive(int nN, int nK)
{
  if ((nK == 0) || (nK == nN))
		return 1;
  else
		return CalcFactorialRecursive(nN - 1, nK - 1) + CalcFactorialRecursive(nN - 1, nK);
}

// main function
int main(void)
{
	// initializing variables
	int nN = 0;
	int nK = 0;
	
	// generating the input information
	printf("Input two numbers (integer, n > k > 0):\n");
	scanf("%d %d", &nN, &nK);

	// exceptional handling
	if (((nN < 0) || (nK < 0)) || (nN < nK))
	{
		printf("Please check the your input status...\n");
		return 1;
	}

	// calculating the binomial coefficient, for-loop
	int nResForLoop = CalcBinomialCoeffLoop(nN, nK);

	// calculating the binomial coefficient, recursive function
	int nResRecur = CalcFactorialRecursive(nN, nK);

	// for debugging
	printf("BinomialCoeff(for-loop, recursive):(%d, %d)\n", nResForLoop, nResRecur);

  // end of program..
  printf("\nEnd of the program..\n");

	// pause function (windows: system("pause");
	getchar();	
  return 0;
}