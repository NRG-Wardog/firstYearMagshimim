/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#define SIZE 50

void swap(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void revarse(char* text, int size) {
    int i = 0;
    for (i = 0; i < size/2; i++) {
        swap(text + i, text + size - 1 - i);
    }
}

void decrypt(char* cipher, int n)
{
    int i = 0;
    revarse(cipher, strlen(cipher));

    for (i = 0; i < SIZE; i++) {
        if (*cipher != NULL)
        {
            *(cipher) = 'a' + (*cipher - 'a' + n) % 26;
            cipher++;
        }
        
    }
}



int main() {
    char text[SIZE] = { 0 };
    int key;

    printf("Enter text: ");
    fgets(text, SIZE, stdin);
    text[strcspn(text, "\n")] = '\0'; 

    printf("Enter key: ");
    scanf("%d", &key);
    getchar(); 

    decrypt(text, key);
    printf("Decrypted text: %s\n", text);
    getchar();
    return 0;
}