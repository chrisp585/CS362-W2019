/****************************************************************************/
/* Tests:  sea hag random test                                             */
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
	printf("****************             This tests the sea_hagFunc function.           *************************\n");
	printf("*****************************************************************************************************\n");
	printf("*****************************************************************************************************\n\n");

	int randNum2 = (rand() % (1000000 - 500000 + 1)) + 500000;
	int returnVal;
	int failCount = 0;
	int passCount = 0;

	int k;
	for (k = 0; k < randNum2; k++)
	{
		int playerNum = (rand() % (4 - 2 + 1)) + 2;
		int randSeed = (rand() % (30 - 1 + 1)) + 1;

		//int playerNum;
		struct gameState G;
		int k[10] = { adventurer, sea_hag, embargo, village, minion, mine, cutpurse,
				 baron, tribute, smithy };
		playerNum = 4;

		initializeGame(playerNum, k, randSeed, &G);
		G.whoseTurn = 1;
		int currentPlayer = G.whoseTurn;

		sea_hagFunc(&G);

		for (int i = 0; i < G.numPlayers; i++)
		{
			if (i != currentPlayer)
			{
				if (G.deck[i][G.deckCount[i]--] == curse)
				{
					passCount++;
				}
				else
				{
					failCount++;
				}
			}
		}
	}

	printf("                      Passing tests: %d\n", passCount);
	printf("                      Failing tests: %d\n\n", failCount);
	printf("\n*****************************************************************************************************\n");
	printf("************************************ Testing Complete ***********************************************\n");
	printf("*****************************************************************************************************\n");


	return 0;
}