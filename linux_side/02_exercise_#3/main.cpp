#include <stdio.h>

int main(void)
{
	// initializing variables
  int nNumMonth = 0;

	// generating the input information
	printf("Input the number related to the month in the calendar (i.e. 1-12):\n");
  scanf("%d",& nNumMonth);

	// using switch-case for solving the given problem
  switch(nNumMonth)
  {
		case 1:
		{
			printf("Result: January, Jan.\n");
			break;
		}
		case 2:
		{
			printf("Result: February, Feb.\n");
			break;
		}
		case 3:
		{
			printf("Result: March, Mar.\n");
			break;
		}
		case 4:
		{
			printf("Result: April, Apr.\n");
			break;
		}
		case 5:
		{
			printf("Result: May\n");
			break;
		}
		case 6:
		{
			printf("Result: June, Jun.\n");
			break;
		}
		case 7:
		{
			printf("Result: July, Jul.\n");
			break;
		}
		case 8:
		{
			printf("Result: August, Aug.\n");
			break;
		}
		case 9:
		{
			printf("Result: September, Sep.\n");
			break;
		}
		case 10:
		{
			printf("Result: October, Oct.\n");
			break;
		}
		case 11:
		{
			printf("Result: November, Nov.\n");
			break;
		}
		case 12:
		{
			printf("Result: December, Dec.\n");
			break;
		}
		default:
		{
			// handling the exception status
			printf("please check the input condition..\n");
		}
  }

  // end of program..
  printf("\nEnd of the program..\n");
	return 0;
}