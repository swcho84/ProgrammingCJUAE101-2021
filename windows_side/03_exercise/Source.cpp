
#include <stdio.h>
#include <stdlib.h>

#define BMIN printf("ǥ���Դϴ�!\n")

int main(void)
{
  double weight, height, BMI;

  printf("������(kg)�� Ű(cm) �Է� : ");
  scanf_s("%lf %lf", &weight, &height);

  printf("������%lf Ű%lf \n", weight, height);

  height = (height / 100.0);
  BMI = weight / (height * height);

  printf("%lf\n", BMI);

  if ((BMI >= 20) && (BMI < 25)) {
	BMIN;
  }
  else {
	printf("ü�߰����� �ʿ��մϴ�!\n");
  }

  system("pause");

  return 0;

}