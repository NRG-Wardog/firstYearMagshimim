#include <stdio.h>
/*
func replace two numbers
input: two pointers of int
output: none
*/
void swap(float* x, float* y)
{
    float temp = *x;
    *x = *y;
    *y = temp;

}
int main(void)
{
    float a = 0, b = 0;
    printf("enter a and b");
    scanf("%f %f", &a, &b);
    swap(&a, &b);
    printf("swapped: %.2f  %.2f \n", a, b);
    getchar();
    return 0;
}
