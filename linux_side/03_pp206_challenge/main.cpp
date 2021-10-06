#include <stdio.h>

// recursive function, n to NumRange
int recFunc(int nStart, int nRange)
{
  if (nStart == nRange)
    return nRange;

	return nStart + recFunc((nStart + 1), nRange);
}

int main(void)
{
	// initializing variables
	int nBegin = 0;
	int nRange = 1;

	// generating the input information
	printf("Input two numbers (integer, condition: A < B):\n");
  scanf("%d %d", &nBegin, &nRange);
	printf("\n");

	// exceptional handling
	if (nBegin > nRange)
	{
		printf("please check the input status..\n");
		return 0;
	}	

	// for debugging
	printf("Summation numBegin to nunRange by scanf:\n");
	printf("%d\n", recFunc(nBegin, nRange));

  // end of program..
  printf("\nEnd of the program..\n");

	// pause function (windows: system("pause");
	getchar();	
  return 0;
}