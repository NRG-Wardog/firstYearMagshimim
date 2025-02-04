#include <stdio.h>

#define COURSES 11
#define EXERCISES 3
#define GRADE_ONE 70
#define GRADE_SEC 80
#define GRADE_TRE 60

int main() 
{
    int myGrades[EXERCISES][COURSES] = {0}; //  danel creat 
	/*
	 70 | 0 | 0 | 0 | 0 | 0 | 0 | 0| 0 | 0 | 0 |
	 80 | 0 | 0 | 0 | 0 | 0 | 0 | 0| 0 | 0 | 0 |
	 60 | 0 | 0 | 0 | 0 | 0 | 0 | 0| 0 | 0 | 0 |
	*/
    // Assign values to the array
    myGrades[0][0] = GRADE_ONE; 
    myGrades[0][1] = GRADE_SEC; 
    myGrades[0][2] = GRADE_TRE; 


    // Print the grades sheet
    printf("Grades Sheet:\n");
    for (int i = 0; i < EXERCISES; i++) {
        printf("Exercise %d: %d | %d | %d\n", i+1, myGrades[i][0], myGrades[i][1], myGrades[i][2]);
    }

    return 0;
}
