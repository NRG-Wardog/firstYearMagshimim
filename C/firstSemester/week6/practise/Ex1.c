#include<stdio.h>
#define MAX_NUM 1000
#define MIN_NUM 1

int main(void)
{
	int num = 0;
	do 
	{
        printf("Please enter number between 1-1000: ");
		scanf("%d", &num);
    }while(num > MAX_NUM || num < MIN_NUM ||num%2==1);
	printf("you enter right number");
	return 0;
}