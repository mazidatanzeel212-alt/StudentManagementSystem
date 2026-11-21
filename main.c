
#include <stdio.h>
#include "student.h"
#include "file.h"

int main() {
    Student students[100];
    int count = loadStudents(students);
    int choice;

    printf("Loaded %d student record(s).\n", count);

    do {
        printf("\n=================================\n");
        printf("    STUDENT MANAGEMENT SYSTEM\n");
        printf("=================================\n");

        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Search Student by Name\n");
        printf("5. Update Student\n");
        printf("6. Delete Student\n");
        printf("7. Show Student Statistics\n");
        printf("8. Exit\n");

        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
            }

            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students, &count);
                saveStudents(students, count);
                break;

            case 2:
                viewStudents(students, count);
                break;

            case 3:
                searchStudent(students, count);
                break;

            case 4:
                searchStudentByName(students, count);
                break;

            case 5:
                updateStudent(students, count);
                saveStudents(students, count);
                break;

            case 6:
                deleteStudent(students, &count);
                saveStudents(students, count);
                break;

            case 7:
                showStatistics(students, count);
                break;

            case 8:
                printf("\nThank you for using Student Management System!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 8);

    return 0;
}

