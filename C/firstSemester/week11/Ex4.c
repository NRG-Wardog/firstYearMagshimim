#include <stdio.h>
#include <stdlib.h>
#define ARR_LENGTH 2
/*
Function will change values of array (input from user)
input: array 
output: none
*/
void initArray(int arr[]) //we dont need to return the addres becuse we get it
{
	printf("Enter grades in English and history: ");
	scanf("%d %d", &arr[0], &arr[1]);
}

/*
Function will print two grades
input: the grades to print
output: none
*/
void printGrades(int first, int second)
{
	printf("My grade in English is: %d!\n",first);
	printf("My grade in History is %d! Great Success!\n",second);
}

int main(void)
{
	int myGrades[] = {0,0};
	
	initArray(myGrades);
	
	int first = myGrades[0];//forgot to put 0 for the first place the number that printed before was the addres 
	int second = myGrades[1];	
	
	printGrades(first, second);
	return 0;
}
