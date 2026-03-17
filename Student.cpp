#include "Student.h"
Student::Student(int sid, string sname, double sgpa) :Person(sname) {
	this->id = sid;
	this->gpa = sgpa;
}
int Student::getId(){
	return this->id;
}
double Student::getGpa() {
	return this->gpa;
}
void Student::enrollCourse(string course) {
	this->courses.insert(course);
}
void Student::showCourses() {
	if (this->courses.empty()) {
		cout << this->name << " didn't enrolled in any courses" << endl;
	}
	else
	{
		for (string course : this->courses)
		{
			cout << course << ", ";
		}
	}
}
void Student::display() {
	cout << "ID: " << this->id << endl;
	cout << "Name: " << this->name << endl;
	cout << "GPA: " << this->gpa << endl;
}