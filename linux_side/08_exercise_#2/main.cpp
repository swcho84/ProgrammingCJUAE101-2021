#include <stdio.h>
#include <string.h>

#define SIZE_ASCII 255
#define UPPER_CASE 11
#define LOWER_CASE 22

// counting the number of the used alphabet
void CalcNumAlphabetInfo(char* strInput, int nStrLength, int* nNumLarge, int* nNumSmall)
{
	for(unsigned int i = 0; i < nStrLength; i++)
	{
		nNumLarge[strInput[i]]++;
		nNumSmall[strInput[i]]++; 
	}
}

// printint the result
void PrintCountRes(int* nArrInput, int nCase)
{
	switch (nCase)
	{
		case UPPER_CASE: 
		{
			for(unsigned i = 'A'; i <= 'Z'; i++)
			{
				if (nArrInput[i] > 0)
					printf("UpperCase::%c:%d\n", i, nArrInput[i]);
			}
			break;
		}
		case LOWER_CASE:
		{
			for(unsigned i = 'a'; i <= 'z'; i++)
			{
				if (nArrInput[i] > 0)
					printf("LowerCase::%c:%d\n", i, nArrInput[i]);
			}
			break;
		}
		default: 
		{
			printf("Please check your case status..\n");
			break;
		}
	}
	printf("\n");
}

// main function
int main(void)
{
	// initializing variables
	char strInput[300];
	int nStrLength;
	int nNumLarge[SIZE_ASCII] = {0, };
	int nNumSmall[SIZE_ASCII] = {0, };
	int* pNumLarge = nNumLarge;
	int* pNumSmall = nNumSmall;
	
	// generating the input information
	// in linux, gets/gets_s are deprecated function case of the security issues
	// "%[^\n]s": including the spacebar
	printf("Input your string information:\n");
	scanf("%[^\n]s", strInput);
	nStrLength = strlen(strInput); 

	// for debugging
	printf("your input:%s\n\n", strInput);

	// counting the number of the used alphabet
	CalcNumAlphabetInfo(strInput, nStrLength, pNumLarge, pNumSmall);

	// for debugging
	PrintCountRes(pNumLarge, UPPER_CASE);
	PrintCountRes(pNumSmall, LOWER_CASE);

	// pause function (windows: system("pause");)
	getchar();
  return 0;
}
