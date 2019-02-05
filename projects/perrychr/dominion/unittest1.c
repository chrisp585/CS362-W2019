/****************************************************************************/
/* Tests:  getCost funtion                                                  */
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

	printf("\n*****************************************************************************************************\n");
	printf("************************************ Test Beginning *************************************************\n");
	printf("****************         This Unit Test is for the getCost function.       **************************\n");
	printf("*****************************************************************************************************\n");
	printf("*****************************************************************************************************\n\n");

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

	for (int i = 0; i < 27; i++) {
		int testValue = getCost(i);

		switch (i)
		{
		case curse:
			if (testValue == 0) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case estate:
			if (testValue == 2) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case duchy:
			if (testValue == 5) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case province:
			if (testValue == 8) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case copper:
			if (testValue == 0) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case silver:
			if (testValue == 3) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case gold:
			if (testValue == 6) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case adventurer:
			if (testValue == 6) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case council_room:
			if (testValue == 5) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case feast:
			if (testValue == 4) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case gardens:
			if (testValue == 4) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case mine:
			if (testValue == 5) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case remodel:
			if (testValue == 4) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case smithy:
			if (testValue == 4) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case village:
			if (testValue == 3) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case baron:
			if (testValue == 4) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case great_hall:
			if (testValue == 3) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case minion:
			if (testValue == 5) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case steward:
			if (testValue == 3) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case tribute:
			if (testValue == 5) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case ambassador:
			if (testValue == 3) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case cutpurse:
			if (testValue == 4) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case embargo:
			if (testValue == 2) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case outpost:
			if (testValue == 5) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case salvager:
			if (testValue == 4) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case sea_hag:
			if (testValue == 4) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		case treasure_map:
			if (testValue == 4) {
				printf("%s cost passed\n", cardArr[i]);
			}
			else {
				printf("%s cost failed\n", cardArr[i]);
			}
			break;
		}
	}
	
	printf("\n*****************************************************************************************************\n");
	printf("************************************ Testing Complete ***********************************************\n");
	printf("*****************************************************************************************************\n");

	return 0;
}