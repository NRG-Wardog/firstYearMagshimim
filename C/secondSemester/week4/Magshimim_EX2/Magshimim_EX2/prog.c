/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <stdlib.h>
/*
func sorting the array by buble sort
input:parr ,size
output:none
*/
void sortBuble(int* parr, int size)
{
    int i = 0, j = 0, temp = 0;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (parr[j] > parr[j + 1])
            {
                temp = parr[j];
                parr[j] = parr[j + 1];
                parr[j + 1] = temp;
            }
        }
    }
}

/*
func print the array
input:parr ,size
output:none
*/
void printArr(int* parr, int size)
{
    int i = 0;
    printf("Sorted array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", parr[i]);
    }

}

/*
func create the array
input:parr ,size
output:none
*/
void createArr(int* parr, int size)
{
    int i = 0;
    printf("enter %d numbers \n", size);
    for (i = 0;i < size;i++)
    {
        scanf("%d", &parr[i]);
        getchar();
    }
    printf("\n")
}

int main(void)
{
    int size = 0;
    printf("enter size");
    scanf("%d", &size);
    getchar();
    int* parr = (int*)malloc(sizeof(int) * size);
    createArr(parr, size);
    sortBuble(parr, size);
    printArr(parr, size);
    free(parr);
    getchar();
    return 0;
}