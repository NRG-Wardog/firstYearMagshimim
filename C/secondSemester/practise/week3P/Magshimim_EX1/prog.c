/*********************************
* Class: MAGSHIMIM C2			 *
* Week 1           				 *
**********************************/

#include <stdio.h>
#include <stdlib.h>

int findFirstNonZero(int a[], int  n)
{
	int* p = a;
	while(p< a+n && *p ==0)
	{
		p++;
	}

	return p-a
}




int main(void)
{
	int arr[] = {1,2,3};
	printf("%d",findFirstNonZero(arr));
	getchar();
	return 0;
}