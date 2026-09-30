# Student Record Management System in C

A menu-driven Student Record Management System developed in C using structures and file handling.

The application allows users to add, delete, update, search, and display student records. Student information is stored permanently in a binary file, allowing the records to remain available even after the program is closed.

This project was developed as part of an internship programming assignment to demonstrate practical knowledge of structures, file handling, functions, and menu-driven programming.

---

## Project Overview

The Student Record Management System provides a simple way to manage student information through a command-line interface.

The system supports the following operations:

* Add a student
* Delete a student
* Update a student
* Search for a student
* Display all student records
* Exit the program

Student records are stored in a binary file named `students.dat`.

---

## Features

* Menu-driven interface
* Add new student records
* Delete existing student records
* Update student information
* Search students using Student ID
* Display all stored records
* Permanent data storage using file handling
* Prevents duplicate Student IDs
* Uses structures to organize student data
* Uses separate functions for each operation
* Supports multiple operations during a single execution

---

## Technologies Used

| Technology         | Purpose                 |
| ------------------ | ----------------------- |
| C                  | Programming Language    |
| GCC                | Compiler                |
| Visual Studio Code | Development Environment |
| Git                | Version Control         |
| GitHub             | Project Hosting         |

---

## Project Structure

```text
Student-Record-Management-C/
│
├── student_record.c
├── students.dat
└── README.md
```

### File Description

**student_record.c**

Contains the complete C source code for the Student Record Management System.

**students.dat**

Binary data file used to permanently store student records. This file is automatically created when the first student record is added.

**README.md**

Contains the project documentation, features, setup instructions, and usage information.

---

## Student Structure

The project uses a structure to store student information.

```c
typedef struct
{
    int id;
    char name[50];
    int age;
    char course[50];
    float marks;
} Student;
```

Each student record contains:

| Field    | Data Type | Description       |
| -------- | --------- | ----------------- |
| `id`     | `int`     | Unique student ID |
| `name`   | `char[]`  | Student name      |
| `age`    | `int`     | Student age       |
| `course` | `char[]`  | Course name       |
| `marks`  | `float`   | Student marks     |

---

## Operations

### 1. Add Student

The user can enter a new student's:

* Student ID
* Name
* Age
* Course
* Marks

The record is then stored permanently in `students.dat`.

The program also checks whether the Student ID already exists.

---

### 2. Delete Student

The user enters the Student ID that needs to be deleted.

The program reads the existing records and copies all records except the selected student into a temporary file.

After successful deletion, the temporary file replaces the original data file.

---

### 3. Update Student

The user enters a Student ID.

If the record exists, the program displays the current information and allows the user to enter updated:

* Name
* Age
* Course
* Marks

The updated record is written back to the data file.

---

### 4. Search Student

The user can search for a student using the Student ID.

If the student exists, the complete record is displayed.

If the ID does not exist, the program displays an appropriate message.

---

### 5. Display All Students

This option reads all records from `students.dat` and displays them in a formatted table.

Example:

```text
ID       Name                 Age      Course               Marks
------------------------------------------------------------------
101      Hariharan            20       ECE                   85.50
102      Arun                 21       CSE                   78.00
103      Kumar                20       EEE                   91.00
```

---

## File Handling

File handling is used to store student records permanently.

The program uses the following file modes:

| Mode  | Purpose                            |
| ----- | ---------------------------------- |
| `ab`  | Add records to the end of the file |
| `rb`  | Read records from the file         |
| `rb+` | Read and update existing records   |
| `wb`  | Create/write the temporary file    |

The student data is stored in:

```text
students.dat
```

Because the data is stored in a file, records remain available after the program terminates.

---

## Delete Operation

The delete operation uses a temporary file.

The process is:

```text
Open students.dat
       |
       v
Read each student record
       |
       v
Is ID equal to requested ID?
       |
    +--+--+
    |     |
   Yes    No
    |     |
 Skip   Copy record
    |     |
    +--+--+
       |
       v
Close files
       |
       v
Replace original file
```

This approach avoids directly removing data from the middle of the binary file.

---

## Functions Used

The program follows a modular programming approach.

