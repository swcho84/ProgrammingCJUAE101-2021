#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define END_COND 999

// generating the seed number using the time clock information
void GenRandSeed()
{
  // generating the random number using the time seed
  srand((unsigned int)(time(NULL)));
  return;
}

// generating the random number
unsigned int GenRandNum(unsigned int nRange)
{
  unsigned int nRes = 0;
  unsigned int nNum = rand();
  nRes = ((unsigned int)(nNum) % (nRange));
  return nRes;
}

int main(void)
{
  // assigning seed
  GenRandSeed();

	// initializing variables
	int nRange = 0;

	while (true)
	{
		// generating the input information
		printf("Input a single number, for generating the random number related to your input:\n");
		printf("if you want to end the loop, please input 999\n");
		scanf("%d", &nRange);

		// escaping the while loop
		if (nRange == END_COND)
		{
			printf("end of the infinite while loop...\n");
			break;
		}
		else 
		{
			// generating the random number
			int nRes = GenRandNum(nRange);

			// for debugging
			printf("Result:random number generator, %d\n\n", nRes);
		}
	}

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}