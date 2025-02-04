#include<stdio.h>
void onesTriangle(int size)
{
	int i = 0;
	int j=1;
	for(i =1;i<=size;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d",1);
		}
		printf("\n");
	}
}
int main(void)
{
	int number =0;
	printf("enter triangjal size: \n");
	scanf("%d",&number);
	onesTriangle(number);
	return 0;
}