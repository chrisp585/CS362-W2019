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
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
			 sea_hag, tribute, smithy };

	playerNum = 4;

	initializeGame(playerNum, k, 2, &G);

	printf("This unit test, test to insure that the inGameOver functions ends the game at the correct time.");

	printf("\n\nTest with no empty supply piles: ");
	if (isGameOver(&G) == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	
	printf("\nTest with one empty supply piles: ");
	G.supplyCount[adventurer] = 0;
	if (isGameOver(&G) == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("\nTest with two empty supply piles: ");
	G.supplyCount[village] = 0;
	if (isGameOver(&G) == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("\nTest with three empty supply piles: ");
	G.supplyCount[minion] = 0;
	if (isGameOver(&G) == 1)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("\nTest after filling the empty piles back up: ");
	G.supplyCount[adventurer] = 10;
	G.supplyCount[village] = 10;
	G.supplyCount[minion] = 10;
	if (isGameOver(&G) == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("\nTest with just province pile empty: ");
	G.supplyCount[province] = 0;
	if (isGameOver(&G) == 1)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("\nTest after filling the province pile back up: ");
	G.supplyCount[province] = 10;
	if (isGameOver(&G) == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("\nTest with one supply pile empty in additiona to the province pile empty: ");
	G.supplyCount[adventurer] = 0;
	G.supplyCount[province] = 0;
	if (isGameOver(&G) == 1)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	return 0;
}