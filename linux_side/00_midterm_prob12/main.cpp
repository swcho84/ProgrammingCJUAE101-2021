#include <stdio.h>
#include <math.h>

#define IS_PRIME	0
#define ISNOT_PRIME 1
#define NUM_IN_LINE	5

int main(void)
{
	// initializing variables
  int nNumRange = 10;
  int nIsPrime = 0;

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

		if (nIsPrime == IS_PRIME)
			printf("%d\n", i);
  }

  return 0;
}