#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define SIZELOTTO   6
#define RANGELOTTO  45
#define COM         99
#define PLAYER      100
#define FIRSTPRZ    6
#define THIRDPRZ    5
#define FOURTHPRZ   4
#define FIFTHPRZ    3     

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
  nRes = ((int)(nNum) % (nRange));
  return nRes;
}

// generating the random number array, double type
void GenRandNumArray(int *nPtArrayInput, int nSize, int nCase)
{
  for (int i = 0; i < nSize; i++)
  {
    switch (nCase)
    {
      case COM:
      {
        nPtArrayInput[i] = GenRandIntNum(RANGELOTTO);
        break;
      }
      case PLAYER:
      {
        while (1)
        {
          printf("[%d]: ", i);
          scanf("%d", (nPtArrayInput + i));

          if ((*(nPtArrayInput + i) > 45) || (*(nPtArrayInput + i) < 1))
            printf("please check the input..\n");
          else
            break;
        }
        break;
      }
    }

    if ((*(nPtArrayInput + i) < 1))
      i--;
    
    for (int j = 0; j < i; j++)
    {
      if (*(nPtArrayInput + i) == *(nPtArrayInput + j))
        i--;
    }
  }
}

// calculating the lotto problem
void CalcLottoResult()
{
  // generating lotto number, for computer
  int nComLottoArray[SIZELOTTO + 1] = {};
  int *nPtComLottoArray = nComLottoArray;
  GenRandNumArray(nPtComLottoArray, SIZELOTTO + 1, COM);
  int nComSecondNum = nPtComLottoArray[SIZELOTTO];

  // generating lotto number, for player
  int nPlayerLottoArray[SIZELOTTO] = {};
  int *nPtPlayerLottoArray = nPlayerLottoArray;
  GenRandNumArray(nPtPlayerLottoArray, SIZELOTTO, PLAYER);   

  // for debugging
	printf("\n");
  for (int i = 0; i < SIZELOTTO + 1; i++)
    printf("ComLotto[%d]:%d\n", i, nPtComLottoArray[i]);
  printf("ComSecondNum:%d\n", nComSecondNum);

  // for debugging
	printf("\n");	
  for (int i = 0; i < SIZELOTTO; i++)
    printf("PlayerLotto[%d]:%d\n", i, nPtPlayerLottoArray[i]);

  // calculating the lotto result
  int nCounter = 0;
  for (int i = 0; i < (SIZELOTTO); i++)
  {
    for (int j = 0; j < (SIZELOTTO); j++)
    {
      if (nPtComLottoArray[i] == nPtPlayerLottoArray[j])
        nCounter++;
    }
  }
  
  // calculating the second prize flag
  int nSecondPrizeFlag = 0;
  for (int i = 0; i < (SIZELOTTO); i++)
  {
    if (nPtPlayerLottoArray[i] == nComSecondNum)
      nSecondPrizeFlag = 1;
  }  

  // for debugging
	printf("\n");	
  printf("result(counter, secondflag)=(%d, %d)\n", nCounter, nSecondPrizeFlag);

  // calculating result
  switch (nCounter)
  {
    case FIRSTPRZ:
    {
      printf("Result: 1st Prize..\n");  
      break;
    }
    case THIRDPRZ:
    {
      // using second flag
      if (nSecondPrizeFlag == 1)
        printf("Result: 2nd Prize..\n");  
      else
        printf("Result: 3rd Prize..\n");  
      break;
    }
    case FOURTHPRZ:
    {
      printf("Result: 4th Prize..\n");  
      break;
    }
    case FIFTHPRZ:
    {
      printf("Result: 5th Prize..\n");  
      break;
    }
    default:
    {
      printf("Result: No Prize..\n");
      break;
    }
  }
}

// main function
int main(void)
{
  // generating the seed number using the time clock information
  GenRandSeed();

  // additional problem: lotto problem
  // random number array, using the defined size data
  CalcLottoResult();

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}