#include <stdio.h>
#include <string.h>
#define SIZE 12
/*
fun check if the num is 0 and put + - 
input:num and str[]
output:num
*/
int check(int num,char str[])
{
	if (num > 0)
	{
        str[0] = '+';
    }
	else  if(num<0)
	{
        str[0] = '-';
        num = -num;
    }
    else
    {
        str[0]='0';
    }
	return num;
}
int main() {
    int num = 0;
    int i = 0,j;
    char str[SIZE] = {0};
	char temp[SIZE] = {0};
    printf("Enter num: ");
    scanf("%d", &num);
	if(check(num,str)!=0)
	{   
		num =check(num,str);
		while (num > 0 && i < SIZE)
		{
			temp[i] = (char)(num % 10 + '0');
			i++;
			num /= 10;
		}
		for(j=1;j<strlen(temp)+1;j++)
		{
			str[j] = temp[strlen(temp)-j];
		}
		printf("string: %s ",str);
		printf("length: %d\n",(int)strlen(temp)+1);
	}
	else
	{
		printf("string: %s ",str);
		printf("length: %d\n",(int)strlen(str));
	}
    return 0;
}
