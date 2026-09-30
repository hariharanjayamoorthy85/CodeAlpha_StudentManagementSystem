#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.dat"
#define TEMP_FILE "temp.dat"
#define NAME_LENGTH 50
#define COURSE_LENGTH 50

/* Structure to store student information */
typedef struct
{
    int id;
    char name[NAME_LENGTH];
    int age;
    char course[COURSE_LENGTH];
    float marks;
} Student;

/* Function prototypes */
void addStudent(void);
void deleteStudent(void);
void updateStudent(void);
void searchStudent(void);
void displayStudents(void);

int studentExists(int id);
void displayStudent(Student student);
void clearInputBuffer(void);

/* Clear unwanted characters from input buffer */
void clearInputBuffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        /* Clear input buffer */
    }
}

/* Check whether a student ID already exists */
int studentExists(int id)
{
    FILE *file;
    Student student;

    file = fopen(FILE_NAME, "rb");

    if (file == NULL)
    {
        return 0;
    }

    while (fread(&student, sizeof(Student), 1, file) == 1)
    {
        if (student.id == id)
        {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

/* Display one student's details */
void displayStudent(Student student)
{
    printf("\n----------------------------------------\n");
    printf("Student ID : %d\n", student.id);
    printf("Name       : %s\n", student.name);
    printf("Age        : %d\n", student.age);
    printf("Course     : %s\n", student.course);
    printf("Marks      : %.2f\n", student.marks);
    printf("----------------------------------------\n");
}

/* Add a new student */
void addStudent(void)
{
    FILE *file;
    Student student;

    printf("\n========== Add Student ==========\n");

    printf("Enter Student ID: ");
    scanf("%d", &student.id);
    clearInputBuffer();

    if (studentExists(student.id))
    {
        printf("Error: Student ID already exists.\n");
        return;
    }

    printf("Enter Student Name: ");
    fgets(student.name, NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = '\0';

    printf("Enter Age: ");
    scanf("%d", &student.age);
    clearInputBuffer();

    printf("Enter Course: ");
    fgets(student.course, COURSE_LENGTH, stdin);
    student.course[strcspn(student.course, "\n")] = '\0';

    printf("Enter Marks: ");
    scanf("%f", &student.marks);
    clearInputBuffer();

    file = fopen(FILE_NAME, "ab");

    if (file == NULL)
    {
        printf("Error: Unable to open student database.\n");
        return;
    }

    fwrite(&student, sizeof(Student), 1, file);
    fclose(file);

    printf("\nStudent record added successfully.\n");
}

/* Delete a student */
void deleteStudent(void)
{
    FILE *file;
    FILE *tempFile;

    Student student;
    int id;
    int found = 0;

    printf("\n========== Delete Student ==========\n");

    printf("Enter Student ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    file = fopen(FILE_NAME, "rb");

    if (file == NULL)
    {
        printf("No student records found.\n");
        return;
    }

    tempFile = fopen(TEMP_FILE, "wb");

    if (tempFile == NULL)
    {
        printf("Error: Unable to create temporary file.\n");
        fclose(file);
        return;
    }

    while (fread(&student, sizeof(Student), 1, file) == 1)
    {
        if (student.id == id)
        {
            found = 1;
        }
        else
        {
            fwrite(&student, sizeof(Student), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found)
    {
        remove(FILE_NAME);
        rename(TEMP_FILE, FILE_NAME);

        printf("\nStudent record deleted successfully.\n");
    }
    else
    {
        remove(TEMP_FILE);
        printf("\nStudent ID not found.\n");
    }
}

/* Update an existing student */
void updateStudent(void)
{
    FILE *file;
    Student student;

    int id;
    int found = 0;

    printf("\n========== Update Student ==========\n");

    printf("Enter Student ID to update: ");
    scanf("%d", &id);
    clearInputBuffer();

    file = fopen(FILE_NAME, "rb+");

    if (file == NULL)
    {
        printf("No student records found.\n");
        return;
    }

    while (fread(&student, sizeof(Student), 1, file) == 1)
    {
        if (student.id == id)
        {
            found = 1;

            printf("\nCurrent Student Details:");
            displayStudent(student);

            printf("\nEnter New Name: ");
            fgets(student.name, NAME_LENGTH, stdin);
            student.name[strcspn(student.name, "\n")] = '\0';

            printf("Enter New Age: ");
            scanf("%d", &student.age);
            clearInputBuffer();

            printf("Enter New Course: ");
            fgets(student.course, COURSE_LENGTH, stdin);
            student.course[strcspn(student.course, "\n")] = '\0';

            printf("Enter New Marks: ");
            scanf("%f", &student.marks);
            clearInputBuffer();

            /*
             * Move the file pointer back by one record
             * and overwrite the old record.
             */
            fseek(file, -(long)sizeof(Student), SEEK_CUR);

            fwrite(&student, sizeof(Student), 1, file);

            printf("\nStudent record updated successfully.\n");
            break;
        }
    }

    fclose(file);

    if (!found)
    {
        printf("\nStudent ID not found.\n");
    }
}

/* Search for a student */
void searchStudent(void)
{
    FILE *file;
    Student student;

    int id;
    int found = 0;

    printf("\n========== Search Student ==========\n");

    printf("Enter Student ID to search: ");
    scanf("%d", &id);
    clearInputBuffer();

    file = fopen(FILE_NAME, "rb");

    if (file == NULL)
    {
        printf("No student records found.\n");
        return;
    }

    while (fread(&student, sizeof(Student), 1, file) == 1)
    {
        if (student.id == id)
        {
            displayStudent(student);
            found = 1;
            break;
        }
    }

    fclose(file);

    if (!found)
    {
        printf("\nStudent ID not found.\n");
    }
}

/* Display all students */
void displayStudents(void)
{
    FILE *file;
    Student student;
    int count = 0;

    printf("\n========== Student Records ==========\n");

    file = fopen(FILE_NAME, "rb");

    if (file == NULL)
    {
        printf("No student records found.\n");
        return;
    }

    printf("\n%-8s %-20s %-8s %-20s %-10s\n",
           "ID", "Name", "Age", "Course", "Marks");

    printf("------------------------------------------------------------------\n");

    while (fread(&student, sizeof(Student), 1, file) == 1)
    {
        printf("%-8d %-20s %-8d %-20s %-10.2f\n",
               student.id,
               student.name,
               student.age,
               student.course,
               student.marks);

        count++;
    }

    fclose(file);

    if (count == 0)
    {
        printf("No student records available.\n");
    }
    else
    {
        printf("\nTotal Records: %d\n", count);
    }
}

/* Main function */
int main(void)
{
    int choice;

    do
    {
        printf("\n============================================\n");
        printf("       STUDENT RECORD MANAGEMENT SYSTEM\n");
        printf("============================================\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Update Student\n");
        printf("4. Search Student\n");
        printf("5. Display All Students\n");
        printf("6. Exit\n");
        printf("============================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                deleteStudent();
                break;

            case 3:
                updateStudent();
                break;

            case 4:
                searchStudent();
                break;

            case 5:
                displayStudents();
                break;

            case 6:
                printf("\nExiting Student Record Management System...\n");
                break;

            default:
                printf("\nInvalid choice. Please select 1-6.\n");
        }

    } while (choice != 6);

    return 0;
}
