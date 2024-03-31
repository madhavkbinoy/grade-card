#ifndef functions_h
#define functions_h

void student_info(char names[10][100], char roll_nos[10], char sec[10]);
int exam_marks_entry(float ISA1marks[10][3], float ISA2marks[10][3], float ESAmarks[10][3]);
void grade_calc(float ISA1marks[10][3], float ISA2marks[10][3], float ESAmarks[10][3]);
void print_grade_card(char names[10][3], char roll_nos[10][100], char sec[10], float ISA1marks[10][3], float ISA2marks[10][3], float ESAmarks[10][3]);

#endif