/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
void printBeforeX(int* arr, int n, int* x) 
{
	if (x >= arr && x < arr + n) {
		while (arr != x) {
			printf("%d ", *arr);
			arr++;
		}
		printf("\n");
	}
	else {
		printf("Index %d is out of the array range\n", x - arr);
	}
}
int main(void)
{
	int arr[] = { 4, 8, 6, 2, 1, 3, 5, 7, 8, 9, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int offset;
	printf("Please enter an offset to search in the array’s address domain: ");
	scanf("%d", &offset);

	printBeforeX(arr, size, arr + offset);
	
	getchar();
	return 0;
}