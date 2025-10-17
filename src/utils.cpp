#include "program3.hpp"

/*********************************************************************
Function Prototype:
    void processCourseInformation(std::ifstream& fileInput,
                                  Course* courseArr,
                                  Student* studentArr,
                                  int& courseCount,
                                  int& studentCount);

Purpose:
    Read course and student data from a file and populate the given
    Course and Student arrays.

Parameters:
    I  fileInput    – input file stream containing course data.
    O  courseArr    – array to store Course objects.
    O  studentArr   – array to store Student objects.
    O  courseCount  – number of courses read.
    O  studentCount – number of students read.

Return Value:
    None (results stored in output parameters).

Notes:
    • Skips blank lines or lines starting with '*'.
    • Assumes arrays are large enough for all entries.
    • Prints each student name as it is read.
*********************************************************************/

void processCourseInformation(ifstream& fileInput, Course* courseArr, Student* studentArr, int& courseCount, int& studentCount)
{
    courseCount = 0;
    studentCount = 0;
    std::string courseID;
    std::string courseName;
    std::string studentID;
    std::string studentName;
    std::string line;
    int lineBreak;

    while (std::getline(fileInput, line))
    {
        if(line.empty() || line[0] == '*') continue;

        lineBreak = line.find(' ');
        courseID = line.substr(0, lineBreak);
        courseName = line.substr(lineBreak + 1);

        std::getline(fileInput, line);
        int numStudents = std::stoi(line);

        Course newCourse(courseID, courseName, numStudents);

        for(int i = 0; i < numStudents; i++)
        {
            std::getline(fileInput, line);
            if(line.empty() || line[0] == '*') break;

            lineBreak = line.find(' ');
            studentID = line.substr(0, lineBreak);
            studentName = line.substr(lineBreak + 1);
            std::cout << studentName << std::endl;
            Student newStudent(studentID, studentName);
            studentArr[studentCount++] = newStudent;
            newCourse.enrollStudent(newStudent);
        };

        courseArr[courseCount++] = newCourse;
    };
};
