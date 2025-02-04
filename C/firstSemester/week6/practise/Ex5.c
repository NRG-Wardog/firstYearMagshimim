#include<stdio.h>
int main()
{
	int countOfNon=0;
	int countOfPrime=0;
	int number=2;
	int i=2;
	for(number = 2;number<1000;number++)
	{
		for(i = 2;i<number;i++)
			if(number%i==0)
			{
				countOfNon++;
			}
		if(countOfNon==0)
		{
			printf("prime number %d \n",number);
			countOfPrime++;
		}
		countOfNon=0;
	}
	printf("Num of primes %d",countOfPrime);
	return 0;
}