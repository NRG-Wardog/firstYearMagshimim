#include <stdio.h>
#define LEGATH_OF_ARR 5 

int main() 
{
	int i=0;
    int  arrHwGrades[LEGATH_OF_ARR]={0};
	for(i=0;i<LEGATH_OF_ARR;i++)
	{
		printf("Enter number place %d : ",i+1);
		scanf("%d",&arrHwGrades[i]);
	}
    return 0;
}