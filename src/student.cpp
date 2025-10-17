#include "program3.hpp"

Student::Student() : szStudentID("A00000000"), szStudentName("Test Student") {};

Student::Student(string id, string name) : szStudentID(id), szStudentName(name) {};

Student::Student(const Student& other) : szStudentID(other.szStudentID), 
                                         szStudentName(other.szStudentName){};

Student::~Student() {};

/*********************************************************************
Function Prototype:
    std::string Student::getStudentInfo()

Purpose:
    Return the student's ID and name in a single formatted string.

Parameters:
    (none)

Return Value:
    std::string – student ID followed by name (e.g., "A00012345: John Doe").

Notes:
    Used for displaying student information in other classes such as Course.
*********************************************************************/

string Student::getStudentInfo()
{
    return szStudentID + ": " + szStudentName;
};

