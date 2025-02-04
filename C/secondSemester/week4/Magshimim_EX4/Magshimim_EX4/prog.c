/*********************************
* Class: MAGSHIMIM C2			 *
* Week 4           				 *
* HW solution   			 	 *
**********************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#define LIMIT 5
#define RESET -1
/*
func check if val is between limit
input:addres of rate
output:none
*/
void checkVal(int* pRate)
{
	while (*pRate < 1 || *pRate > LIMIT)
	{
		printf("valid number enter new number: ");
		scanf("%d", pRate);
		getchar();
	}
}

/*
Function creates an array
input: number of cells in the array
output: pointer to the new array
*/
int* createArr(int size)
{
	int* votes = (int*)malloc(sizeof(int) * size);
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("Please enter rate for person number %d (1-5):  ", i + 1);
		scanf("%d", votes + i);
		getchar();
		checkVal(votes + i);
	}
	return votes;
}



/*
func counting the avrg
intput:int* votes int size
output:avg
*/
float avg(int* votes, int size)
{
	int i = 0;
	int sum = 0;
	for (i = 0;i < size;i++)
	{
		sum += votes[i];
	}
	return ((float)sum) / size;
}

/*
func changeing rate in sp place
intput:int* votes int size
output:none
*/
void changeVal(int* votes, int size)
{
	int place = RESET, rate = 0;
	printf("enter place of rate want to change:");
	scanf("%d", &place);
	getchar();
	while (place<1 || place>size)
	{
		printf("enter place of rate want to change:");
		scanf("%d", &place);
		getchar();
	}
	printf("enter rate:");
	scanf("%d", &rate);
	getchar();
	checkVal(&rate);
	votes[place - 1] = rate;
}

/*
func add rates
intput:int* votes int* size
output:none
*/
void addRates(int* votes, int* size)
{
	int addSize = 0, oldSize = *size, i = 0;
	printf("enter how many new rates:");
	scanf("%d", &addSize);
	getchar();
	*size += addSize;
	votes = (int*)realloc(votes, sizeof(int) * (*size));
	for (i = oldSize; i < *size; i++)
	{
		printf("Please enter rate for person number %d (1-5):  ", i);
		scanf("%d", votes + i);
		getchar();
		checkVal(votes + i);
	}
}
/*
func counting and printing how many votes each rate 1-5
input:int*vote int size
output:none
*/
void print(int* votes, int size)
{
	int rate1 = 0, rate2 = 0, rate3 = 0, rate4 = 0, rate5 = 0, i = 0;
	for (i = 0;i < size;i++)
	{
		switch (votes[i])
		{
		case 1:
			rate1++;
			break;
		case 2:
			rate2++;
			break;
		case 3:
			rate3++;
			break;
		case 4:
			rate4++;
			break;
		case 5:
			rate5++;
			break;
		default:
			break;
		}
	}
	printf("1 - %d \n", rate1);
	printf("2 - %d \n", rate2);
	printf("3 - %d \n", rate3);
	printf("4 - %d \n", rate4);
	printf("5 - %d \n", rate5);

}


int main(void)
{
	int size = 0;
	bool flag = true;
	int* votes = NULL;
	int choice = 0;
	printf("Enter a number of answers: ");
	scanf("%d", &size);
	getchar();
	votes = createArr(size);
	while (flag)
	{
		printf("1 - Calculate average\n2 - Change a score\n3 - Add responders and their scores\n4 - Print scores distribution\n5 - Exit\n");
		printf("enter choice:");
		scanf("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1:
			printf("The avrage is: %.2f \n", avg(votes, size));
			break;
		case 2:
			changeVal(votes, size);
			break;
		case 3:
			addRates(votes, &size);
			break;
		case 4:
			print(votes, size);
			break;
		case 5:
			flag = false;
			break;
		default:
			printf("Error Invalid number");
			break;
		}

	}
	free(votes);
	getchar();
	return 0;
}
