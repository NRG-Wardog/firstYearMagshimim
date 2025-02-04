#include<stdio.h> 
#include <math.h>
#define PIE 3.14
/*caclating area of circle  and return it
input:radios
output:area of circle
*/
float circleAreaCaclater(int radios)
{
	float area=0;
	area = PIE*radios*radios;
	return area;
}
/*caclating scope of circle and return it
input:radios
output:scope of circle
*/
float circleScopeCaclater(int radios)
{
	float scope=0;
	scope = 2*PIE*radios;
	return scope;
}
/*calclating area of rectangle and return it
input:hight and base
output:area of rectangle
*/
float rectangleArea(float hight,float base)
{
	float area=0;
	area = hight*base;
	return area;
}
/*calclating square area and return it 
input:hight
output:area of square
*/
float squareArea(float hight)
{
	float area=0;
	area = hight*hight;
	return area;
}
/*calclating length of thred trangle and return it
input:standsOne,standsSec
output:RightTrian
*/
float lengthThred(float standsOne,float standsSec)
{
	float RightTrian=0;
	RightTrian =pow(pow(standsOne,2.0)+pow(standsSec,2.0),0.5);
	return RightTrian;
}
/*calclating the distance between two points
input:x,y for 2 points
output:distance
*/
float distanceTwoPoints(float xFirst,float yFirst,float xSec,float ySec) 
{
    float distance=0;
	distance=pow((pow(xFirst-xSec,2)+pow(yFirst-ySec,2)),0.5);
	return distance;
}
enum difficultyLevel{distanceBetweenTwoPoints = 1,lengthTheRestRightTriangle,circleCaclaterSAndP,areaOfRectangle,areaofSquare,exiting};
int main(void)
{
	float xFirst, yFirst, xSec, ySec, standsOne, standsSec, radios, hight, base, hightSquare;
	int choice = 0;
	while(choice!=6)
	{
		printf("(%d) Calc the distance between 2 points.\n", distanceBetweenTwoPoints);
		printf("(%d) Calc the excess length in a right triangle. \n ", lengthTheRestRightTriangle);
		printf("(%d) Calc the area and perimeter of a circle.\n", circleCaclaterSAndP);
		printf("(%d) Calc the area of ​​a square.  \n ", areaOfRectangle);
		printf("(%d) Calc the area of ​​a rectangle \n ", areaofSquare);
		printf("(%d) exit \n ", exiting);
		printf("Enter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enter x1 and y1");
				scanf("%f",&xFirst);
				scanf("%f",&yFirst);
				printf("enter x2 and y2");
				scanf("%f",&xSec);
				scanf("%f",&ySec);
				printf("the distance %.2f /n",distanceTwoPoints(xFirst,yFirst,xSec,ySec));
				break;
			case 2:
				printf("enter stands 1 and 2");
				scanf("%f",&standsOne);
				scanf("%f",&standsSec);
				printf("the length Thred distance is :  %.2f  \n ",lengthThred(standsOne,standsSec));
				break;
			case 3:
				printf("enter radios");
				scanf("%f",&radios);
				printf("the scope is %.2f \n the area is : %.2f \n",circleScopeCaclater(radios),circleAreaCaclater(radios));
				break;
			case 4:
				printf("enter hight and base");
				scanf("%f",&hight);
				scanf("%f",&base);
				printf("The area of the square is %.2f  \n",rectangleArea(hight,base));
				break;
			case 5:
				printf("enter hight");
				scanf("%f",&hightSquare);
				printf("The area of the square is %.2f \n",squareArea(hightSquare));
				break;
			default:
				break;
		}
    }
	return 0;
}