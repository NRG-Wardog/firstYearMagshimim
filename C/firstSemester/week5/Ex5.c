#include<stdio.h>
int main()
{
	int slices = 0;
	int price=0;
	printf("enter price and slices");
	scanf("%d %d",price,slices);
	if (price < 50&&slices >= 3)
	{
		printf("You should buy this pizza\n");
	}
	else 
	{
		if(slices > 8)
		{
			printf("You should buy this pizza\n");
		}
		else {
		   printf("This pizza it too expensive\n");
		}
	}
	return 0;
}

