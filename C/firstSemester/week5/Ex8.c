#include<stdio.h>
int main(void)
{
	printf("please enter character");
	char character = getchar();
	(character == 'C')?	printf("upper"):(character == 'c')?printf("lower"):printf("illegal character");
	return 0;
}