#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double CalcEuclideanDistance(double x1, double y1, double x2, double y2)
{
  return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int main(void)
{
  // initializing variables  
  double dX1, dY1 = 0.0;
  double dX2, dY2 = 0.0;

	// generating the input information
  printf("Need to enter data(1st point, (X1, Y1)): ");
  scanf("%lf%lf", &dX1, &dY1);
  printf("Need to enter data(2nd point, (X2, Y2)): ");
  scanf("%lf%lf", &dX2, &dY2);
  printf("\n");
  printf("Your raw input(X1, Y1): (%.4lf, %.4lf)\n", dX1, dY1);
  printf("Your raw input(X2, Y2): (%.4lf, %.4lf)\n", dX2, dY2);

  // calculating the Euclidean distance
  printf("Output, Euclidean Distance: %.4lf\n", CalcEuclideanDistance(dX1, dY1, dX2, dY2));

  // end of program..
  printf("\nEnd of the program..\n");

	// pause function (windows: system("pause");
	getchar();	
  return 0;
}