#include <stdio.h>
#define SIZE 5 
/*get number to the arr
input:arr and arrlen
output:none

*/
void getNumber(int arr[],int arrLen)
{
	int i=0;
    for (i = 0; i < arrLen; i++)
    {
        printf("Pls enter a num:  \n");
        scanf("%d",&arr[i]);
	}
}

int main()
{
	int offSet=0;
	int index =0;
    int  numbers[SIZE]={0};
	getNumber(numbers,SIZE);
	printf("enter offset : ");
	scanf("%d",&offSet);
	for (int i = 0; i < 5; i++)
    {
        index = (i + offSet) % 5; 
        printf("%d ", numbers[index]);
    }
    return 0;
}