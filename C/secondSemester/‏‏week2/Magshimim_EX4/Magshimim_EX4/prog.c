/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
void swap(float* x, float* y)
{
	float temp = *x;
	*x = *y;
	*y = temp;

}
void check(float* num1, float* num2, float* num3) {
    if (*num2 > *num1) {
        swap(num1, num2);
    }
    if (*num3 > *num2) {
        swap(num2, num3);
    }
    if (*num2 > *num1) {
        swap(num1, num2);
    }
}

int main(void)
{
    float num1, num2, num3;
    printf("Enter three numbers: ");
    scanf("%f %f %f", &num1, &num2, &num3);
    getchar();
    check(&num1, &num2, &num3);
    printf("Numbers in descending order: %.2f %.2f %.2f\n", num1, num2, num3);
    getchar();
    return 0;
}