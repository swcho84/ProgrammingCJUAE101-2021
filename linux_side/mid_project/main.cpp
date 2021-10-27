#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#define ROCK		 0
#define SCISSORS 1
#define PAPER		 2
#define NUMCASE	 3

#define THREE_OUT_OF_TWO 3

#define BASIC 		11
#define MINUSONE	22
#define MUKJIPA		33
#define CONTINUE	44
#define QUIT			55
#define END 			66

#define WIN				111
#define LOSE			222
#define DRAW      333

#define PLAYER   1111
#define COMPUTER 2222

#define LEFTSIDE	0
#define RIGHTSIDE 1
#define MINUS_ONE_STATUS 2

// generating the seed number using the time clock information
void GenRandSeed()
{
  // generating the random number using the time seed
  srand((unsigned int)(time(NULL)));
  return;
}

// generating the computer`s Rock-Scissors-Paper selection result
int GenComRockSciPaper()
{
	return (rand() % NUMCASE);
}

// generating the countdown effect
void GenCountDownEffect()
{
	unsigned int nCountDown = 3;
	for (int i = 0; i < nCountDown; i++)
	{
		printf(".\n");
		sleep(1);
	}		
}

// printing the Rock-Scissors-Paper selection status
void PrintSelectStatus(int nSelect, int nCase)
{
	switch (nSelect)
	{
		case ROCK: 
		{
			if (nCase == PLAYER)
				printf("Status::Player::Rock\n");
			else 
				printf("Status::Computer::Rock\n");
			break;
		}
		case SCISSORS: 
		{
			if (nCase == PLAYER)
				printf("Status::Player::Scissors\n");
			else 
				printf("Status::Computer::Scissors\n");			
			break;
		}
		case PAPER: 
		{
			if (nCase == PLAYER)
				printf("Status::Player::Paper\n");
			else 
				printf("Status::Computer::Paper\n");					
			break;
		}				
	}
}

// printing the Rock-Scissors-Paper game status
void PrintGameStatus(int nNumPlayerWin, int nNumComWin)
{
	printf("GameStatus::Win::(Player, Com)=(%d,%d)\n", nNumPlayerWin, nNumComWin);
}

// calculating the match status between the single Rock-Scissors-Paper game
int* CalcMatchStatus(int nPlayer, int nCom)
{
	// result: player win, com win, draw
	static int nRes[2] = {0, 0};
	if (nPlayer == nCom)
	{
		nRes[0] = DRAW;
		nRes[1] = DRAW;
		printf("Draw..\n");
	}
	else
	{
		if (((nPlayer == ROCK) && (nCom == SCISSORS)) ||
				((nPlayer == SCISSORS) && (nCom == PAPER)) ||
				((nPlayer == PAPER) && (nCom == ROCK)))
		{
			nRes[0] = WIN;
			nRes[1] = LOSE;
			printf("player Win..\n");			
		}
		else if (((nPlayer == SCISSORS) && (nCom == ROCK)) ||
						((nPlayer == ROCK) && (nCom == PAPER)) ||
						((nPlayer == PAPER) && (nCom == SCISSORS)))
		{
			nRes[0] = LOSE;
			nRes[1] = WIN;
			printf("computer Win..\n");			
		}
	}
	return nRes;
}

// calculating the match status between the single Rock-Scissors-Paper game
int CalcMatchPlayerStatus(int nPlayer, int nCom)
{
	// result: player win, com win, draw
	static int nRes = DRAW;
	if (nPlayer == nCom)
	{
		nRes = DRAW;
		printf("Draw..\n");
	}
	else
	{
		if (((nPlayer == ROCK) && (nCom == SCISSORS)) ||
				((nPlayer == SCISSORS) && (nCom == PAPER)) ||
				((nPlayer == PAPER) && (nCom == ROCK)))
		{
			nRes = WIN;
			printf("player Win..\n");			
		}
		else if (((nPlayer == SCISSORS) && (nCom == ROCK)) ||
						((nPlayer == ROCK) && (nCom == PAPER)) ||
						((nPlayer == PAPER) && (nCom == SCISSORS)))
		{
			nRes = LOSE;
			printf("computer Win..\n");			
		}
	}
	return nRes;
}

// selecting the minus-one status, for player
int GenPlayerFinalStatus(int *nPlayerStatus)
{
	int nRes;
	while (1)
	{
		int nPlayerNumSelect;
		printf("Player::Choose one status (0 or 1):\n");
		scanf(" %d", &nPlayerNumSelect);
		if ((nPlayerNumSelect == 0) || (nPlayerNumSelect == 1))
		{
			switch (nPlayerNumSelect)
			{
				case LEFTSIDE:
				{
					nRes = nPlayerStatus[0];
					break;
				}
				case RIGHTSIDE:
				{
					nRes = nPlayerStatus[1];
					break;
				}			
			}
			break;
		}
		else
			printf("please check your status..\n");
	}
	return nRes;
}

