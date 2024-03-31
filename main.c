#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

char grade[10];

int main()
{

    char names[10][100];
    char roll_nos[10];
    char sec[10];
    float ISA1marks[10][3];
    float ISA2marks[10][3];
    float ESAmarks[10][3];

    int n = 0;
    while (n != 5)
    {
        printf("1.Enter student information\n2.Enter exam scores\n3.Calculate grade\n4.Print grade\n5.Exit\nEnter your option:\n");
        scanf("%d", &n);

        switch (n)
        {
        case 1:

            student_info(names, roll_nos, sec);
            break;
        case 2:

            exam_marks_entry(ISA1marks, ISA2marks, ESAmarks);
            break;

        case 3:
            grade_calc(ISA1marks, ISA2marks, ESAmarks, grade);
            for (int i = 0; i < 2; i++)
            {
                printf("%c", grade[i]);
            }
            printf("\n");
            break;
        case 4:
            print_grade_card(names, roll_nos, sec, ISA1marks, ISA2marks, ESAmarks, grade);
            break;

        default:
            printf("Invalid option entered");
            break;
        }
    }
}
