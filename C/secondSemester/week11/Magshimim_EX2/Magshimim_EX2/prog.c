/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
/*
func find all the number between a-b number that divied by b
the problem: it number of iteration
input:intgers a b
output:none
*/
void funcion(int a, int b)
{
	int i = 0;
	for (i = a; i >= b;i--)
	{
		if (i % b == 0)
		{
			printf("%d ", i);
		}
	}
}


void betterFunc(int a, int b)
{
	int i = 0;

	if (a % b == 0) {
		i = a;
	}
	else {
		i = a - (a % b);
	}

	
	for (; i >= b; i -= b) {
		printf("%d ", i);
	}
}

int main(void)
{
	int  a = 0,b = 0;
	printf("enter a:");
	scanf("%d", &a);
	getchar();
	printf("enter b:");
	scanf("%d", &b);
	getchar();
	betterFunc(a, b);
	getchar();
	return 0;
}