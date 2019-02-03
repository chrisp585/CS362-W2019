/****************************************************************************/
/* Tests:  initializeGame funtion                                           */
/* Christopher Perry                                                        */
/* CS 362  2/3/2019                                                         */
/****************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int main() {
	int playerNum;
	struct gameState G;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
			 sea_hag, tribute, smithy };

	printf("\n*****************************************************************************************************");
	printf("************************************ Test Beginning *************************************************");
	printf("***********         This Unit Test is for the initializeGame function.       ************************");
	printf("*****************************************************************************************************");
	printf("*****************************************************************************************************\n\n");

	//************Test with 1 layer********************
	playerNum = 1;
	printf("Test with not enough players: ");
	if (initializeGame(playerNum, k, 2, &G) == -1)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	//**************Test with 5 players*****************
	playerNum = 5;
	printf("Test with too many players: ");
	if (initializeGame(5, k, 2, &G) == -1)
	{
		printf("PASS\n\n");
	}
	else
	{
		printf("FAIL\n\n");
	}


	//***Test entire function with 2 players***************
	playerNum = 2;
	printf("********Test with 2 players************\n");

	k[3] = smithy;

	printf("Test for two of the same kingdom cards: ");
	if (initializeGame(playerNum, k, 2, &G) == 0)
	{
		printf("FAIL\n\n");
	}
	else
	{
		printf("PASS\n\n");
	}

	k[3] = village;

	printf("Test supply count with 2 players:\n");
	initializeGame(playerNum, k, 2, &G);

	printf("Curse cards: ");
	if (G.supplyCount[curse] == 10)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("Victory cards: ");
	if (G.supplyCount[estate] == 8)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("Treasure cards: ");
	if (G.supplyCount[copper] == 46)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("'Victory' kingdom cards: ");
	if (G.supplyCount[gardens] == 8)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("Chosen kingdom card: ");
	if (G.supplyCount[smithy] == 10)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("Kingdom card not chosen: ");
	if (G.supplyCount[baron] == -1)
	{
		printf("PASS\n\n");
	}
	else
	{
		printf("FAIL\n\n");
	}

	printf("Player decks:\n");
	printf("Player 0: ");
	if (G.deckCount[0] == 5)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	for (int i = 1; i < playerNum; i++)
	{
		printf("Player %d: ", i);
		if (G.deckCount[i] == 10)
		{
			printf("PASS\n");
		}
		else
		{
			printf("FAIL\n");
		}
	}

	printf("\nPlayer hand:\n");
	printf("Player 0: ");
	if (G.handCount[0] == 5 && G.discardCount[0] == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	for (int i = 1; i < playerNum; i++)
	{
		printf("Player %d: ", i);
		if (G.handCount[i] == 0 && G.discardCount[i] == 0)
		{
			printf("PASS\n");
		}
		else
		{
			printf("FAIL\n");
		}
	}

	printf("\nEmbargo tokens:\n");
	for (int i = 0; i < playerNum; i++)
	{
		printf("Player %d: ", i);
		if (G.embargoTokens[i] == 0)
		{
			printf("PASS\n");
		}
		else
		{
			printf("FAIL\n");
		}
	}

	printf("\nInitialization of first players hand: ");
	if (G.outpostPlayed != 0)
	{
		printf("\nFAIL - OutpostPlayed");
	}
	else if (G.phase != 0)
	{
		printf("\nFAIL - Phase");
	}
	else if (G.numActions != 1)
	{
		printf("\nFAIL - NumAction");
	}
	else if (G.numBuys != 1)
	{
		printf("\nFAIL - NumBuys");
	}
	else if (G.playedCardCount != 0)
	{
		printf("\nFAIL - PlayedCardCount");
	}
	else if (G.whoseTurn != 0)
	{
		printf("\nFAIL - WhoseTurn");
	}
	else
	{
		printf("PASS\n");
	}



	//***Test entire function with 3 players***************
	playerNum = 3;
	printf("\n********Test with 3 players************\n");

	k[3] = smithy;

	printf("Test for two of the same kingdom cards: ");
	if (initializeGame(playerNum, k, 2, &G) == 0)
	{
		printf("FAIL\n\n");
	}
	else
	{
		printf("PASS\n\n");
	}

	k[3] = village;

	printf("Test supply count with 2 players:\n");
	initializeGame(playerNum, k, 2, &G);

	printf("Curse cards: ");
	if (G.supplyCount[curse] == 20)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("Victory cards: ");
	if (G.supplyCount[estate] == 12)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("Treasure cards: ");
	if (G.supplyCount[copper] == 39)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("'Victory' kingdom cards: ");
	if (G.supplyCount[gardens] == 12)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("Chosen kingdom card: ");
	if (G.supplyCount[smithy] == 10)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("Kingdom card not chosen: ");
	if (G.supplyCount[baron] == -1)
	{
		printf("PASS\n\n");
	}
	else
	{
		printf("FAIL\n\n");
	}

	printf("Player decks:\n");
	printf("Player 0: ");
	if (G.deckCount[0] == 5)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	for (int i = 1; i < playerNum; i++)
	{
		printf("Player %d: ", i);
		if (G.deckCount[i] == 10)
		{
			printf("PASS\n");
		}
		else
		{
			printf("FAIL\n");
		}
	}

	printf("\nPlayer hand:\n");
	printf("Player 0: ");
	if (G.handCount[0] == 5 && G.discardCount[0] == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	for (int i = 1; i < playerNum; i++)
	{
		printf("Player %d: ", i);
		if (G.handCount[i] == 0 && G.discardCount[i] == 0)
		{
			printf("PASS\n");
		}
		else
		{
			printf("FAIL\n");
		}
	}

	printf("\nEmbargo tokens:\n");
	for (int i = 0; i < playerNum; i++)
	{
		printf("Player %d: ", i);
		if (G.embargoTokens[i] == 0)
		{
			printf("PASS\n");
		}
		else
		{
			printf("FAIL\n");
		}
	}

	printf("\nInitialization of first players hand: ");
	if (G.outpostPlayed != 0)
	{
		printf("\nFAIL - OutpostPlayed");
	}
	else if (G.phase != 0)
	{
		printf("\nFAIL - Phase");
	}
	else if (G.numActions != 1)
	{
		printf("\nFAIL - NumAction");
	}
	else if (G.numBuys != 1)
	{
		printf("\nFAIL - NumBuys");
	}
	else if (G.playedCardCount != 0)
	{
		printf("\nFAIL - PlayedCardCount");
	}
	else if (G.whoseTurn != 0)
	{
		printf("\nFAIL - WhoseTurn");
	}
	else
	{
		printf("PASS\n");
	}


	//***Test entire function with 4 players***************
	playerNum = 4;
	printf("\n********Test with 4 players************\n");

	k[3] = smithy;

	printf("Test for two of the same kingdom cards: ");
	if (initializeGame(playerNum, k, 2, &G) == 0)
	{
		printf("FAIL\n\n");
	}
	else
	{
		printf("PASS\n\n");
	}

	k[3] = village;

	printf("Test supply count with 2 players:\n");
	initializeGame(playerNum, k, 2, &G);

	printf("Curse cards: ");
	if (G.supplyCount[curse] == 30)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("Victory cards: ");
	if (G.supplyCount[estate] == 12)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("Treasure cards: ");
	if (G.supplyCount[copper] == 32)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("'Victory' kingdom cards: ");
	if (G.supplyCount[gardens] == 12)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("Chosen kingdom card: ");
	if (G.supplyCount[smithy] == 10)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("Kingdom card not chosen: ");
	if (G.supplyCount[baron] == -1)
	{
		printf("PASS\n\n");
	}
	else
	{
		printf("FAIL\n\n");
	}

	printf("Player decks:\n");
	printf("Player 0: ");
	if (G.deckCount[0] == 5)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	for (int i = 1; i < playerNum; i++)
	{
		printf("Player %d: ", i);
		if (G.deckCount[i] == 10)
		{
			printf("PASS\n");
		}
		else
		{
			printf("FAIL\n");
		}
	}

	printf("\nPlayer hand:\n");
	printf("Player 0: ");
	if (G.handCount[0] == 5 && G.discardCount[0] == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	for (int i = 1; i < playerNum; i++)
	{
		printf("Player %d: ", i);
		if (G.handCount[i] == 0 && G.discardCount[i] == 0)
		{
			printf("PASS\n");
		}
		else
		{
			printf("FAIL\n");
		}
	}

	printf("\nEmbargo tokens:\n");
	for (int i = 0; i < playerNum; i++)
	{
		printf("Player %d: ", i);
		if (G.embargoTokens[i] == 0)
		{
			printf("PASS\n");
		}
		else
		{
			printf("FAIL\n");
		}
	}

	printf("\nInitialization of first players hand: ");
	if (G.outpostPlayed != 0)
	{
		printf("\nFAIL - OutpostPlayed");
	}
	else if (G.phase != 0)
	{
		printf("\nFAIL - Phase");
	}
	else if (G.numActions != 1)
	{
		printf("\nFAIL - NumAction");
	}
	else if (G.numBuys != 1)
	{
		printf("\nFAIL - NumBuys");
	}
	else if (G.playedCardCount != 0)
	{
		printf("\nFAIL - PlayedCardCount");
	}
	else if (G.whoseTurn != 0)
	{
		printf("\nFAIL - WhoseTurn");
	}
	else
	{
		printf("PASS\n");
	}

	printf("\n*****************************************************************************************************");
	printf("************************************ Testing Complete ***********************************************");
	printf("*****************************************************************************************************\n");

	return 0;
}