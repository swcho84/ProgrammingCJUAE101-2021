#include <stdio.h>

int get_sum2(int a[], int n)
{
	int i;
	int *p;
	int sum = 0;

	// answer
	// ------------------------------------------//
	p = a;
	for (i = 0; i < n; i++)
		sum += *(p + i);
	// ------------------------------------------//
	
	return sum;
}

int main(void)
{
	int nSize = 0;
	printf("size:\n");
	scanf("%d", &nSize);
	int nArr[nSize] = {0, };

	fflush(stdin); 
	for (int i = 0; i < nSize; i++)
	{
		// nArr[i] = i;
		printf("variable[%d]:\n", i);
		scanf(" %d", &nArr[i]);
	}

	int nA[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int nSumRes = get_sum2(nArr, 10);
	printf("sum:%d\n", nSumRes);

	// pause function (windows: system("pause");)
	getchar();
  return 0;
}
