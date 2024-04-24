#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    student *students = malloc(n * sizeof(student));
    if (students == NULL) {
        printf("Error\n");
        return 1;
    }

    int choice;

    do
    {
        printf("Select an option: \n");
        printf("1. Enter student details and marks\n2. Display the gradecard of the student\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                student_info(students, n);
                Subjects(students);
                Credits(students);
                ISA1(students, n);
                ISA2(students, n);
                Internals(students,n);
                ESA(students, n);
                break;

            case 2:
                total_marks(students, n);
                SGPA(students, n);
                display_gradecard(students, n);
                break;
            case 3:
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (choice != 3);

    free(students);

    return 0;
}
