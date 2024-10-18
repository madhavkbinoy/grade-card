#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


void ViewRecords(student *students, int n);
void ModifyRecord(student *students, int n);

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    student *students = malloc(n * sizeof(student));
    if (students == NULL)
    {
        printf("Error allocating memory\n");
        return 1;
    }

    int choice;

    do
    {
        printf("Select an option: \n");
        printf("1. Enter student details and marks\n");
        printf("2. Display the gradecard of the student\n");
        printf("3. View all student records\n");
        printf("4. Modify a student record\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            student_info(students, n);
            ISA1(students, n);
            ISA2(students, n);
            Internals(students, n);
            ESA(students, n);
            total_marks(students, n);
            SGPA(students, n);
            WriteToFile(students, n);
            break;

        case 2:
            ReadFromFile(students, n);
            display_gradecard(students, n);
            break;

        case 3:
            ViewRecords(students, n); 
            break;

        case 4:
            ModifyRecord(students, n); 
            break;

        case 5:
            break;

        default:
            printf("Invalid option.\n");
        }
    } while (choice != 5);

    
    for (int i = 0; i < n; i++)
    {
        free(students[i].name);
        free(students[i].roll_no);
        free(students[i].isa1);
        free(students[i].isa2);
        free(students[i].internals);
        free(students[i].esa);
        free(students[i].tot_marks);
    }
    free(students);

    return 0;
}


void ViewRecords(student *students, int n)
{
    printf("Student Records:\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("Name: %s, Roll No: %s, Semester: %d, SGPA: %.2f\n", 
               students[i].name, students[i].roll_no, students[i].sem, students[i].sgpa);
    }
    printf("-----------------------------------------------------------\n");
}


void ModifyRecord(student *students, int n)
{
    int index;
    printf("Enter the index of the student record to modify (1 - %d): ", n);
    scanf("%d", &index);
    
    if (index < 1 || index > n)
    {
        printf("Invalid index.\n");
        return;
    }

    index--; 
    printf("Modifying record for %s (Roll No: %s)\n", students[index].name, students[index].roll_no);
    
    
    printf("Enter new name: ");
    scanf("%s", students[index].name);
    printf("Enter new roll number: ");
    scanf("%s", students[index].roll_no);
    
    
}
