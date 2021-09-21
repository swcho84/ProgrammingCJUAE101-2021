#include <stdio.h>

int main(void)
{
	// assigning the character variable
	char chA;
	
	// for debugging
	printf("Input Character:\n");

	// input the character using scanf
	scanf("%c", &chA);

	// show the result, character and its ascii code
	printf("your input is %c and its ascii code is %d\n", chA, chA);

	// pause function (windows: system("pause");
	getchar();
  return 0;
}