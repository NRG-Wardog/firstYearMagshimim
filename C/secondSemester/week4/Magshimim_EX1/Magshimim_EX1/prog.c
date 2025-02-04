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


	int* px = (int*)malloc(sizeof(int) * size);
	free(px);
	printf("Leaks: %d\n", _CrtDumpMemoryLeaks());
	getchar();
	return 0;
}
















//	printf("enter size");
//scanf("%d", &size);
//getchar();