#include <stdio.h>
#include <stdlib.h>

char grade[10];
void student_info(char names[10][100], char roll_nos[10], char sec[10]);
void exam_marks_entry(float ISA1marks[10][10], float ISA2marks[10][10], float ESAmarks[10][10]);
void grade_calc(float ISA1marks[10][10], float ISA2marks[10][10], float ESAmarks[10][10], char grade[10]);
void print_grade_card(char names[10][100], char roll_nos[10], char sec[10], float ISA1marks[10][10], float ISA2marks[10][10], float ESAmarks[10][10]);

void student_info(char names[10][100], char roll_nos[10], char sec[10])
{

    for (int i = 0; i < 3; i++)
    {
        printf("Enter the name of student %d:", i + 1);
        scanf(" %s", names[i]);
        printf("Enter the roll number of student %d:", i + 1);
        scanf(" %s", roll_nos[i]);
        printf("Enter the email of student %d:", i + 1);
        scanf(" %s", sec[i]);
    }
}

int main()
{

    char names[10][100];
    char roll_nos[10];
    char sec[10];
    float ISA1marks[10][10];
    float ISA2marks[10][10];
    float ESAmarks[10][10];

    int n = 0;
    while (n != 5)
    {
        printf("1.Enter student information\n2.Enter exam scores\n3.Calculate grade\n4.Print grade\nEnter your option:\n");
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
            print_grade_card(names, roll_nos, sec, ISA1marks, ISA2marks, ESAmarks);
            break;

        default:
            printf("Invalid option entered");
            break;
        }
    }
}
void exam_marks_entry(float ISA1marks[10][10], float ISA2marks[10][10], float ESAmarks[10][10])
{
    int j = 0;
    while (j < 2) // change to 10
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
void grade_calc(float ISA1marks[10][10], float ISA2marks[10][10], float ESAmarks[10][10], char grade[10])
{
    float ISA_agg[10][3];
    float ESA_agg[10][3];
    float total[10][3];
    float fin_grade[10];
    for (int i = 0; i < 2; i++) // change to 10 later
    {
        for (int j = 0; j < 3; j++)
        {
            ISA_agg[i][j] = (ISA1marks[i][j] + ISA2marks[i][j]) / 2;
            ESA_agg[i][j] = (ESAmarks[i][j]) / 2;
            total[i][j] = ISA_agg[i][j] + ESA_agg[i][j];
        }
        fin_grade[i] = (total[i][1] + total[i][2] + total[i][3]);
    }

    for (int a = 0; a < 2; a++) // 10
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
void print_grade_card(char names[10][100], char roll_nos[10], char sec[10], float ISA1marks[10][10], float ISA2marks[10][10], float ESAmarks[10][10])
{
    for (int j = 0; j < 2; j++)
    {
        printf("Student details for roll number %s\n", roll_nos[j]);
        printf("Name: %s\n", names[j]);
        printf("Section: %s\n", sec[j]);
        for (int i = 0; i < 3; i++)
        {
            printf("Subject %d marks: %.2f %.2f %.2f\n", i + 1, ISA1marks[j][i], ISA2marks[j][i], ESAmarks[j][i]);
        }
        printf("\n");
    }
}
