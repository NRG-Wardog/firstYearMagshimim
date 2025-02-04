#include<stdio.h> 
#define FIRST_NUM -1 
#define SECOND_NUM 46
#define THIRD_NUM 6
//didnt wrote include and magic number.
void printNum(int num);
//Unnecessary space correction
int main(void)
{
	int firstNum = FIRST_NUM;
	int secondNum = SECOND_NUM;
	int thirdNum = THIRD_NUM;
	printNum(firstNum);
	printNum(secondNum);//uneded "int"
	printNum(firstNum + secondNum);
	printNum(thirdNum);
}

/*printing the number 
input:number
output:none
*/
void printNum(int num) 
{
    printf("%d\n", num);
}
