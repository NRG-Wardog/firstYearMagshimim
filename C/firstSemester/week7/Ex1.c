#include<stdio.h>

int main(void)
{
	int num = 0;
	int i=1;
	int cheakerSum=0;
    printf("enter number: ");
	scanf("%d", &num);
    for(i=1;i<num;i++)
	{
		
		if(num%i==0)
		{
			cheakerSum+=i;
		}
	}
	
	if(cheakerSum==num)
	{
		printf("yes! The number is perfect");
	}
	else
	{
		printf("no! The number isnt perfect");
	}
	return 0;
}