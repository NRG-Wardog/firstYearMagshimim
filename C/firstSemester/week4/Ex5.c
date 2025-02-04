#include <stdio.h>//add
int main()
{
  char firstLetter=' ' ;
  char secondLetter=' ' ;
  char thirdLetter=' ' ;
  printf("enter the first letter:");
  scanf("%c",&firstLetter);
  getchar();
  printf("enter the second letter:");
  scanf("%c",&secondLetter);
  getchar();
  printf("enter the third letter:");
  scanf("%c",&thirdLetter);
  printf("The name is %c%c%c",firstLetter,secondLetter,thirdLetter );
  return 0;
}
