#include <stdio.h>

int main(void)
{
	// initializing variables
  int nNumA = 0;
	int nNumB = 0;

	// generating the input information
  printf("Input two numbers, number A and B(integer, condition: A > B):\n");
  scanf("%d %d", &nNumA, &nNumB);

	// using if-else for solving the given problem
	if (nNumA > nNumB)
	{
		// checking the factor status
		if ((nNumA % nNumB) == 0)
		{
			// for debugging
			printf("Number B is a factor of number A.\n");
		}
		else 
		{
			// for debugging
			printf("Number B is NOT a factor of number A.\n");
		}
	}
  else
  {
		// handling the exception status
		printf("Please check the input condition...\n");
  }

  // end of program..
  printf("\nEnd of the program..\n");
  return 0;
}