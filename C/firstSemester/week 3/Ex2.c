#include <stdio.h>
int main()
{
	char firstletter = 'A';
	char lastletter = 'Z';
	printf("The first letter is : %c \n",  firstletter);
	printf("The last letter  is : %c \n",  lastletter);
	printf("The letters in the English language calculated by subtracting the two characters is : %d \n",  lastletter-firstletter);
	return 0; 
}
//Calculates the distance between the letters in the ascii table 