#include <stdio.h>
int main()
{
	int a = 53,b=12;
	a = a+b;
	b = a-b;
	a = a-b;
	printf("a:%d ,b:%d ",a,b);
	return 0 ;
}