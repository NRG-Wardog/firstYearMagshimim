#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
check if the number are Meets the conditions
input: The 3 number
output:1/0
*/
int areValidNumbers(int num1, int num2, int num3)
{
	int ans = 0;
    if((num1%2==0||num2%2==0||num3%2==0)&&(num2%2==1||num1%2==1||num3%2==1)&&(num3>50||num2>50||num3>50))
	{
		ans=1;
	}
	return ans;
}



int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	srand(time(NULL));
	do
	{
		num1 = rand()%101;
		num2 = rand()%101;
		num3 = rand()%101;
	}while(areValidNumbers(num1,num2,num3)!=1);
	printf("The number work are : %d ,%d ,%d",num1,num2,num3);
	return 0;
}

