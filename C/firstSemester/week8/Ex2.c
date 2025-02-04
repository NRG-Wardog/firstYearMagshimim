#include<stdio.h> 
#include <math.h>
//didnt wrote include and magic number.

void sumOf(int firstNumber,int q,int n) 
{
    int sum =0;
    if(q!=1)
    {
        sum=(firstNumber)*(pow (q,n) -1)/((q-1)*1.0);
    }
    else
    {
        sum=firstNumber*n;
    }
    printf("%d",sum);
}
int main(void)
{
	int firstNum = 0;
	int q = 0;
	int n =0;
	printf("Enter first element of the series:");
	scanf("%d",&firstNum);
	printf("Enter the series ratio:");
	scanf("%d",&q);
	printf("Enter number of elements:");
	scanf("%d",&n);
	sumOf(firstNum,q,n);
	return 0;
}

