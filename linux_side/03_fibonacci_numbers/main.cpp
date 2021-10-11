#include <stdio.h>
#include <limits.h>
#include <math.h>

int main(void)
{
	// initializing variables
	int nNumRange = 0;
	int nNumNextFib = 0;
	int nNumFib = 0;
	int nNumIncrease = 1;

	// generating the input information
	printf("Input a single number (integer, condition: A > 0):\n");
  scanf("%d", &nNumRange);
	printf("\n");

	// exceptional handling
	if (nNumRange < 0)
	{
		printf("please check the input status..\n");
		return 0;		
	}

	// calculating the fibonacci numbers
	for (int i = 1; i <= nNumRange; i++)
	{
		// for debugging
		printf("%d\n", nNumFib);

		// calculating the fibonacci number
		nNumNextFib = nNumFib + nNumIncrease; 

		// swapping the number status
		nNumFib = nNumIncrease;
		nNumIncrease = nNumNextFib;
		printf("[debug](nNumFib,nNumIncrease)=(%d,%d)\n\n", nNumFib, nNumIncrease);

		// preventing the overflow (assumption: nNumNextFib > 0)
		if ((nNumFib > (INT_MAX - nNumIncrease)))
		{
			printf("maximum unsigned inteager..\n");
			break;
		}
	}	

  // end of program..
  printf("\nEnd of the program..\n");

	// pause function (windows: system("pause");
	getchar();	
  return 0;
}