#include <stdio.h>
#define START 1
#define SEATS_IN_ROW 10
#define ROW 10

int main()
{
	int bored[SEATS_IN_ROW][ROW] ={0};
    int i = START;
	int j  = START;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<SEATS_IN_ROW;j++)
		{
			bored[i][j]=(j+1)*(i+1);
			printf("%d   ",bored[i][j]);
		}
		printf(" \n");
	}
    return 0;
}