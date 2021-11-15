
#include <stdio.h>
#include <stdlib.h>

#define BMIN printf("표준입니다!\n")

int main(void)
{
  double weight, height, BMI;

  printf("몸무게(kg)와 키(cm) 입력 : ");
  scanf_s("%lf %lf", &weight, &height);

  printf("몸무게%lf 키%lf \n", weight, height);

  height = (height / 100.0);
  BMI = weight / (height * height);

  printf("%lf\n", BMI);

  if ((BMI >= 20) && (BMI < 25)) {
	BMIN;
  }
  else {
	printf("체중관리가 필요합니다!\n");
  }

  system("pause");

  return 0;

}