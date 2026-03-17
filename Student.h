#ifndef Student_H_
#define Student_H_
#include <set>
#include "Person.h"
#include <iostream>
class Student : public Person
{
private:
	int id;
	double gpa;
	set<string> courses;

public:
	Student(int sid, string sname, double sgpa);
	int getId();
	double getGpa();
	void enrollCourse(string course);
	void showCourses();
	void display();





};
#endif


