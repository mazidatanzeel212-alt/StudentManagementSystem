#include <stdio.h>
#include <string.h>
#include "student.h"

void addStudent(Student students[], int *count) {
    int id;

    if (*count >= 100) {
        printf("Student storage is full!\n");
        return;
    }

    printf("Enter Student ID: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID!\n");
        return;
    }

    // Check for duplicate ID
    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            printf("Student ID already exists!\n");
            return;
        }
    }

    students[*count].id = id;

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", students[*count].name);

printf("Enter Student Age: ");
if (scanf("%d", &students[*count].age) != 1 ||
    students[*count].age <= 0) {
    printf("Invalid age! Please enter a positive number.\n");
    return;
}

    printf("Enter Student Course: ");
    scanf(" %49[^\n]", students[*count].course);

    (*count)++;

    printf("\nStudent added successfully!\n");
}

void viewStudents(Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n===== STUDENT RECORDS =====\n");

    for (int i = 0; i < count; i++) {
        printf("\nID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Course: %s\n", students[i].course);
    }
}

void searchStudent(Student students[], int count) {
    int id;

    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\nStudent Found!\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Course: %s\n", students[i].course);
            return;
        }
    }

    printf("\nStudent not found!\n");
}

void updateStudent(Student students[], int count) {
    int id;

    printf("Enter Student ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Enter new name: ");
            scanf(" %49[^\n]", students[i].name);

            printf("Enter new age: ");
            scanf("%d", &students[i].age);

            printf("Enter new course: ");
            scanf(" %49[^\n]", students[i].course);

            printf("\nStudent updated successfully!\n");
            return;
        }
    }

    printf("\nStudent not found!\n");
}

void deleteStudent(Student students[], int *count) {
    int id;

    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }

            (*count)--;

            printf("\nStudent deleted successfully!\n");
            return;
        }
    }

    printf("\nStudent not found!\n");
}

void showStatistics(Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records available for statistics.\n");
        return;
    }

    int totalAge = 0;
    int youngest = students[0].age;
    int oldest = students[0].age;

    for (int i = 0; i < count; i++) {
        totalAge += students[i].age;

        if (students[i].age < youngest) {
            youngest = students[i].age;
        }

        if (students[i].age > oldest) {
            oldest = students[i].age;
        }
    }

    printf("\n===== STUDENT STATISTICS =====\n");
    printf("Total Students: %d\n", count);
    printf("Average Age: %.2f\n", (float)totalAge / count);
    printf("Youngest Age: %d\n", youngest);
    printf("Oldest Age: %d\n", oldest);
}
void searchStudentByName(Student students[], int count) {
    char name[50];
    int found = 0;

    printf("Enter Student Name to search: ");
    scanf(" %49[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("\nStudent Found!\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Course: %s\n", students[i].course);

            found = 1;
        }
    }

    if (!found) {
        printf("\nStudent not found!\n");
    }
}
