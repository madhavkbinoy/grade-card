#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct {
    char *name;
    char *roll_no;
    int sem;
    int *isa1;
    int *isa2;
    int *internals;
    int *esa;
    float *tot_marks;
    float sgpa;
    char sub[3][10];
    int credit[3];
} student;

extern void student_info(student *stu, int n);
extern void Subjects(student *stu);
extern void Credits(student *stu);
extern void ISA1(student *stu, int n);
extern void ISA2(student *stu, int n);
extern void Internals(student *stu, int n);
extern void ESA(student *stu, int n);
extern void total_marks(student *stu, int n);
extern void SGPA(student *stu, int n);
extern void display_gradecard(student *stu, int n);

#endif