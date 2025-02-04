/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE_OF_ANIMAL 2
#define SIZE 30
typedef struct animal
{
	char type[SIZE];
	char name[SIZE];
	int age;
}animal;

bool equls(animal a1,animal a2)
{
	return  a1.age == a2.age && strcmp(a1.type, a2.type) == 0 && strcmp(a1.name, a2.name) == 0;
}

void print(animal a1)
{
	printf("type:%s", a1.type);
	printf("name:%s", a1.name);
	printf("age:%d \n", a1.age);
}



int main(void)
{
	animal a1 = { "","",0};
	animal a2 = { "","",0};
	printf("animal number 1 \n");
	printf("enter type of animal(1-10) ");
	fgets(a1.type, SIZE, stdin);
	printf("ener name of the animal ");
	fgets(a1.name, SIZE, stdin);
	printf("enter age: ");
	scanf("%d", &a1.age);
	getchar();
	printf("animal number 2\n");
	printf("enter type(1-10) ");
	fgets(a2.type, SIZE, stdin);
	printf("ener name of the animal ");
	fgets(a2.name, SIZE, stdin);
	printf("enter age: ");
	scanf("%d", &a2.age);
	getchar();
	printf("size of animal 1:%d \n",sizeof(a1));
	printf("size of animal 2:%d \n", sizeof(a2));

	printf("animal 1  \n");
	print(a1);
	printf("animal 2 \n");
	print(a2);
	if (equls(a1, a2) == 1)
	{
		printf("True 'the same animal");
	}
	else
	{
		printf("False, the arent the same cat");
	}
	getchar();
	return 0;
}