#include<stdio.h>
#include<string.h>

// Define a structure for student records
struct Student {
    int roll_no;
    char name[50];
    float percentage;
};

// Function to swap two student records
void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort on an array of student records
void sortStudents(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].roll_no > students[j + 1].roll_no) {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

int main() {
    struct Student students[5];

    // Input student records
    for (int i = 0; i < 5; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Percentage: ");
        scanf("%f", &students[i].percentage);
    }

    // Sort the students by roll number
    sortStudents(students, 5);

    // Display sorted student records
    printf("\nStudent records in ascending order of roll number:\n");
    printf("Roll No\tName\tPercentage\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\t%s\t%.2f\n", students[i].roll_no, students[i].name, students[i].percentage);
    }

    return 0;
}
