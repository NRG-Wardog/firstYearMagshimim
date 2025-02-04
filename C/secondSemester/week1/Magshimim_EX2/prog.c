/*********************************
* Class: MAGSHIMIM C2			 *
* Week 1           				 *
* HW Question - Thanks Program 	 *
**********************************/

#include <stdio.h>
#include <string.h>
#define SIZE 8 //MAGIC NUMBERS
#define LONG 1
void printMessage(char str[]);

int main(void)
{
	char messge[SIZE] = "THANK ";//STR not a good name size isnt big enouge 
	char you = 'u';

	strncat(messge, &you, LONG); // do not fix this line or the next one
	printMessage(messge);
	return 0;
}

/*
the func printing to sigal thank u letter 
input:char str
output:void
מדפיס תודה וברכה // NOT ENOUGE INFROMATIN
*/
void printMessage(char messge[])
{
	printf("Hello Sigal! I just wanted to say that studying with you...\n\n");
	printf("Really made me understand how much I love\n");
	printf(" __  __                 _     _           _           \n");
	printf("|  \\/  |               | |   (_)         (_)          \n");
	printf("| \\  / | __ _  __ _ ___| |__  _ _ __ ___  _ _ __ ___  \n");
	printf("| |\\/| |/ _` |/ _` / __| '_ \\| | '_ ` _ \\| | '_ ` _ \\ \n");
	printf("| |  | | (_| | (_| \\__ \\ | | | | | | | | | | | | | | |\n");
	printf("|_|  |_|\\__,_|\\__, |___/_| |_|_|_| |_| |_|_|_| |_| |_|\n");
	printf("              __/ |                                  \n");
	printf("              |___/                                  \n\n");

	printf("Without C you would be just Gal :D\n");
	printf("See you in class!\n");
	printf("and %s !!", messge);

}