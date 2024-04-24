#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// Input student information
void student_info(student *stu, int n)
{
    for (int i = 0; i < n; i++)
    {
        stu[i].name = malloc(30 * sizeof(char));
        stu[i].roll_no = malloc(20 * sizeof(char));
        if (stu[i].name == NULL)
        {
            printf("Error\n");
            exit(1);
        }
        printf("-----------------    Data of Student %d    -----------------\n", i + 1);
        printf("Enter the name: ");
        scanf("%s", stu[i].name);
        printf("Enter the roll number: ");
        scanf("%s", stu[i].roll_no);
        printf("Enter the semester: ");
        scanf("%d", &stu[i].sem);
    }
    printf("-----------------------------------------------------------\n");
}

// Input subject names
void Subjects(student *stu)
{
    for (int i = 0; i < 3; i++)
    {
        printf("Enter subject %d: ", i + 1);
        scanf("%s", stu->sub[i]);
    }
    printf("-----------------------------------------------------------\n");
}

// Input subject credits
void Credits(student *stu)
{
    for (int i = 0; i < 3; i++)
    {
        printf("Enter the credits of subject %d: ", i + 1);
        scanf("%d", &stu->credit[i]);
    }
    printf("-----------------------------------------------------------\n");
}

// Input ISA1 marks
void ISA1(student *stu, int n)
{
    for (int i = 0; i < n; i++)
    {
        stu[i].isa1 = malloc(3 * sizeof(int));
        printf("Enter the ISA 2 marks of student %d for the 3 subjects: ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &stu[i].isa1[j]);
        }
    }
    printf("-----------------------------------------------------------\n");
}

// Input ISA2 marks
void ISA2(student *stu, int n)
{
    for (int i = 0; i < n; i++)
    {
        stu[i].isa2 = malloc(3 * sizeof(int));
        printf("Enter the ISA 2 marks of student %d for the 3 subjects: ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &stu[i].isa2[j]);
        }
    }
    printf("-----------------------------------------------------------\n");
}

//Input Internal marks
extern void Internals(student *stu, int n)
{
    for (int i = 0; i < n; i++)
    {
        stu[i].internals = malloc(3 * sizeof(int));
        printf("Enter the internal marks of student %d for the 3 subjects: ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &stu[i].internals[j]);
        }
    }
    printf("-----------------------------------------------------------\n");
}


// Input ESA marks
void ESA(student *stu, int n)
{
    for (int i = 0; i < n; i++)
    {
        stu[i].esa = malloc(3 * sizeof(int));
        printf("Enter the ESA marks of student %d for the 3 subjects: ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &stu[i].esa[j]);
        }
    }
    printf("-----------------------------------------------------------\n");
}

// Calculating total marks
void total_marks(student *stu, int n)
{
    for (int i = 0; i < n; i++)
    {
        stu[i].tot_marks = malloc(3 * sizeof(float));
        for (int j = 0; j < 3; j++)
        {
            stu[i].tot_marks[j] = ((stu[i].isa1[j] * 0.5) + (stu[i].isa2[j] * 0.5) + (stu[i].esa[j] * 0.5) + stu[i].internals[j]);
        }
    }
}

// Calculating SGPA
void SGPA(student *stu, int n)
{
    int total_credits = 0;
    for (int i = 0; i < 3; i++) 
        {total_credits += stu->credit[i];}
    for (int i = 0; i < n; i++)
    {
        stu[i].sgpa = 0;
        for (int j = 0; j < 3; j++)
        {
            if (stu[i].tot_marks[j] > 90 && stu[i].tot_marks[j]<=100) 
                {stu[i].sgpa += 10 * stu->credit[j];}
            else if (stu[i].tot_marks[j] > 80 && stu[i].tot_marks[j] <= 90)
                {stu[i].sgpa += 9 * stu->credit[j];}
            else if (stu[i].tot_marks[j] > 70 && stu[i].tot_marks[j] <= 80)
                {stu[i].sgpa += 8 * stu->credit[j];}
            else if (stu[i].tot_marks[j] > 60 && stu[i].tot_marks[j] <= 70)
                {stu[i].sgpa += 7 * stu->credit[j];}
            else if (stu[i].tot_marks[j] > 50 && stu[i].tot_marks[j] <= 60)
                {stu[i].sgpa += 6 * stu->credit[j];}
            else if (stu[i].tot_marks[j] > 40 && stu[i].tot_marks[j] <= 50)
                {stu[i].sgpa += 5 * stu->credit[j];}
            else
                {stu[i].sgpa += 4 * stu->credit[j];}
            
        }
        stu[i].sgpa /= total_credits;
    }
}

// Display gradecard
void display_gradecard(student *stu, int n)
{
    int input;
    printf("Choose the grade card to be printed (1 - %d):\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d. %s\n", i + 1, stu[i].name);
    }
    scanf("%d", &input);
    if (input >= 1 && input <= n)
    {
        input--;
        printf("\n");
        printf("====================================================================\n");
        printf("\t\t\t    GRADE CARD\n");
        printf("Name: %-30s\n", stu[input].name);
        printf("Semester: %-10d\n", stu[input].sem);
        printf("Roll No.: %-20s\n", stu[input].roll_no);
        printf("--------------------------------------------------------------------\n");
        printf("SGPA: %.2f\n", stu[input].sgpa);
        printf("--------------------------------------------------------------------\n");       
        printf("Subject\t\tISA1\tISA2\tInternals\tESA\tMarks\n");
        printf("--------------------------------------------------------------------\n");
        for (int i = 0; i < 3; i++) {
            printf("%-10s\t%d\t%d\t%d\t\t%d\t%.2f\n", stu[0].sub[i], stu[input].isa1[i], stu[input].isa2[i], stu[input].internals[i], stu[input].esa[i], stu[input].tot_marks[i]);
        }
        printf("====================================================================\n");
    } else
    {
        printf("Invalid number! Please enter a valid number");
    }
}