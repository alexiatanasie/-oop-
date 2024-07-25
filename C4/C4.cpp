#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include <stdexcept> 
using namespace std;

struct Student {
    string name;
    int age;
    string address;
    int grades[10];
};
class StudentClass
{
    //private-get it by default
    int age = 0;
    string address = "";
    int grades[10];
    int noGrades = 0;
    int* bonusPoints = nullptr;

    //public 
    string name = "";

public:
    //accessor methods
    //getters-read access
    int getAge()
    {
        return this->age;
    }

    //setters-write access
    void setAge(int val) {
        if (val >= 19 && val < 30) {
            this->age = val;
        }
        else {
            throw  exception("wrong value");
        }
    }

    //ctr
    StudentClass(string name, int age) {
        this->name = name;
        this->age = age;
    }
    };

void printStudent(Student student) {
    cout << endl << student.name;
}
int main()
{
    Student student;
    student.name = "Max";
    printStudent(student);

    StudentClass stud("Anna", 23);
    cout << endl<<  stud.getAge();
    try {
        stud.setAge(-24);
    }
    catch (const exception& e) {
        cout << endl << e.what();

    }

}

