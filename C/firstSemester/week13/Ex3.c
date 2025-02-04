#include <stdio.h>
#include <string.h>
#define SEATS_IN_ROW 50
#define ROW 10

/*
run all array and get len of the longest one
Input: 	names, and number of rows 
Output: None
*/
void longName(char names[][SEATS_IN_ROW],int row)
{
	int i =0;
	int max=0;
	for(i=1;i<row;i++)
	{
		if(strlen(names[max])<strlen(names[i]))
		{
			max = i;
		}
	}
	printf("longest: %s \n",names[max]);
}

/*
run all array and get len of the shortest one
Input: 	names, and number of rows 
Output: None
*/
void shortName(char names[][SEATS_IN_ROW],int row)
{
	int i =0;
	int shorts=0;
	for(i=1;i<row;i++)
	{
		if(strlen(names[shorts])>strlen(names[i]))
		{
			shorts = i;
		}
	}
	printf("shortest : %s \n",names[shorts]);
}

/*
run all array and get first letter and smalls
Input: 	names, and number of rows 
Output: None
*/
void firstInAlp(char names[][SEATS_IN_ROW],int row)
{
	int i =0;
	int firstLetterPlace=0;
	for(i=1;i<row;i++)
	{
		if(names[firstLetterPlace][0]>names[i][0])
		{
			firstLetterPlace = i;
		}
	}
	printf("first: %s \n",names[firstLetterPlace]);
}

/*
run all array and get first letter and last
Input: 	names, and number of rows 
Output: None
*/
void lastInAlp(char names[][SEATS_IN_ROW],int row)
{
	int i =0;
	int firstLetterPlace=0;
	for(i=1;i<row;i++)
	{
		if(names[firstLetterPlace][0]<names[i][0])
		{
			firstLetterPlace = i;
		}
	}
	printf("last: %s \n",names[firstLetterPlace]);
}
int main()
{
	char names[ROW][SEATS_IN_ROW] ={0};
    int i = 0;
	printf("enter 10 names:");
	for (i = 0; i < ROW; i++) 
	{
        fgets(names[i], SEATS_IN_ROW, stdin);
		names[i][strcspn(names[i], "\n")] = 0;
    }
	shortName(names,ROW);
	longName(names,ROW);
	firstInAlp(names,ROW);
	lastInAlp(names,ROW);	
    return 0;
}