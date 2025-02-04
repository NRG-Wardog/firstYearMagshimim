#include<stdio.h>
int main()
{
	int i=1;
	int g=1;
	int number=0;
	
	printf("enter number 1-9 \n");
	scanf("%d",&number);
	while(number<1||number>9)
	{
		printf("Invalid input! 1-9 only");
		printf("enter number 1-9 \n");
		scanf("%d",&number);
	}		
	for(i=1;i<=number;i++)
	{
		for(g=1;g<=i;g++)
		{
			printf("%d  ",i);
		}
		printf("\n");
	}
	return 0;
}