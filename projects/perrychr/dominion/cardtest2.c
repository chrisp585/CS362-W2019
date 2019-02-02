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

	int treasureCount =0;
	int playerNum;
	struct gameState G;
	int k[10] = { adventurer, sea_hag, embargo, village, minion, mine, cutpurse,
			 baron, tribute, smithy };
	playerNum = 4;

	initializeGame(playerNum, k, 2, &G);
	int currentPlayer = G.whoseTurn;

	printf("This tests the adventurerFunc function.\n");

	printf("**** Player 0 ****\n");
	printf("Current Deck: ");
	for (int i = 0; i < G.deckCount[currentPlayer]; i++)
	{
		printf("%s ", cardArr[G.deck[currentPlayer][i]]);
	}

	printf("\nCurrent Hand: ");
	for (int i = 0; i < G.handCount[currentPlayer]; i++)
	{
		printf("%s ", cardArr[G.hand[currentPlayer][i]]);
	}

	for (int i = 0; i < G.handCount[currentPlayer]; i++)
	{
		if (G.hand[currentPlayer][i] == copper || G.hand[currentPlayer][i] == silver || G.hand[currentPlayer][i] == gold)
		{
			treasureCount++;
		}
	}
	printf("\nTreasure card count: %d\n", treasureCount);
	int tempTreasureCount = treasureCount;

	printf("\n**** Adventurer card played ****");
	adventurerFunc(&G);

	treasureCount = 0;

	printf("\nDeck: ");
	for (int i = 0; i < G.deckCount[currentPlayer]; i++)
	{
		printf("%s ", cardArr[G.deck[currentPlayer][i]]);
	}

	printf("\nHand: ");
	for (int i = 0; i < G.handCount[currentPlayer]; i++)
	{
		printf("%s ", cardArr[G.hand[currentPlayer][i]]);
	}

	for (int i = 0; i < G.handCount[currentPlayer]; i++)
	{
		if (G.hand[currentPlayer][i] == copper || G.hand[currentPlayer][i] == silver || G.hand[currentPlayer][i] == gold)
		{
			treasureCount++;
		}
	}

	printf("\nTreasure test: ");
	if (treasureCount == tempTreasureCount + 2)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	printf("Treasure card count should be: %d", (tempTreasureCount + 2));
	printf("\nActual treasure card count is: %d", treasureCount);




