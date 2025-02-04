#include <stdio.h>
#define MONTHS_OF_THE_YEAR 12
//add define for the rate of euro
int main(void)
{
	const float PAID_PER_HOUR = 32.3;
	const float Hours_IN_DAY = 8.5 ;
	const int WORK_IN_MONTH = 20; //Need to change to 24 
	float salary = PAID_PER_HOUR*Hours_IN_DAY*WORK_IN_MONTH*MONTHS_OF_THE_YEAR;//need to multiply by the euro rate
	printf("He will get paid %.2f ", salary);
	return 0; 
}
