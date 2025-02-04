#include <stdio.h>//add
#define RATE_OF_DIRHAM 1.0873 //write what is XXX
int main()
{
  int wallet=1;//change the variable name
  printf("Welcome to United Arab Emirates, how many ILS you have?\n");
  scanf("%d",&wallet); //change to & and the write name
  printf("You have %.2f Dirham\n", wallet*RATE_OF_DIRHAM);//add f
  return 0;//delete an not needed enter
}
