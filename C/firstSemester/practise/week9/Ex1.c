#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int roll(int sides)
{
	srand(time(NULL));
	int ranNum = (rand()%sides)+1;
	return ranNum;
}
int main()
 {
    int sides=0;
	do{
		printf("enter sides number \n");
		scanf(" %d",&sides);
	}while(sides<1);
	printf("the random number is: %d",roll(sides));
    return 0;
}