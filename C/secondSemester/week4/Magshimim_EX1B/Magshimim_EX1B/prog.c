/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int size = 3;
	printf("enter size");
	scanf("%d", &size);
	getchar();
	int* px = (int*)malloc(sizeof(int) * size);
	free(px);
	getchar();
	return 0;
}