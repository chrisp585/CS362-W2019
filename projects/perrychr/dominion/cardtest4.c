/****************************************************************************/
/* Tests:  minion card funtion                                              */
/* Christopher Perry                                                        */
/* CS 362  2/3/2019                                                         */
/****************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	const char* cardArr[] = {
	"curse",
	"estate",
	"duchy",
	"province",
	"copper",
	"silver",
	"gold",
	"adventurer",
	"council_room",
	"feast",
	"gardens",
	"mine",
	"remodel",
	"smithy",
	"village",
	"baron",
	"great_hall",
	"minion",
	"steward",
	"tribute",
	"ambassador",
	"cutpurse",
	"embargo",
	"outpost",
	"salvager",
	"sea_hag",
	"treasure_map"
	};

	int tempCoinCount;
	int tempActionCount;
	int playerNum;
	struct gameState G;
	int k[10] = { adventurer, sea_hag, embargo, village, minion, mine, cutpurse,
			 baron, tribute, smithy };
	playerNum = 4;

	initializeGame(playerNum, k, 2, &G);
	int currentPlayer = G.whoseTurn;

	printf("\n*****************************************************************************************************\n");
	printf("************************************ Test Beginning *************************************************\n");
	printf("****************             This tests the minionFunc function.           **************************\n");
	printf("*****************************************************************************************************\n");
	printf("*****************************************************************************************************\n\n");


	//Player 1 draws 5 cards
	for (int i = 0; i < 5; i++)
	{
		drawCard(1, &G);
	}

	//Player 2 draws 4 cards
	for (int i = 0; i < 4; i++)
	{
		drawCard(2, &G);
	}

	//Player 3 draws 3 cards
	for (int i = 0; i < 3; i++)
	{
		drawCard(3, &G);
	}
	

	printf("\n\n********* Test for first choice *********\n");
	for (int i = 0; i < G.numPlayers; i++)
	{
		printf("\n**** Player  %d ****\n", i);
		printf("Current Hand Count: ");
		printf("%d ", G.handCount[i]);
	}

	//************ Testing for choice 1 **********************

	printf("\nCurrent Coins:  ");
	updateCoins(0, &G, 0);
	printf("%d\n", G.coins);
	printf("Number of actions: ");
	printf("%d", G.numActions);
	tempCoinCount = G.coins;
	tempActionCount = G.numActions;

	printf("\n>>>>>>>Minion card played.<<<<<<<<<\n");
	minionFunc(1, 0, &G, -1);

	printf("2 coins added:  ");
	if (G.coins == tempCoinCount + 2)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	//printf("%d\n", G.coins);
	printf("Additional action added: ");
	if (G.numActions == tempActionCount + 1)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	//printf("%d", G.numActions);

	printf("Cards in hand are unchanged: \n");
	printf("Player 0: ");
	if (G.handCount[0] == 4)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	printf("Player 1: ");
	if (G.handCount[1] == 5)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	printf("Player 2: ");
	if (G.handCount[2] == 4)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	printf("Player 3: ");
	if (G.handCount[3] == 3)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	//************** Testing for choice 2 *******************


	initializeGame(playerNum, k, 2, &G);

	//Player 1 draws 5 cards
	for (int i = 0; i < 5; i++)
	{
		drawCard(1, &G);
	}

	//Player 2 draws 4 cards
	for (int i = 0; i < 4; i++)
	{
		drawCard(2, &G);
	}

	//Player 3 draws 3 cards
	for (int i = 0; i < 3; i++)
	{
		drawCard(3, &G);
	}

	printf("\n\n*********** Test for second choice **********\n");

	for (int i = 0; i < G.numPlayers; i++)
	{
		printf("\n**** Player  %d ****\n", i);
		printf("Current Hand Count: ");
		printf("%d ", G.handCount[i]);
	}

	printf("\nCurrent Coins:  ");
	updateCoins(0, &G, 0);
	printf("%d\n", G.coins);
	printf("Number of actions: ");
	printf("%d", G.numActions + 1);
	tempCoinCount = G.coins;
	tempActionCount = G.numActions;

	printf("\n>>>>>>Minion card played.<<<<<<<\n");
	minionFunc(0, 1, &G, -1);

	printf("Coins unchanged:  ");
	if (G.coins == tempCoinCount)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	//printf("%d\n", G.coins);
	printf("Additional action added: ");
	if (G.numActions == tempActionCount + 1)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	//printf("%d", G.numActions);

	printf("Cards in hand change if over 5 in hand: \n");
	printf("Player 0: ");
	if (G.handCount[0] == 4)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	printf("Player 1: ");
	if (G.handCount[1] == 4)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	printf("Player 2: ");
	if (G.handCount[2] == 4)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	printf("Player 3: ");
	if (G.handCount[3] == 3)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("\n*****************************************************************************************************\n");
	printf("************************************ Testing Complete ***********************************************\n");
	printf("*****************************************************************************************************\n");

	return 0;
}