#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

inline string szBreakMessage = "*****************************\n";

/*********************************************************************
Class Name: Student
Purpose:
    The Student class represents a student who registers for a course.
Notes:
    -
*********************************************************************/
class Student
{
    private:
        string szStudentID;         // A number of the student
        string szStudentName;       // Full name of the student
    public:
        Student();
        Student(string, string);
        Student(const Student& );
        ~Student();
        string getStudentInfo();
};

/*********************************************************************
Class Name: Course
Purpose:
    The Course class represents a course which students register for.
Notes:
    -
*********************************************************************/
class Course
{
    private:
        string szCourseID;          // Course code (CS2308)
        string szCourseName;        // Name of the course
        int iMaxStudents;           // Max number of students for course
        Student* studentEnrolled;   // Students currently enrolled
        int iNumEnrolled;           // Current students enrolled

    public:
        Course();
        Course(string, string, int);
        Course(const Course& );
        Course& operator=(const Course&);
        ~Course();
        string getCourseInfo();
        bool enrollStudent(const Student&);
        void displayStudents();
        void increaseMaxEnrollment(int);
};

void processCourseInformation(ifstream&, Course*, Student*, int&, int&);
