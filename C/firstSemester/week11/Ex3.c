#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define NUM_GUESTS 200
#define FALSE 	0
#define TRUE !FALSE

/*
Function will return average age of party guests
input: age array, number of guests
output: average age
*/
float averageAge(int ages[], int size)
{
	float avg = 0;
	int i =0;
	for(i=0;i<size;i++)
	{
		avg +=ages[i];
	}
	avg /=size;
	return avg;
}
/*
Function will return teanagers  Under 12
input: age array, number of guests
output: teanagers Under 12
*/
int teanagersUnder12(int ages[], int size)
{
	int counterOfTean = 0;
	int i =0;
	for(i=0;i<size;i++)
	{
		if(ages[i]<=12)
		{
			counterOfTean++;
		}
	}
	return counterOfTean;
}
/*
Function will return if found the searce age
input: age array, number of guests , searce age
output: checkAgeSearce
*/
bool checkAge(int ages[], int size,int ageSearce)
{
	bool checkAgeSearce = false;
	int i =0;
	for(i=0;i<size;i++)
	{
		if(ages[i]==ageSearce)
		{
			checkAgeSearce = true;
		}
	}
	return checkAgeSearce;
}
/*
Function will return if found the  2 searce age
input: age array, number of guests , searce age
output: checkAgeSearce
*/
bool checkAgeFriend(int ages[], int size,int ageSearce)
{
	bool checkAge = false;
	int checkAgeSearce=0;
	int i =0;
	for(i=0;i<size&&checkAgeSearce!=2;i++)
	{
		if(ages[i]==ageSearce)
		{
			checkAgeSearce++;
		}
		if(checkAgeSearce==2)
		{
		checkAge=true;
		}
	}
	return checkAgeSearce;
}
/*
Function will return if max age
input: age array, number of guests
output: max age
*/
int maxNumber(int ages[], int size)
{
	int i =0;
	int max = ages[0];
	for(i=1;i<size;i++)
	{
		if(ages[i]>max)
		{
			max = ages[i];
		}
	}
	return max;
}
/*
Function will return if min age
input: age array, number of guests
output: min age
*/
int minNumber(int ages[], int size)
{
	int min = ages[0];
	int i =0;
	for(i=1;i<size;i++)
	{
		if(ages[i]<min)
		{
			min = ages[i];
		}
	}
	return min;
}
int main(void)
{
	float average=0;
	int teanUnder12=0;
	int maxAge=0;
	int minAge=0;
	int ageSearce=0;
	int guestAges[NUM_GUESTS] = {42, 108, 95, 101, 90, 5, 79, 79, 83, 105, 66, 66, 2, 28, 2, 12, 116, 63, 28, 37,	
					 112, 85, 63, 34, 53, 23, 22, 117, 39, 96, 48, 7, 12, 19, 70, 113, 108, 20, 116,
					 55, 24, 52, 3, 94, 34, 105, 22, 32, 54, 29, 108, 45, 23, 118, 118, 20, 84, 22,
					 50, 59, 77, 36, 111, 43, 49, 107, 41, 63, 65, 89, 87, 46, 51, 10, 11, 111, 7, 22,
					 34, 69, 70, 24, 85, 35, 37, 81, 47, 57, 12, 29, 25, 40, 27, 44, 18, 59, 39, 43, 
					 10, 102, 34, 36, 80, 19, 25, 91, 100, 27, 114, 67, 102, 66, 45, 113, 31, 70, 18, 
					 94, 58, 73, 107, 91, 42, 37, 36, 48, 16, 95, 72, 53, 111, 71, 22, 5, 47, 71, 28, 
					 72, 8, 58, 98, 48, 34, 64, 66, 30, 50, 39, 102, 109, 63, 107, 27, 71, 94, 9,
					 61, 72, 43, 96, 11, 120, 25, 18, 69, 4, 116, 82, 3, 111, 92, 117, 15, 101, 37, 22, 
					 109, 40, 109, 5, 2, 55, 54, 80, 19, 99, 61, 69, 8, 108, 9, 14, 49, 44, 48, 22, 
					 31, 18, 14, 35};
	average=averageAge(guestAges,NUM_GUESTS);
	printf("average age : %.2f \n",average);
	teanUnder12= teanagersUnder12(guestAges,NUM_GUESTS);
	printf("Number of kids 12 and under: %d \n",teanUnder12);
	printf("Enter age to searce : \n");
	scanf("%d",&ageSearce);
	if(checkAge(guestAges,NUM_GUESTS, ageSearce))
	{
		printf("guest found! \n");
	}
	else
	{
		printf("No guest this age. \n");
	}
	printf("Enter age of looking for friend : \n");
	scanf("%d",&ageSearce);
	if(checkAgeFriend(guestAges,NUM_GUESTS, ageSearce))
	{
		printf("A couple in the same age was found \n");
	}
	else
	{
		printf("no couples found... \n");
	}
	maxAge= maxNumber(guestAges,NUM_GUESTS) ;
	minAge= minNumber(guestAges,NUM_GUESTS) ;
	printf("Youngest guest age : %d \n",minAge);
	printf("Oldest guest age : %d",maxAge);
	return 0;
}

