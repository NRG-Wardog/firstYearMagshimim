/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>

void recursivePrintStar(int a);

int main(void)
{
	int a = 0;
	a = 5;
	recursivePrintStar(a);
	getchar();
	return 0;
}




void recursivePrintStar(int a)
{
	int  i = 0;
	if (a > 0)
	{
		for (i = 0;i < a;i++)
		{
			printf("*");
		}
		printf("\n");
		recursivePrintStar(a - 1);
	}
	
}