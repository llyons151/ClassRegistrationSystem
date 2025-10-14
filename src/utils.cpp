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
        if(line.empty() || line[0] == '*') return;

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
            Student newStudent(studentID, studentName);
            studentArr[studentCount++] = newStudent;
            newCourse.enrollStudent(newStudent);
        };

        courseArr[courseCount++] = newCourse;
    };
};
