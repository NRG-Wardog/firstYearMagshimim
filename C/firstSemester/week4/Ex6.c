#include <stdio.h>
#define YEAR_TODAY 2023
int main()
{
  char firstLetter=' ' ;
  char secondLetter=' ' ;
  char thirdLetter=' ' ;
  int yearBorn = 0;
  int numberChoose = 0 ;
  int sum = 0;
  float sum_divaid = 0;
  float sumFloat=1.0;
  printf("enter the first letter:");
  scanf("%c",&firstLetter);
  getchar();
  printf("enter the second letter:");
  scanf("%c",&secondLetter);
  getchar();
  printf("enter the third letter:");
  scanf("%c",&thirdLetter);
  printf("hey %c%c%c ,what year were you born?",firstLetter,secondLetter,thirdLetter );
  scanf("%d",&yearBorn);
  getchar();
  printf("please choose any number you would like from 1-100?");
  scanf("%d",&numberChoose);
  sum = YEAR_TODAY - yearBorn ;
  printf("you are %d year old",sum);
  sumFloat = (float)sum;
  sum_divaid = sumFloat/numberChoose;
  printf("  %d %% %d  = %.2f ",sum,numberChoose,sum_divaid);
  return 0;
}
