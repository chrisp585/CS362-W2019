/****************************************************************************/
/* Tests:  adventurer random test                                          */
/* Christopher Perry                                                        */
/* CS 362  2/22/2019                                                         */
/****************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

int main()
{
	srand(time(NULL));

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

	printf("\n*****************************************************************************************************\n");
	printf("************************************ Test Beginning *************************************************\n");
	printf("**************             This tests the adventurerFunc function.           ************************\n");
	printf("*****************************************************************************************************\n");
	printf("*****************************************************************************************************\n\n");

	int randNum2 = (rand() % (1000000 - 500000 + 1)) + 500000;
	int returnVal;
	int failCount = 0;
	int passCount = 0;

	int i;
	for (i = 0; i < randNum2; i++)
	{
		int playerNum = (rand() % (4 - 2 + 1)) + 2;
		int randSeed = (rand() % (30 - 1 + 1)) + 1;

		int treasureCount = 0;
		struct gameState G;
		int k[10] = { adventurer, sea_hag, embargo, village, minion, mine, cutpurse,
				 baron, tribute, smithy };

		initializeGame(playerNum, k, randSeed, &G);
		int currentPlayer = G.whoseTurn;
	

		int j;

			for (int i = 0; i < G.handCount[currentPlayer]; i++)
			{
				if (G.hand[currentPlayer][i] == copper || G.hand[currentPlayer][i] == silver || G.hand[currentPlayer][i] == gold)
				{
					treasureCount++;
				}
			}

			int tempTreasureCount = treasureCount;
			treasureCount = 0;

			returnVal = adventurerFunc(&G);

			for (int i = 0; i < G.handCount[currentPlayer]; i++)
			{
				if (G.hand[currentPlayer][i] == copper || G.hand[currentPlayer][i] == silver || G.hand[currentPlayer][i] == gold)
				{
					treasureCount++;
				}
			}
			if (treasureCount >= (tempTreasureCount + 3))
			{
				passCount++;
			}
			else
			{
				failCount++;
			}

	}
	printf("                      Passing tests: %d\n", passCount);
	printf("                      Failing tests: %d\n\n", failCount);
	printf("\n*****************************************************************************************************\n");
	printf("************************************ Testing Complete ***********************************************\n");
	printf("*****************************************************************************************************\n");

	return 0;
}
