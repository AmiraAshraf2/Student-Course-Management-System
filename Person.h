#ifndef Person_H_
#define Person_H_
#include <string>
using namespace std;
class Person
{
protected: 
	string name;

public:
	Person(string sname = "");
	string getName();
};
#endif