// game loop, mode#1: Basic
int CalcModeBasic()
{
	// initializing the variables
	int nRes = CONTINUE;
	int nNumPlayerWin = 0;
	int nNumComWin = 0;

	// 3-out-of-2-wins round 
	for (unsigned int i = 1; i < THREE_OUT_OF_TWO + 1; i++)
	{
		// generating the player`s Rock-Scissors-Paper selection result
		int nPlayerStatus;
		printf("Turn(%d)::Player::Choose the Rock-Scissors-Paper (0: Rock, 1: Scissors, 2: Paper):\n", i);
		printf("if you want to forced quit, please input 55\n");
		scanf("%d", &nPlayerStatus);

		// forced quit mode
		if (nPlayerStatus == QUIT)
		{
			printf("Turn::Player::Forced quit..\n\n");
			nRes = QUIT;
			break;
		}

		// for debugging
		PrintSelectStatus(nPlayerStatus, PLAYER);

		// generating the computer`s Rock-Scissors-Paper selection result
		int nComStatus = GenComRockSciPaper();

		// calculating the winner-looser status
		// result: player win, com win, draw
		GenCountDownEffect();
		PrintSelectStatus(nComStatus, COMPUTER);			
		int* pMatchStatus = CalcMatchStatus(nPlayerStatus, nComStatus);

		// counting the 3-out-of-2-wins round status
		if ((pMatchStatus[0] != DRAW) || (pMatchStatus[1] != DRAW))
		{
			// accumulating the round status
			if (pMatchStatus[0] == WIN)
				nNumPlayerWin++;
			else if (pMatchStatus[1] == WIN)
				nNumComWin++;
			
			// for 3-out-of-2-wins
			if ((nNumPlayerWin == 2) || (nNumComWin == 2))
				break;
		}
		else
		{
			// for handling draw status
			--i;
			if (i < 1)
				i = 0;  // finally, meet the increment operator of for-statement
		}

		// for debugging
		PrintGameStatus(nNumPlayerWin, nNumComWin);
		printf("\n");
	}

	// printing the game status
	PrintGameStatus(nNumPlayerWin, nNumComWin);
	if (nNumPlayerWin > nNumComWin)
		printf("GameStatus::Final::Win::Player..\n\n");
	else
		printf("GameStatus::Final::Win::Computer..\n\n");
	return nRes;
}

// game loop, mode#2: Minus-one
int CalcModeMinusOne()
{
	// initializing the variables
	int nRes = CONTINUE;
	int nNumPlayerWin = 0;
	int nNumComWin = 0;
	int nPlayerStatus[2] = {};
	int nComStatus[2] = {};	

	// if draw, re-matching the game
	while (1)
	{
		// generating the player`s Rock-Scissors-Paper selection result, for Minus-one game
		printf("Player::Choose two Rock-Scissors-Paper status (0: Rock, 1: Scissors, 2: Paper):\n");
		printf("if you want to forced quit, please input 55\n");
		scanf(" %d%d", &nPlayerStatus[0], &nPlayerStatus[1]);

		// forced quit mode
		if ((nPlayerStatus[0] == QUIT) || (nPlayerStatus[1] == QUIT))
		{
			nRes = QUIT;
			return nRes;
		}
		else // ongoing game status
		{
			// for debugging
			for (unsigned int i = 0; i < 2; i++)
			{
				printf("[%d]", i);
				PrintSelectStatus(nPlayerStatus[i], PLAYER);			
			}		
		}

		// generating the computer`s Rock-Scissors-Paper selection result, for Minus-one game
		for (unsigned int i = 0; i < 2; i++)
		{
			nComStatus[i] = GenComRockSciPaper();
			printf("[%d]", i);
			PrintSelectStatus(nComStatus[i], COMPUTER);			
		}

		// selecting the minus-one status, for player
		int nPlayerFinalStatus = GenPlayerFinalStatus(nPlayerStatus);
		PrintSelectStatus(nPlayerFinalStatus, PLAYER);

		// selecting the minus-one status, for computer 
		int nComputerFinalStatus = nComStatus[rand()%MINUS_ONE_STATUS];

		// calculating the winner-looser status
		// result: player win, com win, draw
		GenCountDownEffect();	
		PrintSelectStatus(nComputerFinalStatus, COMPUTER);	
		int* pMatchStatus = CalcMatchStatus(nPlayerFinalStatus, nComputerFinalStatus);

		// accumulating the round status
		if (pMatchStatus[0] == WIN)
			nNumPlayerWin++;
		else if (pMatchStatus[1] == WIN)
			nNumComWin++;	

		// printing the game status
		PrintGameStatus(nNumPlayerWin, nNumComWin);
		if (nNumPlayerWin > nNumComWin)
		{
			printf("GameStatus::Final::Win::Player..\n\n");
			break;
		}
		else if (nNumPlayerWin < nNumComWin)
		{
			printf("GameStatus::Final::Win::Computer..\n\n");
			break;			
		}
		else
			printf("GameStatus::Draw..\n\n");
	}

	return nRes;
}

