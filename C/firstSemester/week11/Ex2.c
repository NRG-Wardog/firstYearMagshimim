#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROLLS 9999
#define NUM_OF_FACES 6
#define MIN_NUMBER_OF_FACE 1
int main() 
{
	int i =MIN_NUMBER_OF_FACE;
	int rolled=0;
    srand(time(NULL));
	int counters[NUM_OF_FACES] = {0};
	for(i =0;i<ROLLS;i++)
	{
		rolled = rand()%(NUM_OF_FACES);
		counters[rolled]+=1;
	}
	for(i=0;i<NUM_OF_FACES;i++)
	{
		printf("The number of rolls in %d is %d \n",i+1,counters[i]);
	}
    return 0;
}