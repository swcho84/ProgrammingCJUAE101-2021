#include <stdio.h>

int main(void)
{
	// initializing variables
  int nNumA = 0;    
  int nNumB = 0;    
  int nRes = 0;
  char chArithOper;

	// generating the input information
  printf("Input the arithmetic operation using two integer numbers(e.g. a (+, -, *, /) b):\n");
  scanf("%d %c %d", &nNumA, &chArithOper, &nNumB);

	// using switch-case with the ASCII code for solving the given problem
  switch (chArithOper)
  {
		case '+':
		{
			// addition
			nRes = nNumA + nNumB;
			break;
		}
		case '-':
		{
			// subtraction
			nRes = nNumA - nNumB;
			break;
		}
		case '*':
		{
			// multiplication
			nRes = nNumA * nNumB;
			break;
		}
		case '/':
		{
			// division
			nRes = nNumA / nNumB;
			break;
		}
		default:
		{
			// handling the exception status
			printf("please check the (+, -, *, /) option..\n");
			break;
		}
  }

	// for debugging
  printf("result: %d %c %d = %d\n", nNumA, chArithOper, nNumB, nRes);

  // end of program..
  printf("\nEnd of the program..\n");

	// pause function (windows: system("pause");
	getchar();	
  return 0;
}