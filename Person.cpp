#include "Person.h"

Person::Person(string sname ) {
	this->name = sname;
}

string Person::getName() {
	return this->name;
}