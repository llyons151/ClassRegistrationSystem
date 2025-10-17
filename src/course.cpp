#include "program3.hpp"

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

/*********************************************************************
Function Prototype:
    Course& Course::operator=(const Course& other)

Purpose:
    Perform a deep copy from another Course, resizing internal storage
    and copying enrolled students and metadata.

Parameters:
    I  other (const Course&) : Source Course to copy from.

Return Value:
    Course& : Reference to *this for chaining.

Notes:
    Handles self-assignment; allocates a new Student[] sized to other's
    capacity, copies other.iNumEnrolled elements, then replaces storage.
*********************************************************************/

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

/*********************************************************************
Function Prototype:
    Course::~Course()

Purpose:
    Release dynamically allocated array of enrolled students.

Parameters:
    (none)

Return Value:
    (none)

Notes:
    Matches prior new[] with delete[] to prevent memory leaks.
*********************************************************************/

Course::~Course()
{
    delete[] studentEnrolled;
};

/*********************************************************************
Function Prototype:
    std::string Course::getCourseInfo()

Purpose:
    Produce a human-readable summary of course ID, name, capacity,
    and current enrollment.

Parameters:
    (none)

Return Value:
    std::string : Multi-line description of course metadata.

Notes:
    Does not list individual students; formatting is fixed.
*********************************************************************/

string Course::getCourseInfo()
{
    std::string out;
    out += szCourseID + ": " + szCourseName + "\n";
    out += "Capacity: " + std::to_string(iMaxStudents) + "\n";
    out += "Enrollment: " + std::to_string(iNumEnrolled) + "\n";
    return out;
};

/*********************************************************************
Function Prototype:
    bool Course::enrollStudent(const Student& newStudent)

Purpose:
    Add a student to the course roster if capacity allows.

Parameters:
    I  newStudent (const Student&) : Student to enroll.

Return Value:
    bool : true if enrolled; false if capacity is full.

Notes:
    Prints a warning on capacity overflow; does not check for duplicates.
*********************************************************************/

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

/*********************************************************************
Function Prototype:
    void Course::displayStudents()

Purpose:
    Print the course header and each enrolled student's info to stdout.

Parameters:
    (none)

Return Value:
    (none)

Notes:
    Produces console output as a side effect; relies on Student::getStudentInfo().
*********************************************************************/

void Course::displayStudents() 
{
    std::cout << "Students enrolled in " << getCourseInfo() << std::endl;

    for (int i = 0; i < iNumEnrolled; ++i) 
    {
        std::cout << "-" << studentEnrolled[i].getStudentInfo() << std::endl;
    }
}

/*********************************************************************
Function Prototype:
    void Course::increaseMaxEnrollment(int additionalCapacity)

Purpose:
    Grow internal storage to accommodate more students while preserving
    existing enrollments.

Parameters:
    I  additionalCapacity (int) : Number of extra seats to add.

Return Value:
    (none)

Notes:
    Assumes additionalCapacity > 0; reallocates Student[] and copies
    iNumEnrolled elements, then updates iMaxStudents.
*********************************************************************/

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
