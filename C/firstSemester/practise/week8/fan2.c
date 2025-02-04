#include<stdio.h>
void addAndPrint(int x,int y)
{
	int sum = x+y;
	printf("x+y = %d".sum);
}
void subAndPrint(int x,int y)
{
	y=0-y;
	addAndPrint(x,y);
}
int main(void)
{
	int x =0;
	int y =0;
	printf("enter two numbers: \n");
	scanf("%d",&x);
	scanf("%d",&y);
	addAndPrint(x,y);
	subAndPrint(x,y);
	return 0;
}