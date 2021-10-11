#include <stdio.h>
#include <math.h>

#define IS_PRIME	0
#define ISNOT_PRIME 1
#define NUM_IN_LINE	5

int main(void)
{
	// initializing variables
  int nNumRange = 0;
  int nIsPrime = 0;
  int nPrtPrint = 0;

	// generating the input information
	printf("Input a single number (integer, condition: A > 2):\n");
  scanf("%d", &nNumRange);
	printf("\n");

	// exceptional handling
	if (nNumRange <= 2)
	{
		printf("please check the input status..\n");
		return 0;
	}

	// calculating and printing the prime number 
  for (int i = 2; i <= nNumRange; i++)
  {
		// initializing the prime number calculation result 
		nIsPrime = IS_PRIME;

		// calculation the prime number status by the definition
		for (int j = 2; j < i; j++)
		{
			if ((i % j) == 0)
			{
				nIsPrime = ISNOT_PRIME;    
				break;
			}
		}
		
		// printing results
		if (nIsPrime == IS_PRIME)    
		{
			// making the pretty printing result
			printf("%5d ", i);
			nPrtPrint++;

			if ((nPrtPrint % NUM_IN_LINE) == 0)
				printf("\n");
		}
  }

  // end of program..
  printf("\nEnd of the program..\n");

	// pause function (windows: system("pause");
	getchar();	
  return 0;
}