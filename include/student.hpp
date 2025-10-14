#include <string>

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