//************ Player 2 test *****************
	G.whoseTurn = 1;
	treasureCount = 0;
	currentPlayer = G.whoseTurn;

	printf("\n\n**** Player 1 ****\n");

	printf("Current Deck: ");
	for (int i = 0; i < G.deckCount[currentPlayer]; i++)
	{
		printf("%s ", cardArr[G.deck[currentPlayer][i]]);
	}

	printf("\nCurrent Hand: ");
	for (int i = 0; i < G.handCount[currentPlayer]; i++)
	{
		printf("%s ", cardArr[G.hand[currentPlayer][i]]);
	}

	for (int i = 0; i < G.handCount[currentPlayer]; i++)
	{
		if (G.hand[currentPlayer][i] == copper || G.hand[currentPlayer][i] == silver || G.hand[currentPlayer][i] == gold)
		{
			treasureCount++;
		}
	}
	printf("\nTreasure card count: %d\n", treasureCount);
	tempTreasureCount = treasureCount;

	printf("\n**** Adventurer card played ****");
	adventurerFunc(&G);

	treasureCount = 0;

	printf("\nDeck: ");
	for (int i = 0; i < G.deckCount[currentPlayer]; i++)
	{
		printf("%s ", cardArr[G.deck[currentPlayer][i]]);
	}

	printf("\nHand: ");
	for (int i = 0; i < G.handCount[currentPlayer]; i++)
	{
		printf("%s ", cardArr[G.hand[currentPlayer][i]]);
	}

	for (int i = 0; i < G.handCount[currentPlayer]; i++)
	{
		if (G.hand[currentPlayer][i] == copper || G.hand[currentPlayer][i] == silver || G.hand[currentPlayer][i] == gold)
		{
			treasureCount++;
		}
	}

	printf("\nTreasure test: ");
	if (treasureCount == tempTreasureCount + 2)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	printf("Treasure card count should be: %d", (tempTreasureCount + 2));
	printf("\nActual treasure card count is: %d", treasureCount);


	//************ Player 3 test *****************
	G.whoseTurn = 2;
	treasureCount = 0;
	currentPlayer = G.whoseTurn;

	printf("\n\n**** Player 2 ****\n");

	printf("Current Deck: ");
	for (int i = 0; i < G.deckCount[currentPlayer]; i++)
	{
		printf("%s ", cardArr[G.deck[currentPlayer][i]]);
	}

	printf("\nCurrent Hand: ");
	for (int i = 0; i < G.handCount[currentPlayer]; i++)
	{
		printf("%s ", cardArr[G.hand[currentPlayer][i]]);
	}

	for (int i = 0; i < G.handCount[currentPlayer]; i++)
	{
		if (G.hand[currentPlayer][i] == copper || G.hand[currentPlayer][i] == silver || G.hand[currentPlayer][i] == gold)
		{
			treasureCount++;
		}
	}
	printf("\nTreasure card count: %d\n", treasureCount);
	tempTreasureCount = treasureCount;

	printf("\n**** Adventurer card played ****");
	adventurerFunc(&G);

	treasureCount = 0;

	printf("\nDeck: ");
	for (int i = 0; i < G.deckCount[currentPlayer]; i++)
	{
		printf("%s ", cardArr[G.deck[currentPlayer][i]]);
	}

	printf("\nHand: ");
	for (int i = 0; i < G.handCount[currentPlayer]; i++)
	{
		printf("%s ", cardArr[G.hand[currentPlayer][i]]);
	}

	for (int i = 0; i < G.handCount[currentPlayer]; i++)
	{
		if (G.hand[currentPlayer][i] == copper || G.hand[currentPlayer][i] == silver || G.hand[currentPlayer][i] == gold)
		{
			treasureCount++;
		}
	}

	printf("\nTreasure test: ");
	if (treasureCount == tempTreasureCount + 2)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	printf("Treasure card count should be: %d", (tempTreasureCount + 2));
	printf("\nActual treasure card count is: %d", treasureCount);

	//************ Player 4 test *****************
	G.whoseTurn = 3;
	treasureCount = 0;
	currentPlayer = G.whoseTurn;

	printf("\n\n**** Player 3 ****\n");

	printf("Current Deck: ");
	for (int i = 0; i < G.deckCount[currentPlayer]; i++)
	{
		printf("%s ", cardArr[G.deck[currentPlayer][i]]);
	}

	printf("\nCurrent Hand: ");
	for (int i = 0; i < G.handCount[currentPlayer]; i++)
	{
		printf("%s ", cardArr[G.hand[currentPlayer][i]]);
	}

	for (int i = 0; i < G.handCount[currentPlayer]; i++)
	{
		if (G.hand[currentPlayer][i] == copper || G.hand[currentPlayer][i] == silver || G.hand[currentPlayer][i] == gold)
		{
			treasureCount++;
		}
	}
	printf("\nTreasure card count: %d\n", treasureCount);
	tempTreasureCount = treasureCount;

	printf("\n**** Adventurer card played ****");
	adventurerFunc(&G);

	treasureCount = 0;

	printf("\nDeck: ");
	for (int i = 0; i < G.deckCount[currentPlayer]; i++)
	{
		printf("%s ", cardArr[G.deck[currentPlayer][i]]);
	}

	printf("\nHand: ");
	for (int i = 0; i < G.handCount[currentPlayer]; i++)
	{
		printf("%s ", cardArr[G.hand[currentPlayer][i]]);
	}

	for (int i = 0; i < G.handCount[currentPlayer]; i++)
	{
		if (G.hand[currentPlayer][i] == copper || G.hand[currentPlayer][i] == silver || G.hand[currentPlayer][i] == gold)
		{
			treasureCount++;
		}
	}

	printf("\nTreasure test: ");
	if (treasureCount == tempTreasureCount + 2)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	printf("Treasure card count should be: %d", (tempTreasureCount + 2));
	printf("\nActual treasure card count is: %d", treasureCount);

	return 0;
}