// game loop, mode#3: Muk-Ji-Pa
int CalcModeMukJiPa()
{
	// initializing the variables
	int nRes = CONTINUE;
	int nNumPlayerWin = 0;
	int nNumComWin = 0;
	int nPlayerStatus[2] = {};
	int nComStatus[2] = {};	

	// if finally draw, end of the game
	while (1)
	{
		// generating the player`s first Rock-Scissors-Paper selection result, for Muk-Ji-Pa
		printf("Player::Choose first Rock-Scissors-Paper status (0: Rock, 1: Scissors, 2: Paper):\n");
		printf("if you want to forced quit, please input 55\n");
		scanf(" %d", &nPlayerStatus[0]);

		// forced quit mode
		if (nPlayerStatus[0] == QUIT)
		{
			printf("Turn::Player::Forced quit..\n\n");
			nRes = QUIT;
			break;
		}

		// for debugging
		printf("[Player::0]");
		PrintSelectStatus(nPlayerStatus[0], PLAYER);

		// generating the computer`s Rock-Scissors-Paper selection result
		nComStatus[0] = GenComRockSciPaper();

		// result: player side
		GenCountDownEffect();
		printf("[Computer::0]");
		PrintSelectStatus(nComStatus[0], COMPUTER);
		int nFirstPlayerMatchStatus = CalcMatchPlayerStatus(nPlayerStatus[0], nComStatus[0]);

		// going to the next game
		int nCount = 0;
		while (nFirstPlayerMatchStatus != DRAW)
		{
			// generating the player`s first Rock-Scissors-Paper selection result, for Muk-Ji-Pa
			printf("Player::Choose second Rock-Scissors-Paper status (0: Rock, 1: Scissors, 2: Paper):\n");
			scanf(" %d", &nPlayerStatus[1]);

			// for debugging
			printf("[Player::1]");
			PrintSelectStatus(nPlayerStatus[1], PLAYER);

			// generating the computer`s Rock-Scissors-Paper selection result
			nComStatus[1] = GenComRockSciPaper();

			// result: player side
			GenCountDownEffect();
			printf("[Computer::1]");
			PrintSelectStatus(nComStatus[1], COMPUTER);			
			int nSecondPlayerMatchStatus = CalcMatchPlayerStatus(nPlayerStatus[1], nComStatus[1]);

			// second match is draw --> judging the match status using the previous match status
			if (nSecondPlayerMatchStatus == DRAW)
				break;
			else	// second is not draw --> swapping the first win/lose status 
			{
				if (nSecondPlayerMatchStatus == WIN)
					nFirstPlayerMatchStatus = WIN;
				else
					nFirstPlayerMatchStatus = LOSE;
			}

			nCount++;
		}

		// handling the exception
		if (nCount == 0)
		{
			printf("FistGameStatus::Draw..\n");			
			printf("First::ReMatch..\n\n");
		}
		else
		{
			// judging the game status
			if (nFirstPlayerMatchStatus == WIN)
				printf("Final::player::Win..\n\n");
			else if (nFirstPlayerMatchStatus == LOSE)
				printf("Final::computer::Win..\n\n");
			
			// exiting the game
			break;
		}
	}
	return nRes;
}

// main function
int main(void)
{
	// generating the input information
	unsigned int nGameMode = 0;

	// main loop
	while (nGameMode != END)
	{
		printf("Choose the Rock-Scissors-Paper Game mode (11: Basic, 22: Minus-one, 33: Muk-Ji-Pa):\n");
		printf("if you want to end the loop, please input 66\n");
		scanf("%d", &nGameMode);
		fflush(stdin);
		printf("\n");

		// selecting the game loop
		unsigned int nEndFlag = 0;
		switch (nGameMode)
		{
			case BASIC:
			{
				printf("Mode#1::Basic, 3 out of 2 wins\n\n");
				nEndFlag = CalcModeBasic();
				break;
			}
			case MINUSONE:
			{
				printf("Mode#2::Minus-one\n\n");
				nEndFlag = CalcModeMinusOne();
				break;
			}
			case MUKJIPA:
			{
				printf("Mode#3::Muk-Ji-Pa\n\n");
				nEndFlag = CalcModeMukJiPa();
				break;
			}
			case END:
			{
				printf("Select:Quit..\n");
				nEndFlag = QUIT;
				break;
			}
			default:
			{
				printf("Please check the your input condition...\n");
				break;
			}
		}

		// calculating the end condition
		if (nEndFlag == QUIT)
		{
			char chrYN;
			printf("Really want?(y,n)\n");
			while ((chrYN != 'y') && (chrYN != 'n'))
			{
				// for the memory flush
				scanf(" %c", &chrYN);
				switch (chrYN)
				{
					case 'y':
					{
						// really game end mode
						printf("Select:Quit..\n");
						nGameMode = END;
						break;
					}
					case 'n': 
					{
						// continue mode
						printf("Select:continue...\n");
						nGameMode = CONTINUE;
						break;
					}
					default: 
					{
						// handling the exception
						printf("Please check your input condition...\n");
						break;
					}
				}
			}
		}
	}

	return 0;
}