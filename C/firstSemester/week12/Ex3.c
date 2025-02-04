#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 50
#define MIN_ASCII_CAPS 65 
#define MAX_ASCII_CAPS 90
#define MIN_ASCII_REG 97 
#define MAX_ASCII_REG 122
#define MIN_ASCII_NUM 48 
#define MAX_ASCII_NUM 57
#define MAX_LET 8
#define MIN_LET 6
/*
fun get after the array an chaeck if the password are currct
input:arr
output:none
*/
void check(char arr[])
{
    int i = 0;
    bool checkerBigLe = false;
    bool checkerSmaLe = false;
    bool checkerSefra = false;
    bool cheackDouble = false;
    bool length = false;

    for (i = 0; i < SIZE && arr[i] != '\0'; i++)
    {
        if (arr[i] >= MIN_ASCII_CAPS && arr[i] <= MAX_ASCII_CAPS)
        {
            checkerBigLe = true;
        }
        if (arr[i] >= MIN_ASCII_REG && arr[i] <= MAX_ASCII_REG)
        {
            checkerSmaLe = true;
        }
        if (arr[i] >= MIN_ASCII_NUM && arr[i] <= MAX_ASCII_NUM)
        {
            checkerSefra = true;
        }
        if (i < SIZE - 1 && arr[i] == arr[i + 1])
        {
            cheackDouble = true;
        }
    }

    if (i >= MIN_LET && i <= MAX_LET)
    {
        length = true;
    }

    if (checkerBigLe && checkerSmaLe && checkerSefra && (!cheackDouble) && length)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
}

int main() 
{
    int num = 0;
    int i = 0,j;
    char str[SIZE] = {0};
    printf("Enter num: ");
    fgets(str, SIZE, stdin);
	str[strcspn(str, "\n")] = '\0';
	check(str);	
    return 0;
}