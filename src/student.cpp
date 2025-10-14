#include "program3.hpp"

Student::Student() : szStudentID("A00000000"), szStudentName("Test Student") {};

Student::Student(string id, string name) : szStudentID(id), szStudentName(name) {};

Student::Student(const Student& other) : szStudentID(other.szStudentID), 
                                         szStudentName(other.szStudentName){};

Student::~Student() {};

string Student::getStudentInfo()
{
    return szStudentID + ": " + szStudentName;
};

