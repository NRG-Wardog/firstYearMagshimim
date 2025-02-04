/*********************************
* Class: MAGSHIMIM C2			 *
* Week 3           				 *
* HW solution   			 	 *
**********************************/
#include <stdio.h>
#include <string.h>
/*
func printing arr
intput:string and len
output:none
*/
void printArray(char* p, int len)
{
	char* i = 0;
	for (i=p; i < p + len; i++)//p<p+len always true
	{
		printf("%c", *i);
	}
	printf("\n");
}
//he want to meet jyegq
int main(void)
{
	char* msg = "hi jyegq meet me at 2 :)";
	printArray(msg, strlen(msg));
	getchar();
	return 0;
}