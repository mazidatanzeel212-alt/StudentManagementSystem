#include <stdio.h>
#include "file.h"

void saveStudents(Student students[], int count) {
    FILE *file = fopen("students.txt", "w");

    if (file == NULL) {
        printf("Error saving student records!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d|%s|%d|%s\n",
                students[i].id,
                students[i].name,
                students[i].age,
                students[i].course);
    }

    fclose(file);
    printf("Student records saved successfully!\n");
}

int loadStudents(Student students[]) {
    FILE *file = fopen("students.txt", "r");

    if (file == NULL) {
        return 0;
    }

    int count = 0;

    while (count < 100 &&
           fscanf(file, "%d|%49[^|]|%d|%49[^\n]\n",
                  &students[count].id,
                  students[count].name,
                  &students[count].age,
                  students[count].course) == 4) {
        count++;
    }

    fclose(file);
    return count;
}
