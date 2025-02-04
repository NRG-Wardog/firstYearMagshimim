#include<stdio.h>
int main(void)
{
	printf("please enter character");
	char character = getchar();
	if(character == 'C')
	{
		printf("upper");
	}
	else if(character == 'c')
	{
		printf("lower");
	}
	else 
	{
		printf("illegal character");
	}
	return 0;
}