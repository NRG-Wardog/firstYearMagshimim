#include<stdio.h>
int main()
{
    int choice=0;
	int a = 0;
    int b = 0;
    int sum =0;
    int subtracting=0;
    int multiplying = 0;
	float dividing =0.0;
    printf("Enter two numbers: ");
    scanf("%d", &a);
    scanf("%d", &b);
    sum = a + b;
    subtracting = a - b;
    multiplying = a * b;
    dividing = (a*1.0) / b;
	printf("1. Adding %d + %d\n", a, b);
    printf("2. Subtracting %d - %d\n", a, b);
    printf("3. Multiplying %d * %d\n", a, b);
    printf("4. Dividing %d / %d\n", a, b);
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
	 switch (choice) {
        case 1:
            printf("Adding %d+%d = %d\n", a, b, sum);
        case 2:
            printf("Subtracting %d-%d = %d\n", a, b, subtracting);
        case 3:
            printf("Multiplying %d*%d = %d\n", a, b, multiplying);
        case 4:
            if (b != 0) {
                printf("Dividing %d/%d = %.2f\n", a, b, dividing);
            } else {
                printf("Can't divide by zero!!!\n");
            }
            break;
        default:
            printf("Choice is not valid\n");
    }
	return 0;
}