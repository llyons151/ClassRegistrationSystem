#include "program3.h"
#include <iostream>
using namespace std;

/*********************************************************************
File name: program3_driver.cpp
Author: Dr.Patrick (ueg11)
Date: 09/02/2025

Purpose:
    Driver for program 3 to simulate course registration.
Command Parameters:
    File with course and student information.
Input:
    User input
Results:
    Course simulation.
Notes:
    -
*********************************************************************/
int main(int argc, char *argv[])
{
	// Check for command line arguments
	if(argc != 2)
    {
        std::cout << "Not enough arguments" << std::endl;
        return -1;
    }

    // Testing Student class
    std::cout << "=== Testing Student Class ===" << std::endl;
    
    // Default constructor
    Student defaultStudent;
    std::cout << "Default Student Info: " << defaultStudent.getStudentInfo() << std::endl;

    // Parameterized constructor
    Student student1("A12345678", "Alice Johnson");
    Student student2("A87654321", "Bob Smith");
    std::cout << "Student 1 Info: " << student1.getStudentInfo() << std::endl;
    std::cout << "Student 2 Info: " << student2.getStudentInfo() << std::endl;

    // Copy constructor
    Student copiedStudent = student1;
    std::cout << "Copied Student Info (from Student 1): " << copiedStudent.getStudentInfo() << std::endl;

    // Testing Course class with Students
    std::cout << "\n=== Testing Course Class ===" << std::endl;

    // Default constructor for Course
    Course course1;
    std::cout << "Default Course Info:\n" << course1.getCourseInfo() << std::endl;

    // Parameterized constructor for Course
    Course course2("CS2308", "Data Structures", 3);
    std::cout << "Parameterized Course Info:\n" << course2.getCourseInfo() << std::endl;

    // Enroll students in course2
    std::cout << "\nEnrolling Students in Course 2:" << std::endl;
    course2.enrollStudent(student1);
    course2.enrollStudent(student2);

    // Enroll additional student to check capacity limit
    Student student3("A11223344", "Charlie Brown");
    Student student4("A99887766", "Daisy Ridley");
    course2.enrollStudent(student3);

    if (!course2.enrollStudent(student4)) 
	{
        std::cout << "Failed to enroll Daisy Ridley; max capacity reached.\n";
    }

    // Display students in course2
    std::cout << "\nCurrent Students in Course 2:\n";
    course2.displayStudents();

    // Test increaseMaxEnrollment
    cout << "\nIncreasing max enrollment by 2.\n";
    course2.increaseMaxEnrollment(2);

    // Attempt to enroll an additional student now that capacity has increased
    course2.enrollStudent(student4);

    // Display updated students in course2
    std::cout << "\nStudents in Course 2 after increasing capacity:\n";
    course2.displayStudents();

    // Test copy constructor for Course
    Course course3 = course2;
    std::cout << "\nCopied Course (course3) Info and Students:\n";
    std::cout << course3.getCourseInfo();
    course3.displayStudents();

    // Test assignment operator for Course
    Course course4;
    course4 = course2;
    std::cout << "\nAssigned Course (course4) Info and Students:\n";
    std::cout << course4.getCourseInfo();
    course4.displayStudents();

    // Set up the input file stream
    ifstream fileInput;
	fileInput.open(argv[1]);
    if (!fileInput) 
	{
        std::cerr << "Error: Could not open file." << std::endl;
        return -1;
    }

    // Define maximum array sizes for testing purposes
    const int MAX_COURSES = 20;
    const int MAX_STUDENTS = 150;

    // Create arrays to hold courses and students
    Course coursesArr[MAX_COURSES];
    Student studentArr[MAX_STUDENTS];

    int iCIndex = 0; // Index for courses array
    int iSIndex = 0; // Index for students array

    // Call the function to process course information from the file
    processCourseInformation(fileInput, coursesArr, studentArr, iCIndex, iSIndex);

    // Close the file input stream
    fileInput.close();

    // Output the processed data for verification
    std::cout << "\n=== Processed Course and Student Information from File ===\n";
    for (int i = 0; i < iCIndex; i++) 
	{
        std::cout << coursesArr[i].getCourseInfo();
        std::cout << "Enrolled Students:\n";
        coursesArr[i].displayStudents();
        std::cout << "--------------------\n";
    }

    std::cout << "Total Courses Processed: " << iCIndex << std::endl;
    std::cout << "Total Students Processed: " << iSIndex << std::endl;

    return 0;
}
