#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 50
#define LETTERS_IN_ALPABAT 26
#define TAKE_ASCII_DOWN 97
#define MAX_ASCII_LETT 122
/*
fun find qho is sec and first  commond letter in the string and replace each other
input: arr
output:none
*/
void encryption(char arr[])
{
	int mostCommon = 0;
	int placeMostCommon=0;
	int placeSecMost=1;
	int alpahBat[LETTERS_IN_ALPABAT] = {0};
	int i = 0,j,k;
	int secMostCommon = 0;
	char charMostCOM= ' ';
	char secCharMostCOM= ' ';
	for(i=0;i<SIZE;i++)
	{
		if(arr[i]>=TAKE_ASCII_DOWN&&arr[i]<=MAX_ASCII_LETT)
		{
			alpahBat[arr[i]-TAKE_ASCII_DOWN]+=1;
		}
	}
	mostCommon=alpahBat[0];
	secMostCommon=alpahBat[1];
	for(j=1;j<LETTERS_IN_ALPABAT;j++)
	{
		if(alpahBat[j]>mostCommon)
		{
			placeSecMost=placeMostCommon;
			secMostCommon=mostCommon;
			placeMostCommon=j;
			mostCommon=alpahBat[j];
		}
	}
	charMostCOM = (char)(placeMostCommon+TAKE_ASCII_DOWN);
	secCharMostCOM = (char)(placeSecMost+TAKE_ASCII_DOWN);
	for(k=0;k<SIZE;k++)
	{
		if(arr[k]==charMostCOM)
		{
			arr[k] = secCharMostCOM;
		}
		else if(arr[k]==secCharMostCOM)
		{
			arr[k] = charMostCOM;
		}
	}
	printf("most commom is %c and sec most is %c \n",charMostCOM,secCharMostCOM);
	printf("swapped: \n");
	printf("%s",arr);
}
int main() 
{
    int num = 0;
    char str[SIZE] = {0};
    printf("Enter string: ");
    fgets(str, SIZE, stdin);
	str[strcspn(str, "\n")] = '\0';
	encryption(str);	
    return 0;
}