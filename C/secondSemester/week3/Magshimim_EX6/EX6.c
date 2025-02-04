#include <stdio.h>
#include <string.h>

#define PASSWORD "maGshimim2017"
#define STR_LEN 16
#define FALSE 0
#define TRUE !FALSE

int main(void)
{
	int pass = FALSE;
    char buff[STR_LEN] = { 0 };

    printf("Enter the password: ");
    scanf("%15s", buff);//if it more than 15 it will say yes even if not becuse it will get pass pasbilite to change to true becuse of the stock overflow

    if(strcmp(buff, PASSWORD))
    {
        printf ("Wrong Password \n");
    }
    else
    {
        printf ("Correct Password \n");
        pass = TRUE;
    }

    if(pass)
    {
        printf ("Access given to the secret files \n");
    }
	
	getchar();
    return 0;
}