#include <stdio.h>

// calculating the lcm and gcd info. 
void CalcLcmGcd(int x, int y, int *pLcm, int *pGcd)
{
	// 1. using while loop
	// // initializing variables for calculating the gcd info.
	// int nTempSwap = 0;
	// int nTempX = x;
	// int nTempY = y;
	
	// // recursive calculation for gcd info.
	// while(nTempY != 0)
	// {
	// 	nTempSwap = nTempY;
	// 	nTempY = nTempX % nTempY;
	// 	nTempX = nTempSwap;
	// }

	// calculating the lcm and gcd info.
	// *pGcd = nTempX;
	// *pLcm = (x * y) / (*pGcd);	  // lcm calculation	

	// 2. using for loop
	// perform the maximum iteration, with respec to the number between x and y
	for (unsigned int i = 1; ((i <= x) && (i <= y)); ++i) 
	{
		if ((x % i == 0) && (y % i == 0))
			*pGcd = i;   // maximum iter = gcd
	}	
	*pLcm = (x * y) / (*pGcd); // lcm calculation	
}

// main function
int main(void)
{
	// initializing variables
	int nX, nY = 0;
	int nLcm, nGcd = 0;
	int *nPlcm = &nLcm;
	int *nPgcd = &nGcd;
	
	// generating the input information
	printf("Input two numbers (integer):\n");
	scanf("%d %d", &nX, &nY);	

	// calculating the largest common multiple and the greatest common divisor
	CalcLcmGcd(nX, nY, nPlcm, nPgcd);

	// for debugging
	printf("\nResult:(x,y)=(%d,%d)-->(lcm,gcd)=(%d,%d)\n", nX, nY, *nPlcm, *nPgcd);

  // end of program..
  printf("\nEnd of the program..\n");

	// pause function (windows: system("pause");
	getchar();	
  return 0;
}