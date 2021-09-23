#include <stdio.h>

int main(void)
{
  // initializing variables
  double dWeight = 0.0;
  double dHeightCm = 0.0;
  double dBmi = 0.0;

  // interaction: getting some information related to the problem
  printf("Need to enter data(order: weight[kg] and height[cm]):\n");
  scanf("%lf%lf", &dWeight, &dHeightCm);

  // calculating the mbti information
	double dHeightM = dHeightCm * 0.01;
  dBmi = (dWeight) / ((dHeightM) * (dHeightM));

  // using if-else
	if ((dBmi < 20.0) && (dBmi >= 25.0))
	{
		printf("MBTI result: %lf, You need to manage your weight\n", dBmi);
	}
	else 
	{
		printf("MBTI result: %lf, You have the standard weight status\n", dBmi);
	}

  // end of program..
  printf("End of the program..\n");
  return 0;
}