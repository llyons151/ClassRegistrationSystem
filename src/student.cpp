/*********************************************************************
File name: Student.cpp
Author: Luke Lyons (ujw18)
Date: 10/14/2025

Purpose:
   Implements the Student class: constructors, copy semantics,
   destructor, and formatted info retrieval.

Command Parameters:
   - None (library/source file).

Input:
   - Constructor parameters (student ID and name).

Results:
   - Stores student ID and name.
   - Provides getStudentInfo() returning "<ID>: <Name>".

Notes:
   - Keep declaration in program3.hpp in sync (e.g., getStudentInfo() const).
*********************************************************************/

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

