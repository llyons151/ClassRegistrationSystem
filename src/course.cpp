#include "course.hpp"

Course::Course() : 
        szCourseID("XXX0000"),
        szCourseName("Test Course"),
        iMaxStudents(10),
        iNumEnrolled(0)
{
    studentEnrolled = new Student[iMaxStudents];
};

Course::Course(string id, string name, int capacity) :
        szCourseID(id),
        szCourseName(name),
        iMaxStudents(capacity),
        iNumEnrolled(0)
{
    studentEnrolled = new Student[iMaxStudents];
};

Course::Course(const Course& other) :
        szCourseID(other.szCourseID),            
        szCourseName(other.szCourseName),
        iMaxStudents(other.iMaxStudents),
        iNumEnrolled(other.iNumEnrolled)
{
    studentEnrolled = new Student[iMaxStudents];
    for(int i = 0; i < other.iNumEnrolled; i++)
    {
        studentEnrolled[i] = other.studentEnrolled[i];
    };
};

Course& Course::operator=(const Course& other)
{
    if(this == &other) return *this;

    Student* newArr = new Student[other.iMaxStudents];
    for(int i = 0; i < other.iNumEnrolled; i++)
    {
        newArr[i] = other.studentEnrolled[i];
    };

    delete[] studentEnrolled;
    studentEnrolled = newArr;

    szCourseID    = other.szCourseID;   
    szCourseName = other.szCourseName;
    iMaxStudents = other.iMaxStudents;
    iNumEnrolled = other.iNumEnrolled;

    return *this;
};

Course::~Course()
{
    delete[] studentEnrolled;
};

string Course::getCourseInfo()
{
    std::string info = szCourseID + ": " + szCourseName +
                       ", Capacity: " + std::to_string(iMaxStudents) +
                       ", Enrollment: " + std::to_string(iNumEnrolled);
    return info;
};

bool Course::enrollStudent(const Student& newStudent)
{
    if(iMaxStudents == iNumEnrolled)
    {
        std::cout << "Max capacity reached. Please increase the course capacity before adding more students." << std::endl;
        return false;
    };

    studentEnrolled[iNumEnrolled] = newStudent;
    iNumEnrolled++;
    return true;
};

void Course::displayStudents() 
{
    std::cout << getCourseInfo() << std::endl;

    for (int i = 0; i < iNumEnrolled; ++i) {
        std::cout << studentEnrolled[i].getStudentInfo() << std::endl;
    }
}

void Course::increaseMaxEnrollment(int additionalCapacity)
{
    Student* tempStudentEnrolled = new Student[iMaxStudents + additionalCapacity];
    for(int i = 0; i < iNumEnrolled; i++)
    {
        tempStudentEnrolled[i] = studentEnrolled[i];
    };
    delete[] studentEnrolled;
    studentEnrolled = tempStudentEnrolled;
    iMaxStudents += additionalCapacity;
};