| Function             | Purpose                             |
| -------------------- | ----------------------------------- |
| `addStudent()`       | Adds a new student                  |
| `deleteStudent()`    | Deletes a student                   |
| `updateStudent()`    | Updates student information         |
| `searchStudent()`    | Searches for a student              |
| `displayStudents()`  | Displays all records                |
| `studentExists()`    | Checks for duplicate Student IDs    |
| `displayStudent()`   | Displays individual student details |
| `clearInputBuffer()` | Clears unwanted input characters    |

---

## Concepts Demonstrated

This project demonstrates the following C programming concepts:

* Structures
* File handling
* Binary files
* Functions
* Function prototypes
* Arrays
* Strings
* `fopen()`
* `fclose()`
* `fread()`
* `fwrite()`
* `fseek()`
* `remove()`
* `rename()`
* `switch-case`
* `if-else`
* `do-while` loop
* Input validation
* Modular programming
* CRUD operations

---

## CRUD Operations

The project implements the four fundamental data management operations:

| CRUD Operation | Program Feature  |
| -------------- | ---------------- |
| Create         | Add Student      |
| Read           | Search / Display |
| Update         | Update Student   |
| Delete         | Delete Student   |

---

## How to Run the Project

### Prerequisites

Install a C compiler such as GCC.

Visual Studio Code can be used as the development environment with a C/C++ compiler configured.

### Step 1: Clone the Repository

```bash
git clone https://github.com/your-username/Student-Record-Management-C.git
```

### Step 2: Open the Project

```bash
cd Student-Record-Management-C
```

### Step 3: Compile the Program

Using GCC:

```bash
gcc student_record.c -o student_record
```

### Step 4: Run the Program

#### Windows

```bash
student_record.exe
```

#### Linux / macOS

```bash
./student_record
```

---

## Sample Output

```text
============================================
       STUDENT RECORD MANAGEMENT SYSTEM
============================================
1. Add Student
2. Delete Student
3. Update Student
4. Search Student
5. Display All Students
6. Exit
============================================

Enter your choice: 1

========== Add Student ==========

Enter Student ID: 101
Enter Student Name: Hariharan
Enter Age: 20
Enter Course: ECE
Enter Marks: 85.5

Student record added successfully.
```

---

## Search Example

```text
========== Search Student ==========

Enter Student ID to search: 101

----------------------------------------
Student ID : 101
Name       : Hariharan
Age        : 20
Course     : ECE
Marks      : 85.50
----------------------------------------
```

---

## Update Example

```text
========== Update Student ==========

Enter Student ID to update: 101

Current Student Details:

----------------------------------------
Student ID : 101
Name       : Hariharan
Age        : 20
Course     : ECE
Marks      : 85.50
----------------------------------------

Enter New Name: Hariharan J
Enter New Age: 21
Enter New Course: ECE
Enter New Marks: 88.50

Student record updated successfully.
```

---

## Delete Example

```text
========== Delete Student ==========

Enter Student ID to delete: 101

Student record deleted successfully.
```

---

## Learning Objectives

The main objectives of this project are:

1. To understand structures in C.
2. To implement file handling in C.
3. To store data permanently using files.
4. To perform Create, Read, Update, and Delete operations.
5. To implement a menu-driven application.
6. To practice modular programming using functions.
7. To work with binary files.
8. To improve practical problem-solving skills.
9. To understand how simple data management systems work.

---

## Future Improvements

The project can be extended with additional features such as:

* Sorting students by marks
* Sorting students by name
* Searching by name
* Grade calculation
* Percentage calculation
* Attendance management
* Department-wise filtering
* Password-based login
* Separate header and source files
* CSV export
* Student result generation
* Dynamic memory allocation

---

## Author

**HARIHARAN J**

Electronics and Communication Engineering (ECE) Student

Interested in VLSI, RTL Design, SoC, Digital Electronics, and C Programming.

---

## License

This project is created for educational and internship purposes.

You are free to study, modify, and improve the source code for learning purposes.

---

## Acknowledgement

This project was developed as part of an internship programming assignment to strengthen practical knowledge of C programming, structures, file handling, and modular programming.
