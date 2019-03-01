/****************************************************************************/
/* Tests:  whoseTurn funtion                                                */
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
	int turn;
	struct gameState G;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
			 sea_hag, tribute, smithy };

	playerNum = 4;

	initializeGame(playerNum, k, 2, &G);

	printf("\n*****************************************************************************************************\n");
	printf("************************************ Test Beginning *************************************************\n");
	printf("** This unit test, test to make sure the whoseTurn function is returning the correct players turn ***\n");
	printf("*****************************************************************************************************\n");
	printf("*****************************************************************************************************\n\n");


	printf("Check turn right after game initialization: ");
	if (whoseTurn(&G) == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
		printf("Turn: %d", whoseTurn(&G));
	}

	turn = 3;
	G.whoseTurn = 3;

	printf("Now it is player %d's turn: ", turn);
	if (whoseTurn(&G) == turn)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
		printf("Turn: %d", whoseTurn(&G));
	}

	turn = 2;
	G.whoseTurn = 2;

	printf("Now it is player %d's turn: ", turn);
	if (whoseTurn(&G) == turn)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
		printf("Turn: %d", whoseTurn(&G));
	}

	turn = 1;
	G.whoseTurn = 1;

	printf("Now it is player %d's turn: ", turn);
	if (whoseTurn(&G) == turn)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
		printf("Turn: %d", whoseTurn(&G));
	}

	printf("\n*****************************************************************************************************\n");
	printf("************************************ Testing Complete ***********************************************\n");
	printf("*****************************************************************************************************\n");

	return 0;
}