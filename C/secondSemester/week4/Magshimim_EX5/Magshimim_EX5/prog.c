/*********************************
* Class: MAGSHIMIM C2			 *
* Week 4           				 *
* HW solution   			 	 *
**********************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
Function creates an array
input: number of cells in the array
output: pointer to the new array
*/
int* createArr(int size)
{
	int* pArr = (int*)malloc(sizeof(int) * size);//forgot using int size 
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("Please enter a number for index %d: ", i);
		scanf("%d", pArr + i);//memory leaks using size as place
		getchar();
	}
	return pArr;
}

int main(void)
{
	int size = 0;
	int* pArr = NULL;

	printf("Enter a number of cells: ");
	scanf("%d", &size);//forgot put the address memory leaks using size as place
	getchar();
	pArr = createArr(size);
	printf("The array is at address %p: ", pArr);
	free(pArr);
	getchar();
	return 0;
}
