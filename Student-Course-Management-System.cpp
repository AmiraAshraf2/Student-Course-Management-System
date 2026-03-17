#include "Student.h"
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

map<int, Student> indexedStudents;

void addStudent() {

    int id;
    string name;
    double gpa;

    cout << "Enter Student ID: ";
    cin >> id;
    // Check if the student ID used
    if (indexedStudents.count(id)) {
        cout << "Student ID already exists!\n";

    }
    else {

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter GPA (0 - 4): ";
        cin >> gpa;

        if (gpa < 0 || gpa > 4) {
            cout << "Invalid GPA\n";
            return;
        }

        indexedStudents.insert({ id, Student(id,name, gpa) });

        cout << "Student added successfully\n";
    }

}

void removeStudent() {

    int id;
    cout << "Enter Student ID: ";
    cin >> id;
    // Check if the student exist
    if (!indexedStudents.count(id)) {
        cout << "Student not found\n";
    }
    else
    {
        indexedStudents.erase(id);
        cout << "Student removed successfully\n";
    } 
}

void searchStudent() {

    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    if (indexedStudents.count(id)){
        cout << "Student was found \n";
        indexedStudents.at(id).display();
    }
   
    else
        cout << "Student not found\n";
}

void displayStudents() {

    if (indexedStudents.empty()) {
        cout << "No students available\n";
        return;
    }

    for (auto& indstudt : indexedStudents) {
        indstudt.second.display();
    }     
}

void enrollCoursefunc() {

    int id;
    string course;

    cout << "Enter Student ID: ";
    cin >> id;

    if (!indexedStudents.count(id)) {
        cout << "Student not found\n";
        return;
    }

    cout << "Enter Course Name: ";
    cin >> course;

    indexedStudents.at(id).enrollCourse(course);

    cout << "Course added successfully\n";
}

void showCourses() {

    int id;

    cout << "Enter Student ID: ";
    cin >> id;

    if (!indexedStudents.count(id)) {
        cout << "Student not found\n";
        return;
    }

    indexedStudents.at(id).showCourses();
}

void sortStudents() {

    vector<Student> temp;

    for (auto& p : indexedStudents)
        temp.push_back(p.second);

    sort(temp.begin(), temp.end(),
        [](Student& a, Student& b) {
            return a.getGpa() > b.getGpa();
        });

    cout << "\nStudents Sorted by GPA:\n";

    for (auto& s : temp)
        s.display();
}

void saveDataInFlie() {
    ofstream studentFile;
    studentFile.open("studentdata.txt");
    if (!studentFile.is_open()) {
        cout << "can't open the file";
        return;
    }
    if (indexedStudents.empty()) {
        cout << "No students available to save\n";
        return;
    }

    for (auto& indstudt : indexedStudents) {
        studentFile << "ID: " << indstudt.second.getId() << endl;
        studentFile << "Name: " << indstudt.second.getName() << endl;
    }
}





int main()
{
    int choice;

    do {

        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Search Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Enroll Student in Course\n";
        cout << "6. Show Student Courses\n";
        cout << "7. Sort Students by GPA\n";
        cout << "8. Load data from file\n";
        cout << "9. Save data to file\n";
        cout << "10. Save data to database\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice) {

        case 1: addStudent(); break;
        case 2: removeStudent(); break;
        case 3: searchStudent(); break;
        case 4: displayStudents(); break;
        case 5: enrollCoursefunc(); break;
        case 6: showCourses(); break;
        case 7: sortStudents(); break;
        case 8: cout << "Goodbye\n"; break;
        case 9: cout << "Goodbye\n"; break;
        case 10: cout << "Goodbye\n"; break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 8);
    return 0;
}
