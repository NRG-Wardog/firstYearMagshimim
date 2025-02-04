#include <stdio.h>
int main()
{
	int integerNumber = 10;
	float decimalNumber = 3.5;
	printf("The integer number is : %d \n",  integerNumber);
	printf("The decimal number is : %.2f \n",  decimalNumber);
	printf("The product of a decimal number by a whole number is %.2f \n",  integerNumber*decimalNumber);
	return 0; 
}