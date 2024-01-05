//this code shows 

//the program works and also it works with the commented lines
//the ones commented appear on debug console, but there is an debug error, so yeah...
//tried to fix with g++,but it doesn't work, so i will fix it in 2-3 yrs, maybe...or when i will like/love a lot c++ :))

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

enum Subjects {
	OOP, Micro, Macro
};

class Student {
private:
	int id = 0;
	string name = "";
	float age = 0;
	static int sequence;

public:
	//constructor
	Student(string name, float age) : id(sequence)
	{
		this->name = name;
		this->age = age;
		this->id = id;
		//++Student::sequence;
		Student::sequence = Student::sequence + 1;
	}

	void print()
	{
		cout << "id:" << this->id << endl
			<< "student's name: " << this->name << endl
			<< "is " << this->age << " yo" << endl;
	}
	string getName() {
		return this->name;
	}
	float getAge()
	{
		return this->age;
	}
};
int Student::sequence = 1;

class Grade
{
private:
	float values;
	Subjects subjects;
public:
	Grade(float values, Subjects subjects)
	{
		this->values = values;
		this->subjects = subjects;
	}
	void print() const {
		cout << "grade for ";
		switch (subjects) {
		case Subjects::Micro:
			cout << "Micro";
			break;
		case Subjects::Macro:
			cout << "Macro";
			break;
		case Subjects::OOP:
			cout << "OOP";
			break;
		default:
			cout << "Unknown Subject";
		}
		cout << " is " << values << endl;

	}
};
enum class Semester {
	sem1, sem2
};

//class GradeBook {
//private:
//	Grade** grades;
//	int gradesAssigned;
//	int maxGrades;
//	int year;
//	Semester semester;
//public:
//
//	GradeBook(int maxGrades, int year, Semester semester) : maxGrades(maxGrades), year(year), semester(semester)
//	{
//		this->gradesAssigned = 0;
//		this->grades = new Grade * [maxGrades];
//	}
//	~GradeBook()
//		// Destructor for proper memory cleanup
//	{
//		for (int i = 0; i < gradesAssigned; ++i)
//		{
//			delete grades[i];
//		}
//		delete[] grades;
//	}
//	void addGrade(Grade* grade)
//	{
//		if (gradesAssigned < maxGrades)
//		{
//			this->grades[gradesAssigned++] = grade;
//		}
//		else
//		{
//			throw runtime_error("Error: GradeBook is full. Cannot add more grades.");
//		}
//	}
//	void printGrades() const
//	{
//		for (int i = 0; i < gradesAssigned; ++i)
//		{
//			grades[i]->print();
//		}
//	}
//};
void showStudent(Student& stud)
{
	cout << "student " << stud.getName() << "is "
		<< stud.getAge() << " yo" << endl;
}

int main()
{
	//try{
		Student stud1("Alice ", 19);
		stud1.print();
		Grade grade1(9.6, Subjects::Macro);
		grade1.print();

		cout << endl;
		Student stud2("Bob ", 21);
		stud2.print();
		Grade grade2(6, Subjects::Micro);
		grade2.print();

		cout << endl;
		Student stud3("John ", 21);
		stud3.print();
		Grade grade3(8.66, Subjects::OOP);
		grade3.print();
		cout << endl;

		/*GradeBook gradeBook1(6, 2024, Semester::sem1);
		gradeBook1.addGrade(&grade1);
		cout << endl;

		GradeBook gradeBook2(6, 2023, Semester::sem2);
		gradeBook2.addGrade(&grade2);
		cout << endl;

		GradeBook gradeBook3(6, 2023, Semester::sem1);
		gradeBook3.addGrade(&grade3);

		gradeBook1.printGrades();
		gradeBook2.printGrades();
		gradeBook3.printGrades();
	}

	catch (const exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}*/

	return 0;
}
