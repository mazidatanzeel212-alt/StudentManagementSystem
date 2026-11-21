#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    int id;
    char name[50];
    int age;
    char course[50];
} Student;

void addStudent(Student students[], int *count);
void viewStudents(Student students[], int count);
void searchStudent(Student students[], int count);
void searchStudentByName(Student students[], int count);
void updateStudent(Student students[], int count);
void deleteStudent(Student students[], int *count);
void showStatistics(Student students[], int count);

#endif
