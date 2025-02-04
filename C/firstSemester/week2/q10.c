#include <stdio.h>
int main(void)
{
	int AgeOfGrandmother  = 80;
	int AgeOfGrandfather  = 83;
	int AgeogCousin1 = 2;
	int AgeogCousin2 = 23;
	int AgeogCousin3 = 15;
	int AgeogCousin4 = 11;
	int SumOfAgesGrandparents = AgeOfGrandfather+AgeOfGrandmother;
	int SumOfAgesCousins = AgeogCousin1 + AgeogCousin2 +AgeogCousin3 + AgeogCousin4;
	printf("Cousins ages are %d ,%d,%d,%d \n",AgeogCousin1 ,AgeogCousin2 ,AgeogCousin3,AgeogCousin4);
	printf("Grandparents ages are %d ,%d \n",AgeOfGrandfather,AgeOfGrandmother);
	printf("the sum of the ages of Grandparents is %d\n ",SumOfAgesGrandparents);
	printf("the sum of the ages of Cousins is %d \n ",SumOfAgesCousins);
	return 0;
}