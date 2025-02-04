#include<stdio.h> 
#include <math.h>
#define PIE 3.14
void circleCaclater()
{
	float radios=0;
	float area=0;
	float scope=0;
	printf("enter radios");
	scanf("%f",&radios);
	area = PIE*radios*radios;
	scope = 2*PIE*radios;
	printf("the scope is %.2f \n the area is : %.2f \n",scope,area);
}
void rectangleAREA()
{
	float hight=0;
	float base=0;
	float area=0;
	printf("enter hight and base");
	scanf("%f",&hight);
	scanf("%f",&base);
	area = hight*base;
	printf("The area of the square is %.2f  \n",area);
}
void squareAREA()
{
	float hight=0;
	float area=0;
	printf("enter hight");
	scanf("%f",&hight);
	area = hight*hight;
	printf("The area of the square is %.2f \n",area);
}
void lengthThred()
{
	int standsOne=0;
	int standsSec=0;
	float RightTrian=0;
	printf("enter stands 1 and 2");
	scanf("%d",&standsOne);
	scanf("%d",&standsSec);
	RightTrian =pow(pow(standsOne,2.0)+pow(standsSec,2.0),0.5);
	printf("the distance %.2f  \n ",RightTrian);
}
void distanceTwoPoints() 
{
    float distance=0;
	int xFirst =0;
	int yFirst=0;
	int xSec =0;
	int ySec=0;
    printf("enter x1 and y1");
	scanf("%d",&xFirst);
	scanf("%d",&yFirst);
	printf("enter x1 and y1");
	scanf("%d",&xSec);
	scanf("%d",&ySec);
	distance=pow((pow(xFirst-xSec,2)+pow(yFirst-ySec,2)),0.5);
	printf("the distance %.2f /n",distance);
}
int main(void)
{
	int choice = 0;
	while(choice!=6)
	{
		printf("(1) Calc the distance between 2 points. \n (2) Calc the excess length in a right triangle. \n (3) Calc the area and perimeter of a circle. \n (4) Calc the area of ​​a square.  \n (5) Calc the area of ​​a rectangle \n (6) Exit. \n");
		printf("Enter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				distanceTwoPoints();
				break;
			case 2:
				lengthThred();
				break;
			case 3:
				circleCaclater();
				break;
			case 4:
				rectangleAREA();
				break;
			case 5:
				squareAREA();
				break;
			default:
				break;
		}
    }
	return 0;
}