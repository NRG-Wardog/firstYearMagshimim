#include<stdio.h>
int main()
{
	int sum =1;
	int i=1;
	int number=0;
	char decision = 'y';
	
	while(decision =='y')
	{
		printf("enter number \n");
		scanf("%d",&number);
		getchar();
		while(number<1)
		{
			printf("Invalid input!");
			printf("enter number \n");
			scanf("%d",&number);
			getchar();
		}		
		for(i=1;i<=number;i++)
		{
			sum = i*i;
			printf("%d  ",sum);
		}
		printf("Would you like to try again? ");
		decision = getchar();
		getchar();
	}
	return 0;
}