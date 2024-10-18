#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

FILE *fp;


void student_info(student *stu, int n)
{
    for (int i = 0; i < n; i++)
    {
        stu[i].name = malloc(30 * sizeof(char));
        stu[i].roll_no = malloc(20 * sizeof(char));
        if (stu[i].name == NULL || stu[i].roll_no == NULL)
        {
            printf("Error allocating memory\n");
            exit(1);
        }
        printf("-----------------    Data of Student %d    -----------------\n", i + 1);
        printf("Enter the name: ");
        scanf("%s", stu[i].name);
        printf("Enter the roll number: ");
        scanf("%s", stu[i].roll_no);
        printf("Enter the semester: ");
        scanf("%d", &stu[i].sem);

        
        Subjects(&stu[i]);
        Credits(&stu[i]);
    }
    printf("-----------------------------------------------------------\n");
}


void Subjects(student *stu)
{
    for (int i = 0; i < 3; i++)
    {
        printf("Enter subject %d: ", i + 1);
        scanf("%s", stu->sub[i]);
    }
    printf("-----------------------------------------------------------\n");
}


void Credits(student *stu)
{
    for (int i = 0; i < 3; i++)
    {
        printf("Enter the credits of subject %d: ", i + 1);
        scanf("%d", &stu->credit[i]);
    }
    printf("-----------------------------------------------------------\n");
}


void ISA1(student *stu, int n)
{
    for (int i = 0; i < n; i++)
    {
        stu[i].isa1 = malloc(3 * sizeof(int));
        printf("Enter the ISA 1 marks(out of 40) of student %d for the 3 subjects: ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &stu[i].isa1[j]);
        }
    }
    printf("-----------------------------------------------------------\n");
}


void ISA2(student *stu, int n)
{
    for (int i = 0; i < n; i++)
    {
        stu[i].isa2 = malloc(3 * sizeof(int));
        printf("Enter the ISA 2 marks(out of 40) of student %d for the 3 subjects: ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &stu[i].isa2[j]);
        }
    }
    printf("-----------------------------------------------------------\n");
}


void Internals(student *stu, int n)
{
    for (int i = 0; i < n; i++)
    {
        stu[i].internals = malloc(3 * sizeof(int));
        printf("Enter the internal marks(out of 10) of student %d for the 3 subjects: ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &stu[i].internals[j]);
        }
    }
    printf("-----------------------------------------------------------\n");
}


void ESA(student *stu, int n)
{
    for (int i = 0; i < n; i++)
    {
        stu[i].esa = malloc(3 * sizeof(int));
        printf("Enter the ESA marks of student(out of 100) %d for the 3 subjects: ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &stu[i].esa[j]);
        }
    }
    printf("-----------------------------------------------------------\n");
}


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


void SGPA(student *stu, int n)
{
    int total_credits = 0;
    for (int i = 0; i < 3; i++)
    {
        total_credits += stu->credit[i];
    }
    for (int i = 0; i < n; i++)
    {
        stu[i].sgpa = 0;
        for (int j = 0; j < 3; j++)
        {
            if (stu[i].tot_marks[j] > 90 && stu[i].tot_marks[j] <= 100)
            {
                stu[i].sgpa += 10 * stu->credit[j];
            }
            else if (stu[i].tot_marks[j] > 80 && stu[i].tot_marks[j] <= 90)
            {
                stu[i].sgpa += 9 * stu->credit[j];
            }
            else if (stu[i].tot_marks[j] > 70 && stu[i].tot_marks[j] <= 80)
            {
                stu[i].sgpa += 8 * stu->credit[j];
            }
            else if (stu[i].tot_marks[j] > 60 && stu[i].tot_marks[j] <= 70)
            {
                stu[i].sgpa += 7 * stu->credit[j];
            }
            else if (stu[i].tot_marks[j] > 50 && stu[i].tot_marks[j] <= 60)
            {
                stu[i].sgpa += 6 * stu->credit[j];
            }
            else if (stu[i].tot_marks[j] > 40 && stu[i].tot_marks[j] <= 50)
            {
                stu[i].sgpa += 5 * stu->credit[j];
            }
            else
            {
                stu[i].sgpa += 4 * stu->credit[j];
            }
        }
        stu[i].sgpa /= total_credits;
    }
}


