#include <stdio.h>

int main(void)
{
	// initializing variables
  double dNumX = 0.0;
	double dNumY = 0.0;

	// generating the input information
  printf("Input the 2D coordinate, just one case (double, (x,y)):\n");
  scanf("%lf %lf", &dNumX, &dNumY);
  
	// using if-else for solving the given problem
	if ((dNumX > 0.0) && (dNumY > 0.0))
  {
		// I-quadrant
		printf("Result: first quadrant\n");
  }
  else if ((dNumX < 0.0) && (dNumY > 0.0))
  {
		// II-quadrant
		printf("Result: second quadrant\n");
  }
  else if ((dNumX < 0.0) && (dNumY < 0.0))
  {
		// III-quadrant
		printf("Result: third quadrant\n");
  }
  else if ((dNumX > 0.0) && (dNumY < 0.0))
  {
		// IV-quadrant
		printf("Result: fourth quadrant\n");
  }
  else
  {
		// handling the exception status
		printf("Result: origin\n");
  }

  // end of program..
  printf("\nEnd of the program..\n");	
  return 0;
}