#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

// reversing the string input and saving the result
void CalcNumAlphabetInfo(char* strInput, int nStrLength, char* strOutput)
{
	for(unsigned int i = 0; i < nStrLength; i++)
		*(strOutput + i) = strInput[nStrLength - 1 - i];
}

// main function
int main(void)
{
	// initializing variables
	char strInput[300];
	int nStrLength;

	// generating the input information
	// in linux, gets/gets_s are deprecated function case of the security issues
	// "%[^\n]s": including the spacebar
	printf("Input your string information:\n");
	scanf("%[^\n]s", strInput);
	nStrLength = strlen(strInput); 

	// reversing the string input
	char* strRevInput = (char*)(malloc(sizeof(char) * (nStrLength + 1)));
	CalcNumAlphabetInfo(strInput, nStrLength, strRevInput);

	// for debugging
	printf("Reverse::%s\n", strRevInput);

	// pause function (windows: system("pause");)
	getchar();
  return 0;
}
