/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#define SIZE 8
void arrayInput(int arr[], int size)
{
	int* pArr = arr;
	printf("enter 8 numbers: ");
	scanf("%d %d %d %d %d %d %d %d", pArr,pArr+1, pArr + 2, pArr + 3, pArr + 4, pArr + 5, pArr + 6, pArr + 7);
	getchar();
}
void arrayEvenElements(int arr[], int size)
{
	int i = 0;
	int* pArr = arr;
	printf("The numbers in even indexes are: ");
	for (i = 0;i < size;i++)
	{
		if (i % 2 == 0)
		{
			printf("%d ", *(pArr + i));
		}
	}
}



int main(void)
{

	int arr[SIZE] = { 0 };
	arrayInput(arr,SIZE);
	arrayEvenElements(arr, SIZE);
	getchar();
	return 0;
}