void WriteToFile(student *stu, int n)
{
    fp = fopen("student_data.csv", "a"); 
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%s,%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%f\n",
                stu[i].name, stu[i].roll_no, stu[i].sem,
                stu[i].isa1[0], stu[i].isa2[0], stu[i].internals[0], stu[i].esa[0],
                stu[i].isa1[1], stu[i].isa2[1], stu[i].internals[1], stu[i].esa[1],
                stu[i].isa1[2], stu[i].isa2[2], stu[i].internals[2], stu[i].esa[2],
                stu[i].sgpa);
    }
    printf("Written to file\n");
    fclose(fp);
}


void ReadFromFile(student *stu, int n)
{
    fp = fopen("student_data.csv", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    char buffer[1024];
    fgets(buffer, sizeof(buffer), fp); 

    printf("\nStudent Records:\n");
    printf("--------------------------------------------------------------------\n");
    printf("Name\t\tRoll Number\tSemester\tSGPA\n");
    printf("--------------------------------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), fp))
    {
        char name[30], roll_no[20];
        int sem;
        float sgpa;

        sscanf(buffer, "%29[^,],%19[^,],%d,%*d,%*d,%*d,%*d,%*d,%*d,%*d,%*d,%*d,%*d,%*d,%*d,%f",
               name, roll_no, &sem, &sgpa);
        printf("%-30s %-20s %-10d %.2f\n", name, roll_no, sem, sgpa);
    }

    printf("--------------------------------------------------------------------\n");
    fclose(fp);
}


void ViewRecords()
{
    fp = fopen("student_data.csv", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    char buffer[1024];
    fgets(buffer, sizeof(buffer), fp); 

    printf("\nAll Student Records:\n");
    printf("--------------------------------------------------------------------\n");
    printf("Name\t\tRoll Number\tSemester\tSGPA\n");
    printf("--------------------------------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), fp))
    {
        char name[30], roll_no[20];
        int sem;
        float sgpa;

        sscanf(buffer, "%29[^,],%19[^,],%d,%*d,%*d,%*d,%*d,%*d,%*d,%*d,%*d,%*d,%*d,%*d,%*d,%f",
               name, roll_no, &sem, &sgpa);
        printf("%-30s %-20s %-10d %.2f\n", name, roll_no, sem, sgpa);
    }

    printf("--------------------------------------------------------------------\n");
    fclose(fp);
}


void ModifyRecord()
{
    
    FILE *file = fopen("student_data.csv", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    char buffer[1024];
    fgets(buffer, sizeof(buffer), file); 

    
    char records[100][1024]; 
    int count = 0;

    while (fgets(buffer, sizeof(buffer), file))
    {
        strcpy(records[count++], buffer);
    }
    fclose(file);

    
    printf("\nExisting Records:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d: %s", i + 1, records[i]);
    }

    int record_num;
    printf("Enter the record number to modify: ");
    scanf("%d", &record_num);
    if (record_num < 1 || record_num > count)
    {
        printf("Invalid record number!\n");
        return;
    }

    
    printf("Enter new details (name, roll number, semester):\n");
    char new_name[30], new_roll_no[20];
    int new_sem;

    getchar(); 
    printf("Name: ");
    fgets(new_name, 30, stdin);
    new_name[strcspn(new_name, "\n")] = 0; 

    printf("Roll Number: ");
    fgets(new_roll_no, 20, stdin);
    new_roll_no[strcspn(new_roll_no, "\n")] = 0; 

    printf("Semester: ");
    scanf("%d", &new_sem);

    
    sprintf(records[record_num - 1], "%s,%s,%d,%s\n",
            new_name, new_roll_no, new_sem, records[record_num - 1] + strlen(records[record_num - 1]) - 9); // Keep the SGPA and marks

    
    file = fopen("student_data.csv", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "Name,Roll_Number,Sem,ISA1_S1,ISA2_S1,Internals_S1,ESA_S1,ISA1_S2,ISA2_S2,Internals_S2,ESA_S2,ISA1_S3,ISA2_S3,Internals_S3,ESA_S3,SGPA\n");
    for (int i = 0; i < count; i++)
    {
        fputs(records[i], file);
    }
    fclose(file);

    printf("Record modified successfully!\n");
}
