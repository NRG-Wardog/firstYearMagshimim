#include <stdio.h>
int main()
{
	char firstLetter = 'H';
	char secondLetter = ' ';
	char lastLetter = ' ';
	printf("enter sec char");
	secondLetter = getchar();
	printf("The last char ");
	scanf(" %c", &lastLetter);
	char sumOfFirstLetter =firstLetter+1 ;
	int sumOfLetters =  secondLetter+lastLetter+firstLetter ;
	int sumOfLettersEdge = lastLetter+firstLetter ;
	printf("The first char: %c and the first char plus one is : %c \n", firstLetter ,sumOfFirstLetter);
	printf("The first letter number  is : %d \n",(int)firstLetter); //The number in the ascii for the last letter
	printf("The sum of thr letters number ascii : %d \n", sumOfLetters); //The ascii number of sum of the letters
	printf("The sum of the first and last letters number ascii : %d \n", sumOfLettersEdge);//The ascii number of the sum of the edge numbers
	return 0; 
}
 