#include <stdio.h>

//enum sizes {small,medium,LARGE,XLARGE}; //challange
//enum trafficLights {red,yellow,green};
enum difficultyLevel{easy = 1,medium,hard}; //we set the first one equle to one
int main() 
{
	int userChoice;
    printf("Choose the difficulty level:\n");
    printf("%d. Easy\n", easy);
    printf("%d. Medium\n", medium);
    printf("%d. Hard\n", hard);
    printf("Enter your choice: ");
    scanf("%d", &userChoice);
    return 0;
}
