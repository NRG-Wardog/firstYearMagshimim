#include<stdio.h>
int main() 
{
    const int minAge = 16;
    const int maxAge = 18;
    int age = 0;
    printf("Enter age: ");
    scanf("%d", &age);
    if (!(age >= minAge && age <= maxAge))
	{
        printf("Yay! Your age is not between 16-18.\n");
		printf("you can have phone");
    }
	else 
	{
        printf("Sorry, no phone for you.\n");
    }
    return 0;
}
