#include "student.hpp"

Student::Student() : szStudentID("A00000000"), szStudentName("Test Student") {};

Student::Studnet(string id, string name) : szStudentID(id), szStudentName(name) {};

Student::Student(const Student& other) : szStudnetID(other.szStudentID), 
                                         szStudentName(other.szStudentName){};

Student::~Student() {};

string Student::getStudnetInfo()
{
    return szStudnetID + ": " + szStudentName;
};

