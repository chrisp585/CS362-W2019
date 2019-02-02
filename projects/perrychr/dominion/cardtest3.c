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

	int playerNum;
	struct gameState G;
	int k[10] = { adventurer, sea_hag, embargo, village, minion, mine, cutpurse,
			 baron, tribute, smithy };
	playerNum = 4;

	initializeGame(playerNum, k, 2, &G);
	G.whoseTurn = 1;
	int currentPlayer = G.whoseTurn;

	sea_hagFunc(&G);

	printf("This tests the sea_hagFunc function.");

	for (int i = 0; i < G.numPlayers; i++)
	{
		if (i != currentPlayer)
		{
			printf("\n\n**** Player  %d ****\n", i);
			printf("Current Deck: ");
			for (int j = 0; j < G.deckCount[i]; j++)
			{
				printf("%s ", cardArr[G.deck[i][j]]);
			}
			printf("\nCurse on top of the deck: ");
			if (G.deck[i][G.deckCount[i]--] == curse)
			{
				printf("PASS\n");
			}
			else
			{
				printf("FAIL\n");
				printf("Top card on the deck is: %s", cardArr[G.deck[i][G.deckCount[i]--]]);
			}
		}
	}

	return 0;
}