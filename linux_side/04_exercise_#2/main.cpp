#include <stdio.h>
#include <math.h>
#include <time.h>

#define END_COND 999
#define MAX_DICE 6
#define DICENUM1 1
#define DICENUM2 2
#define DICENUM3 3
#define DICENUM4 4
#define DICENUM5 5
#define DICENUM6 6

// generating the seed number using the time clock information
void GenRandSeed()
{
  // generating the random number using the time seed
  srand((unsigned int)(time(NULL)));
  return;
}

// generating the random number
unsigned int GenRandNum(unsigned int nRange)
{
  unsigned int nRes = 0;
  unsigned int nNum = rand();
  nRes = ((unsigned int)(nNum) % (nRange));
  return nRes;
}

// generating the dice number
int GenDiceNum()
{
	int nRes = 0;
	while (1)
	{
		// generating the number from 1 to 6 as the dice
		nRes = GenRandNum(MAX_DICE + 1);
		if (nRes != 0)
			break;
	}
	return nRes;
}

// accumulating the summation of the dice case
int CalcSumDiceNum(int nDiceNum, int nSumDiceNum)
{
	if (nDiceNum == nSumDiceNum)
		return 1;
	else 
		return 0;
}

// calculating the probability of the dice case
double CalcProbDiceNum(int nAccDiceNum, int nTotal)
{
	return (((double)(nAccDiceNum) * 100.0)/((double)(nTotal)));
}

// main loop function
int main(void)
{
  // assigning seed
  GenRandSeed();

	// initializing variables
	int nRange = 0;
	int nSumDiceNum1 = 0, nSumDiceNum2 = 0, nSumDiceNum3 = 0, nSumDiceNum4 = 0, nSumDiceNum5 = 0, nSumDiceNum6 = 0;
	double dProbDiceNum1 = 0.0, nProbDiceNum2 = 0.0, nProbDiceNum3 = 0.0, nProbDiceNum4 = 0.0, nProbDiceNum5 = 0.0, nProbDiceNum6 = 0.0;

	// generating the input information
		printf("Input a single number, for generating the random number related to your input:\n");
		printf("if you want to end the loop, please input 999\n");
		scanf("%d", &nRange);
		printf("\n");

	// exceptional handling
	if (nRange < 0)
	{
		printf("Please check the your input status...\n");
		return 1;
	}

	// early end loop
	if (nRange == END_COND)
	{
		printf("End program...\n");
		return 0;
	}

	// calculating the summation of the dice case
	for (int i = 0; i < nRange; i++)
	{
		int nDiceNum = GenDiceNum();
		nSumDiceNum1 += CalcSumDiceNum(nDiceNum, DICENUM1);
		nSumDiceNum2 += CalcSumDiceNum(nDiceNum, DICENUM2);
		nSumDiceNum3 += CalcSumDiceNum(nDiceNum, DICENUM3);
		nSumDiceNum4 += CalcSumDiceNum(nDiceNum, DICENUM4);
		nSumDiceNum5 += CalcSumDiceNum(nDiceNum, DICENUM5);
		nSumDiceNum6 += CalcSumDiceNum(nDiceNum, DICENUM6);										
	}

	// for debugging
	printf("Probability of the dice case..\n");
	printf("[1]Num1:(%d, %.4lf)\n", nSumDiceNum1, CalcProbDiceNum(nSumDiceNum1, nRange));
	printf("[2]Num2:(%d, %.4lf)\n", nSumDiceNum2, CalcProbDiceNum(nSumDiceNum2, nRange));
	printf("[3]Num3:(%d, %.4lf)\n", nSumDiceNum3, CalcProbDiceNum(nSumDiceNum3, nRange));
	printf("[4]Num4:(%d, %.4lf)\n", nSumDiceNum4, CalcProbDiceNum(nSumDiceNum4, nRange));
	printf("[5]Num5:(%d, %.4lf)\n", nSumDiceNum5, CalcProbDiceNum(nSumDiceNum5, nRange));
	printf("[6]Num6:(%d, %.4lf)\n", nSumDiceNum6, CalcProbDiceNum(nSumDiceNum6, nRange));

  // end of program..
  printf("\nEnd of the program..\n");

	// pause function (windows: system("pause");
	getchar();	
  return 0;
}