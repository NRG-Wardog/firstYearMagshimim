/*********************************
* Class: MAGSHIMIM C2			 *
* Week 1           				 *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#define START_BOB 50
#define START_UMM 100
#define START_JANI 10
#define START_JOHNNY 90
#define START_DUDU 12

int main(void)
{
	int bobDylan = START_BOB;
	int ummKulthum = START_UMM;
	int janisJoplin = START_JANI;//forgot ';'
	int johnnyCash = START_JOHNNY;//del  indation
	int* duduTasa = START_DUDU;
																// bobDylan | ummKulthum  |  janisJoplin  | johnnyCash
																// --------   -----------   -------------   ---------------
	johnnyCash /= 3;											//    50    |     100     |       10      |        30
	bobDylan = ummKulthum + janisJoplin++ * 4;					//   140   |     100     |      11     |       30
	bobDylan += --johnnyCash + janisJoplin + 2 * ummKulthum;	//   380   |     100     |      11     |       29

	printf("How many roads must a man walk down before you can call him a man?\n");
	printf("The answer my friend, is %d\n", bobDylan);//wrong symbol d(int) not s(tring)
	getchar();
	return 0;
}