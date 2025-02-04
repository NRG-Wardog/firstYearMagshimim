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
#define MAX_LETTER 50

int main(void)
{
	int size = 0,i=0;
	char** names = NULL;
	char temp[MAX_LETTER];


	printf("enter number  of friends");
	scanf("%d", &size);
	getchar();
	names = (char*)malloc(size * sizeof(char*));
	for (int i = 0; i < size; i++) 
	{
		names[i] = (char*)malloc(MAX_LETTER * sizeof(char));
		printf("enter name of friend number %d: ", i+1);
		scanf("%s", names[i]);
		names[i] = realloc(names[i],strlen(names[i]) * sizeof(char));
		getchar();
	}
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (strcmp(names[i], names[j]) > 0) {
				strcpy(temp, names[i]);
				strcpy(names[i], names[j]);
				strcpy(names[j], temp);
			}
		}
	}

	for (int i = 0; i < size; i++) {
		printf("friend %d : %s\n",i+1, names[i]);
	}


	for (int i = 0; i < size; i++) {
		free(names[i]);
	}
	free(names);
	getchar();
	return 0;
}