/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>

void sqrtNumbersInN(int n) {
    int i = 1;
    while (i * i <= n) //run time o(sqrt(n))
    {
        printf("%d ", i * i);
        i++;
    }
}

int main()
{
    int n = 0;
    printf("enter number:");
    scanf("%d", &n);
    getchar();
    sqrtNumbersInN(n);
    getchar();
    return 0;
}
