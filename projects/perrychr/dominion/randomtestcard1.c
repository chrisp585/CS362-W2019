/****************************************************************************/
/* Tests:  smithy random test                                             */
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

	printf("\n*****************************************************************************************************\n");
	printf("************************************ Test Beginning *************************************************\n");
	printf("*****************             This test the smithy card function.           *************************\n");
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

		struct gameState G;
		int k[10] = { adventurer, sea_hag, embargo, village, minion, mine, cutpurse,
				 baron, tribute, smithy };

		initializeGame(playerNum, k, randSeed, &G);

		returnVal = smithyFunc(-1, &G);

		if (G.handCount[0] == 7)
		{
			passCount++;
		}
		else
		{
			failCount++;
		}

		if (G.playedCardCount == 1)
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