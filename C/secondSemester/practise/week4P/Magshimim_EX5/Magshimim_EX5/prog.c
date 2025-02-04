/*********************************
* Class: MAGSHIMIM C2			 *
* Week 2           				 *
* HW solution 			 		 *
**********************************/

#include <stdio.h>
/*
func adding in the addres of sum valu of two number 
input:int* x/y/sum
output:none

*/
void add(int* x, int* y, int* sum)
{
	*sum = *x + *y;//when you are using  place in memmory dont forget about  it
}
int main(void)
{
	int a = 0, b = 0, sum = 0;
	int* c = &b;//using addres always dont forget
	printf("Enter two numbers: ");
	scanf("%d %d", &a, &b);
	getchar();
	add(&a, c, &sum);//if c give addres you dont give  the ad for the ad
	printf("The sum of a and b is: %d", sum);
	getchar();
	return 0;
}


//remmber where do you put as a addres for and when as number