/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/

#include <stdio.h>
#include <stdlib.h>

int* createArray(int size) {
    char arr[] ="anoo";
    return arr; 
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n");
}

int main() {
    int size = 5;
    int* arr = createArray(size);

    printArray(arr, size);

    getchar();
    return 0;
}
//לא עובד בגלל שהערכים נשמרים רק בתוך אותו הפונקציה ונמחקים  לאחרי יצאתו