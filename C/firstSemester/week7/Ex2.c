#include<stdio.h>
#define MIN_WIN 100
#define MIN_LIMIT 1
#define MAX_LIMIT 11
#define PLAYER_NUM 1
int main(void)
{
	int num = 0;
	int lastNum=0;
	int i=PLAYER_NUM;
	printf("player %d please enter a number: ",i);
	scanf("%d", &lastNum);
	while(lastNum<1||lastNum>10)
	{
        printf("This number is illegal!  \n");
		printf("player %d please enter a number: ",i);
		scanf("%d", &lastNum);
	}
	while(num<100)
	{
		if(i%2!=0)
		{
			i=2;
		}
		else
		{
			i=1;
		}
		printf("player %d please enter a number: ",i);
		scanf("%d", &num);
		while(num-lastNum<MIN_LIMIT||num-lastNum>MAX_LIMIT)
		{
			printf("This number is illegal!  \n");
			printf("player %d please enter a number: ",i+1);
			scanf("%d", &num);
		}
		lastNum = num;
	}
	printf("Player %d wins!",i);
	
	return 0;
}