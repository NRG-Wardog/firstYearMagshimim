#include <stdio.h>
#include <string.h>
#define SIZE 50
#define DEFFR_BETWEEN_CAPS 32
int main() {
    char str1[SIZE] = {0};
    int i, j; 
    int isPalindrome = 1;
    
    printf("Enter string: ");
    fgets(str1, SIZE, stdin);
	str1[strcspn(str1, "\n")] = 0;
    for (i = 0, j = strlen(str1) - 1; i < j; i++, j--) 
	{
        while (str1[i] == ' ') {
            i++;
        }

        while (str1[j] == ' ') 
		{
            j--;
        }

        if (str1[i] != str1[j]&&str1[i]+DEFFR_BETWEEN_CAPS != str1[j]&&str1[i]-DEFFR_BETWEEN_CAPS != str1[j]) //bouns 2 conditions
		{
            isPalindrome = 0;
        }
    }

    if (isPalindrome == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
