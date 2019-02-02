#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int playerNum;
	struct gameState G;
	int k[10] = { adventurer, sea_hag, embargo, village, minion, mine, cutpurse,
			 baron, tribute, smithy };

	playerNum = 4;

	initializeGame(playerNum, k, 2, &G);

	printf("This test, checks the smithy card function.\n\n");

	printf("********Smithy card played**********\n");
	smithyFunc(-1, &G);

	printf("Are the correct cards added to the players hand: ");
	if (G.handCount[0] == 7)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
		printf("Correct Hand Count: 7\n");
		printf("Actual Hand Count: %d\n", G.handCount[0]);
	}
	printf("Is the cards played count incremented correctly: ");
	if (G.playedCardCount == 1)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
		printf("Correct Played Card Count: 1\n");
		printf("Actual Played Card Count: %d\n", G.playedCardCount);
	}

	printf("\n********Smithy card played**********\n");
	smithyFunc(-1, &G);

	printf("Are the correct cards added to the players hand: ");
	if (G.handCount[0] == 9)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
		printf("Correct Hand Count: 9\n");
		printf("Actual Hand Count: %d\n", G.handCount[0]);
	}
	printf("Is the cards played count incremented correctly: ");
	if (G.playedCardCount == 2)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
		printf("Correct Played Card Count: 1\n");
		printf("Actual Played Card Count: %d\n", G.playedCardCount);
	}

	return 0;
}