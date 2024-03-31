#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
void exam_marks_entry(float ISA1marks[10][3], float ISA2marks[10][3], float ESAmarks[10][3])
{
    int j = 0;
    while (j < 10)
    {
        printf("Student %d details\n", j + 1);
        printf("Enter ISA1 marks:");
        for (int i = 0; i < 3; i++)
        {
            printf("Enter for subject %d ", i + 1);
            scanf("\n%f", &ISA1marks[j][i]);
        }
        printf("Enter ISA2 marks:");
        for (int i = 0; i < 3; i++)
        {
            printf("Enter for subject %d ", i + 1);
            scanf("\n%f", &ISA2marks[j][i]);
        }
        printf("Enter ESA marks:");
        for (int i = 0; i < 3; i++)
        {
            printf("Enter for subject %d ", i + 1);
            scanf("\n%f", &ESAmarks[j][i]);
        }
        j++;
    }
}