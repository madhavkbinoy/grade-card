#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void grade_calc(float ISA1marks[10][3], float ISA2marks[10][3], float ESAmarks[10][3], char grade[10])
{
    float ISA_agg[10][3];
    float ESA_agg[10][3];
    float total[10][3];
    float fin_grade[10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ISA_agg[i][j] = (ISA1marks[i][j] + ISA2marks[i][j]) / 2;
            ESA_agg[i][j] = (ESAmarks[i][j]) / 2;
            total[i][j] = ISA_agg[i][j] + ESA_agg[i][j];
        }
        fin_grade[i] = (total[i][1] + total[i][2] + total[i][3]);
    }

    for (int a = 0; a < 10; a++)
    {
        if (fin_grade[a] >= 90)
            grade[a] = 'S';
        else if (fin_grade[a] >= 80)
            grade[a] = 'A';
        else if (fin_grade[a] >= 70)
            grade[a] = 'B';
        else if (fin_grade[a] >= 60)
            grade[a] = 'C';
        else if (fin_grade[a] >= 50)
            grade[a] = 'D';
        else if (fin_grade[a] >= 45)
            grade[a] = 'E';
        else
            fin_grade[a] = 'F';
    }
}