//course 5
#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include <iostream>
using namespace std;

enum class StudentType
{
    Bachelor=10,
    Master,
    Phd=20
};

class Student {
private: //you get it by default
    string name = "";
    int age = 0;
    string address = "";
    int grades[10];
    int noGrades = 0;
    int* bonusPoints = nullptr;
    int noBonusPoints = 0;
    char* faculty = nullptr;
    char university[100] = "ase";

    bool hasScholarship = false;
    bool isErasmusStud = false;
    StudentType type = StudentType::Bachelor;
    char gender;

public:
    static const int MIN_AGE = 18;
    static const int MAX_AGE = 30;
    static const int MIN_NAME = 5;
    static int nrGirls;
    static int nrBoys;

public:
    string getName() {
        return this->name;
    }
    void setName(string newName) {
        if (newName.size() <= Student::MIN_NAME) {
            throw exception("name too short");
        }
        this->name = newName;
    }
    int getAge() {
        return this->age;

    }
    void setAge(int val) {
        if (val >= MIN_AGE && val <= MAX_AGE) {
            this->age = val;
        }
        else { throw new exception("wrong value"); }
    }
    char* getFaculty() {
        return this->faculty;
    }
    char* getUniversity() {
        char* copy = new char[strlen(this->university) + 1];
        strcpy_s(copy, strlen(this->university) + 1, this->university);
        return copy;
    }

    int* getBonusPoints() {
        int* copyy = new int[this->noBonusPoints];
        for (int i = 0; i < this->noBonusPoints; i++) {
            copyy[i] = this->bonusPoints[i];
        }
        return copyy;
    }

    int getNoBonusPoints()
    {
        return this->noBonusPoints;
    }
    void setFaculty(char* newFaculty) {
        if (newFaculty == nullptr) {
            throw exception("invalid faculty name");
        }

    //elibereaza memoria veche, daca exista
        if (this->faculty != nullptr) {
            delete[] this->faculty;
        }
        //aloca memorie pt noul string si copiaza continutul
        this->faculty = new char[strlen(newFaculty) + 1];
        strcpy_s(this->faculty, strlen(newFaculty) + 1, newFaculty);
    }

    void getsScholarship() {
        this->hasScholarship = true;
    }
    void losesScholarship() {
        this->hasScholarship = false;
    }

    Student(string name, int age) {
        this->name = name;
        this->setAge(age);
    }

    Student(string name, int age, char gender) {
        this->name = name;
        this->setAge(age);
        this->gender = gender;
    }
    Student(string name, char gender, int age, int* bonusPoints, int noBonusPoints) {
        this->name = name;
        this->gender = gender;
        this->setAge(age);
        this->noBonusPoints = noBonusPoints;
        this->bonusPoints = new int[noBonusPoints];
        for (int i = 0; i < noBonusPoints; i++) {
            this->bonusPoints[i] = bonusPoints[i];
        }
    }

    Student() {}

    //destructor
    ~Student() {
        if (this->faculty != nullptr) {
            delete[] this->faculty;
        }
        if (this->bonusPoints != nullptr) {
            delete[] this->bonusPoints;
        }
    }
    //copy ctr
    Student(const Student& other) {
        this->name = other.name;
        this->age = other.age;
        this->address = other.address;
        this->noGrades = other.noGrades;
        memcpy(this->grades, other.grades, sizeof(int) * 100);
        this->noBonusPoints = other.noBonusPoints;
        if (other.bonusPoints != nullptr) {
            this->bonusPoints = new int[other.noBonusPoints];
            memcpy(this->bonusPoints, other.bonusPoints, sizeof(int) * other.noBonusPoints);
        }
        else {
            this->bonusPoints = nullptr;
        }
        if (other.faculty != nullptr) {
            this->faculty = new char[strlen(other.faculty) + 1];
            strcpy_s(this->faculty, strlen(other.faculty) + 1, other.faculty);
        }
        else {
            this->faculty = nullptr;
        }
        strcpy_s(this->university, 100, other.university);
        this->hasScholarship= other.hasScholarship;
        this->isErasmusStud= other.isErasmusStud;
        this->type = other.type;
        this->gender = other.gender;
    }
};
//init a NON CONSTANT STATIC attribute
int Student::nrGirls = 0;
int Student::nrBoys = 0;
int main()
{
    Student john;
    Student* pStudent = new Student();

    delete pStudent;

    Student alice("Alice", 23);
    pStudent = new Student("Bob", 21);

    char facultyName[] = "Computer Science";
    john.setFaculty(facultyName);

    cout << "John's faculty: " << john.getFaculty() << endl;

    delete pStudent;
    return 0;
}

