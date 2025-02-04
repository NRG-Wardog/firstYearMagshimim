/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

void myFgets(char str[], int size);
bool isPalindrome(char str[], int beg, int end);
int main(void)
{
	int beg = 0;
	int len = 0;
	char str[SIZE] = { 0 };
	printf("enter word: ");
	myFgets(str, SIZE);


	if (isPalindrome(str, beg, strlen(str) - 2))
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}

	getchar();
	return 0;
}


/*
func check if the str is Palindrome
input:char str[], int beg, int end
output:bool

*/
bool isPalindrome(char str[], int beg, int end)
{
	if (beg >= end) {
		return true;
	}
	if (str[beg] != str[end])
	{
		return false;
	}
	return isPalindrome(str, beg + 1, end - 1);
}

/*
func get strring and deleat enter
input:char str[], int size
output:none
*/
void myFgets(char str[], int size)
{
	int len = 0, i = 0;
	fgets(str, size, stdin);
	len = strlen(str);
	for (i = 0;len < i;i++)
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
		}
	}
}