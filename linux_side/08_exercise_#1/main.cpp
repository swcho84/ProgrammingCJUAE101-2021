#include <stdio.h>
#include <math.h>
#include <time.h>

#define ASCEND 11
#define DESCEND 22

// generating the seed number using the time clock information
void GenRandSeed()
{
  // generating the random number using the time seed
  srand((unsigned int)(time(NULL)));
  return;
}

// generating the random number, integer type
int GenRandIntNum(int nRange)
{
  int nRes = 0;
  int nNum = rand();
  nRes = ((int)(nNum) % (nRange)) + 1;
  return nRes;
}

// for debugging, printout the array information
void PrintArr(int* pArr, int nSize, char* strOut)
{
	for (unsigned int i = 0; i < nSize; i++)
		printf("%s::[%d]%d\n", strOut, i, pArr[i]);
	printf("\n");
}

// generating the random integer array with respect to the assigned size information
void GenIntArr(int nSize, int* pArrRes)
{
	for (unsigned int i = 0; i < nSize; i++)
		*(pArrRes + i) = GenRandIntNum(nSize);
}

// swapping the variable for the sort function
void CalcSwap(int* nA, int* nB)
{
	int nTemp;
	nTemp = *nB;
	*nB = *nA;
	*nA = nTemp;
}

// sorting the variable with the option
void CalcSort(int* nArrInput, int nSize, int nCase)
{
	for (unsigned int j = nSize - 1; j > 0; j--) 
	{
		for (unsigned int i = 0; i < (nSize - 1); i++)
		{
			switch(nCase)
			{
				case ASCEND: 
				{
					if (nArrInput[i] > nArrInput[i + 1])
						CalcSwap((nArrInput + i), (nArrInput + i + 1));
					break;
				}
				case DESCEND:
				{
					if (nArrInput[i] < nArrInput[i + 1])
						CalcSwap((nArrInput + i), (nArrInput + i + 1));
					break;
				}
				default:
				{
					printf("Please check your case status..\n");
					break;
				}
			}
		}
	}
}

// exercise #1 function
void merge(int* arrA, int* arrB, int *arrC, int nSize)
{
	// making the merged array
	for (unsigned int i = 0; i < nSize; i++)
	{
		*(arrC + i) = *(arrA + i);
		*(arrC + nSize + i) = *(arrB + i);		
	}

	// for debugging
	PrintArr(arrC, (nSize * 2), "merged array, nArrC::beforeSort");

	// sorting the merged array
	CalcSort(arrC, (nSize * 2), DESCEND);

	// for debugging
	PrintArr(arrC, (nSize * 2), "merged array, nArrC::afterSort");
}

// main function
int main(void)
{
	// initializing variables
	int nSize = 0;
	
	// generating the input information
	printf("Input the size (integer > 0):\n");
	scanf("%d", &nSize);

	// exceptional handling
	if (nSize <= 0)
	{
		printf("please check the input status..\n");
		return 0;
	}

	// assigning the array with the dynamic memory allocation
	int* nArrA = (int*)(malloc(sizeof(int) * (nSize)));
	int* nArrB = (int*)(malloc(sizeof(int) * (nSize)));
	int* nArrMergeC = (int*)(malloc(sizeof(int) * (2 * nSize)));

	// generating the array information
	GenIntArr(nSize, nArrA);
	GenIntArr(nSize, nArrB);

	// for debugging
	PrintArr(nArrA, nSize, "nArrA");
	PrintArr(nArrB, nSize, "nArrB");

	// exercise #1
	merge(nArrA, nArrB, nArrMergeC, nSize);

	// pause function (windows: system("pause");)
	getchar();
  return 0;
}
