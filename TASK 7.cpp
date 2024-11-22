#include <stdio.h>
#include <string.h>

#define MAX_DEPARTMENTS 10
#define MAX_COURSES 20


struct Course {
    char courseID[10];
    char courseName[50];
    char instructor[50];
    int credits;
};

struct Department {
    char deptName[50];
    struct Course courses[MAX_COURSES];
    int courseCount;
};


struct Department departments[MAX_DEPARTMENTS];
int departmentCount = 0;


void addDepartment() {
    if (departmentCount >= MAX_DEPARTMENTS) {
        printf("Max departments reached!\n");
        return;
    }
    printf("Enter department name: ");
    scanf(" %[^\n]", departments[departmentCount].deptName);
    departments[departmentCount].courseCount = 0;
    departmentCount++;
    printf("Department added successfully!\n");
}

void addCourse() {
    if (departmentCount == 0) {
        printf("No departments available. Add a department first.\n");
        return;
    }
    char deptName[50];
    printf("Enter department name: ");
    scanf(" %[^\n]", deptName);

    for (int i = 0; i < departmentCount; i++) {
        if (strcmp(departments[i].deptName, deptName) == 0) {
            if (departments[i].courseCount >= MAX_COURSES) {
                printf("Max courses reached for this department!\n");
                return;
            }
            struct Course *course = &departments[i].courses[departments[i].courseCount];
            printf("Enter course ID: ");
            scanf("%s", course->courseID);
            printf("Enter course name: ");
            scanf(" %[^\n]", course->courseName);
            printf("Enter instructor name: ");
            scanf(" %[^\n]", course->instructor);
            printf("Enter credits: ");
            scanf("%d", &course->credits);

            departments[i].courseCount++;
            printf("Course added successfully!\n");
            return;
        }
    }
    printf("Department not found!\n");
}

void displayDetails() {
    if (departmentCount == 0) {
        printf("No departments available.\n");
        return;
    }
    for (int i = 0; i < departmentCount; i++) {
        printf("\nDepartment: %s\n", departments[i].deptName);
        printf("Courses:\n");
        for (int j = 0; j < departments[i].courseCount; j++) {
            struct Course *course = &departments[i].courses[j];
            printf("  ID: %s, Name: %s, Instructor: %s, Credits: %d\n",
                   course->courseID, course->courseName, course->instructor, course->credits);
        }
    }
}

void calculateTotalCredits() {
    if (departmentCount == 0) {
        printf("No departments available.\n");
        return;
    }
    for (int i = 0; i < departmentCount; i++) {
        int totalCredits = 0;
        for (int j = 0; j < departments[i].courseCount; j++) {
            totalCredits += departments[i].courses[j].credits;
        }
        printf("Total Credits for Department %s: %d\n", departments[i].deptName, totalCredits);
    }
}


int main() {
    int choice;
    while (1) {
        printf("\nUniversity Course Enrollment System\n");
        printf("1. Add Department\n2. Add Course\n3. Display Details\n4. Calculate Total Credits\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addDepartment(); break;
            case 2: addCourse(); break;
            case 3: displayDetails(); break;
            case 4: calculateTotalCredits(); break;
            case 5: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}

