#include<stdio.h>
int main()
{
	int number=0;
	int mewNumber=0;
	printf("enter number");
	scanf("%d",&number);
	while(number<0)
	{
		printf("enter number");
		scanf("%d",&number);
	}
	printf("original number: %d \n",number);
	while(number>0)
	{
		if(number<100&&number%10==0)
		{
			mewNumber=number/10;
			number=0;
		}
		mewNumber=(mewNumber)*10+(number%10);
		number=(number-(number%10))/10;
	}
	printf("after reverse : %d",mewNumber);
	
	return 0;
}