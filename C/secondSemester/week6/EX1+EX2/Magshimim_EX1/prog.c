/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#define TARGET_MOL "MOL"
#define TARGET_ADD "ADD"

int main(int argc,char** argv)
{
	float sum = 0;
	int i = 0;
	if (argc > 3)
	{
		if (!strcmp(argv[1], TARGET_ADD))
		{
			for (i =2;i < argc;i++)
			{
				sum += atoi(argv[i]);
			}
			printf("Result: %.2f", sum);
		}
		else if (!strcmp(argv[1], TARGET_MOL))
		{
			sum = atoi(argv[2]) * atoi(argv[3]);
			for (i = 4;i < argc ;i++)
			{
				sum *= atoi(argv[i]);
			}
			printf("Result: %.2f", sum);
		}
		else
		{
			printf("ERROR! Invalid Number of Arguments! \nUsage: [ADD | MUL] <number> … < number>");
		}
	}
	else
	{
		printf("ERROR! Invalid Number of Arguments! \nUsage: [ADD | MUL] <number> … < number>");
	}
	
	getchar();
	return 0;
}