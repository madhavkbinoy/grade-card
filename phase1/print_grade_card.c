#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void print_grade_card(char names[10][100], char roll_nos[10], char sec[10], float ISA1marks[10][3], float ISA2marks[10][3], float ESAmarks[10][3])
{
    for (int j = 0; j < 10; j++)
    {
        printf("Student details for roll number %s\n", roll_nos[j]);
        printf("Name: %s\n", names[j]);
        printf("Section: %s\n", sec[j]);
        for (int i = 0; i < 3; i++)
        {
            printf("Subject %d marks: %.2f %.2f %.2f\n", i + 1, ISA1marks[j][i], ISA2marks[j][i], ESAmarks[j][i]);
        }
        printf("\n"); // Add a newline after printing all details for one student
    }
}