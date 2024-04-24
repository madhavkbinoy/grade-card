#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
void student_info(char names[10][100], char roll_nos[10][100], char sec[10][100])
{
    for (int i = 0; i < 10; i++)
    {
        printf("Enter the name of student %d:", i + 1);
        scanf("%s", names[i]);
        printf("Enter the roll number of student %d:", i + 1);
        scanf("%s", roll_nos[i]);
        printf("Enter the email of student %d:", i + 1);
        scanf("%s", sec[i]);
    }
}