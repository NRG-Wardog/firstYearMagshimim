#include <stdio.h>
#define MAX_NUMBER 10
int main(void)
{
	int myLoopyVar = 1; 
	int sum=1;
	int multiplyBy = 0;
	printf("Daniel Presents: The Board of Multiplication!\n\n");

	for(myLoopyVar=1; myLoopyVar <= MAX_NUMBER; myLoopyVar++)
	{	
		for(multiplyBy = 1; multiplyBy <= MAX_NUMBER; multiplyBy++)
		{
			sum = myLoopyVar * multiplyBy;
			printf("%4d", sum); // Printing multiplication more clear
		}
		printf("\n"); // newline
	} 
	return 0;
}
//have to reset at start ,empty state and mestey number 10 add = to the condition 