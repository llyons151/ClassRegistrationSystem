/*********************************************************************
File name: utils.cpp
Author: Luke Lyons (ujw18)
Date: 10/14/2025

Purpose:
   Parse a course roster text file and populate arrays of Course and
   Student objects. Enrolls each parsed student into the appropriate course.

Command Parameters:
   - (none; this is a library/source file providing functions)

Input:
   An input stream (ifstream) where courses are listed as:
     <CourseID> <Course Name...>
     <NumberOfStudents>
     <StudentID> <Student Name...>   (repeated for NumberOfStudents)
     *****                           (separator between courses)

Results:
   Updates the provided arrays (Course* and Student*) and increments
   courseCount and studentCount to reflect how many were processed.

Notes:
   Assumes arrays passed in are large enough and the file format is
   well-formed as described. Skips blank lines and separator lines.
*********************************************************************/

#include "program3.hpp"

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
