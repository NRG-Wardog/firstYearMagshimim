/*********************************
* Class: MAGSHIMIM C1			 *
* Week 11          				 *
**********************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[] = {'H', 'i', ' ',0};//to show its string 0
	char str2[] = {'H', 'o',0}; //??? forget "}" and 0
	
	strncat(str1, str2, strlen(str1) + strlen(str2));
	
	printf("%s", str1);
	return 0;
	
}