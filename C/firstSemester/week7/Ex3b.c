#include<stdio.h>
int main(void)
{
	int num=0;
	
	int digit;
	int evenProduct = 1;
	int oddProduct = 1;
	int countOf1 = 0, countOf2 = 0, countOf3 = 0, countOf4 = 0, 
        countOf5 = 0, countOf6 = 0, countOf7 = 0, countOf8 = 0, countOf9 = 0;
    printf("Please enter a number \n ");
    scanf("%d", &num);

    while (num > 0) {
        digit = num % 10;              

        switch (digit) {
            case 1:
				countOf1++; 
				if(countOf1==1)
				{
					oddProduct*=1;
				}
				break;
            case 2: 
				countOf2++; 
				if(countOf2==1)
				{
					evenProduct*=2;
				}
				break;
			case 3: 
				countOf3++; 
				if(countOf3==1)
				{
					oddProduct*=3;
				}
				break;
            case 4: 
				countOf4++; 
				if(countOf4==1)
				{
					evenProduct*=4;
				}
				break;
            case 5: 
				countOf5++; 
				if(countOf5==1)
				{
					oddProduct*=5;
				}
				break;
            case 6: 
				countOf6++; 
				if(countOf6==1)
				{
					evenProduct*=6;
				}
				break;
            case 7: 
				countOf7++; 
				if(countOf7==1)
				{
					oddProduct*=7;
				}
				break;
            case 8: 
				countOf8++; 
				if(countOf8==1)
				{
					evenProduct*=8;
				}
				break;
            case 9: 
				countOf9++;
				if(countOf9==1)
				{
					oddProduct*=9;
				}
				break;
            default: 
				break;  
        }
		num /= 10;
    }
	printf("Product of distinct even digits is %d",evenProduct);
	printf("Product of distinct odd digits is %d",oddProduct);
	return 0;
}