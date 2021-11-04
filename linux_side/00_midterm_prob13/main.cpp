#include <stdio.h>

int main(void)
{
	// initializing variables
  int nDice = 4;
	int nStepFwd = 0;
	char* chArryBoard[11] = {"start", "circle", "star", "10", "heart", 
	                          "30", "50", "circle", "star", "80", "100"};

	// step forward
	nStepFwd += nDice;

	// calculating the rules with respect to the problem
	while ((chArryBoard[nStepFwd] == "heart") || 
	       (chArryBoard[nStepFwd] == "star") || 
				 (chArryBoard[nStepFwd] == "circle"))
	{
		if (chArryBoard[nStepFwd] == "heart")
			nStepFwd += 3;
		else if (chArryBoard[nStepFwd] == "star")
			nStepFwd += 2;
		else if (chArryBoard[nStepFwd] == "circle")
			nStepFwd -= 1;
		else
		{
			break;
		}
	}

	// final result
	printf("[%d]chArryBoard[%d]=(%s)\n", 
	        nStepFwd, nStepFwd, chArryBoard[nStepFwd]);
	
  return 0;
}