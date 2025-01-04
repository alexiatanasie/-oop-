// overloaded operators
// constant attributes
// static methods

#include <iostream>
#include <string>
using namespace std;

class Utility {
public:
	static char* copyCharArray(const char* value) {
		return nullptr;
	}
};

class Person {

};

class Student {


	int grades[100];
	string name = "";
	int age = 0;
	float gradesAverage = 0;

	static int MIN_NAME_SIZE;

	static int COUNTER;

public:
	const int id;
	const int uniqueId;

	const static int MAX_NAME_SIZE = 255;

	Student(string name) : id(1), uniqueId(++Student::COUNTER) {
		//this->id = 1;
		//Student::COUNTER += 1;
		//this->uniqueId = Student::COUNTER;

		if (name.size() < Student::MIN_NAME_SIZE) {
			throw "Wrong name";
		}

	}

	Student(string name, int id) : id(id), uniqueId(++Student::COUNTER) {
		this->name = name;
		//this->id = id;
	}

	// : is named the ctor initialization list
	Student(string name, int id, int inputAge)
		: id(id), name(name), age(inputAge), uniqueId(++Student::COUNTER) {
		//this->name = name;
		//this->id = id;
	}

	//don't provide a setter for id -> no one can change it


	//static methods are called directly
	//there is NO this in static methods
	static int getNameMinSize() {
		return Student::MIN_NAME_SIZE;
	}

	static void checkUniversityFees() {
		//do something related with students but 
		// not to a particular student
	}

	void takeExam(string course) {
		// this is a method for each student
	}

	//overload operators
	void operator=(const Student& s) {
		this->age = s.age;
		//this->id = s.id;
		this->name = s.name;
	}

	void operator+=(int v) {
		this->age += v;
	}

	Student operator-(int v) {
		////the MISTAKE
		//this->age -= v;
		//return *this;

		Student result = *this;
		result.age -= v;
		return result;
	}

	bool operator>=(Student s) {
		return this->age >= s.age;
	}

	bool operator!() const {
		return this->age <= 0;
	}
	// Pre-increment (++bob)
	Student& operator++() {
		this->age++;
		return *this;
	}

	// Post-increment (bob++)
	Student operator++(int) {
		Student temp = *this;
		this->age++;
		return temp;
	}
	// Pre-decrement (--bob)
	Student& operator--() {
		this->age--;
		return *this;
	}

	// Post-decrement (bob--)
	Student operator--(int) {
		Student temp = *this;
		this->age--;
		return temp;
	}

	//CAST explicit pentru a realiza conversia între Student și Person
	operator Person() const {
		return Person(); 
	}

	explicit operator int() const {
		return this->age;
	}

	bool operator()(int lower, int upper) const {
		return this->age >= lower && this->age <= upper;
	}
	int& operator[](int index) {
		if (index < 0 || index >= 100) {
			throw ("Index out of range");
		}
		return this->grades[index];
	}



	friend Student operator+(int v, Student s);
};

int Student::MIN_NAME_SIZE = 3;
//const int Student::MAX_NAME_SIZE = 255;
int Student::COUNTER = 0;

Student operator+(int v, Student s) {
	Student result = s;
	result.age += v;
	return result;
}

void operator<<(ostream& console, Student s) {

}

void operator>>(istream& console, Student& s) {

}

int main() {
	string name = "John";

	if (name.size() >= Student::getNameMinSize() &&
		name.size() < Student::MAX_NAME_SIZE) {
		Student john("John");
		john.takeExam("OOP");

		//john.id = 100;
	}

	Student::checkUniversityFees();

	Student alice("Alice", 2);
	Student bob("Bob", 2, 20);

	const int vb = 10;

	//overload operators

	// operator =	
	bob = alice;

	// input and output streams << and >>
	cout << endl << bob;
	cin >> bob;

	//math operators - binary +=, -=, *=, /=
	bob += 2; //add 2 to Bob's age


	//math operators - binary +, -, * and /
	//these operator DON"T change the value of the operands
	bob = bob - 2; //create a copy of Bob with age - 2
	bob = 2 + bob;


	//logic operator - binary ==,>=,>,<,<=
	if (bob >= alice) {
		cout << endl << "Bob has an age bigger or equal than Alice";
	}

	//logic operator - unary - !
	if (!bob) {
		cout << endl << "Bob can't buy an enery drink";
	}

	//post an pre operators - ++obj, obj++, --obj, obj--
	Student temp = ++bob; //create a copy of Bob with age + 1
	Student clone = bob--;

	//cast operator - (type)
	Person person = (Person)bob;
	int bobAge = (int)bob;

	//function operator - ()
	bool hasValidAge = bob(10, 35);// check if Bob age is between given limits

	//index operator - []
	int secondGrade = bob[1];


	//by me:
	bob += 5; 
	cout << "Operator +=: Bob's new age is " << (int)bob << endl;

	Student olderBob = bob - 3; 
	cout << "Operator -: Older Bob's age is " << (int)olderBob << endl;

	if (bob >= alice) {
		cout << "Operator >=: Bob is older or the same age as Alice." << endl;
	}
	else {
		cout << "Operator >=: Bob is younger than Alice." << endl;
	}

	if (!bob) {
		cout << "Operator !: Bob is too young to register." << endl;
	}
	else {
		cout << "Operator !: Bob has a valid age." << endl;
	}

	// Prefix increment
	++bob;
	cout << "Operator ++ (prefix): Bob's age is now " << (int)bob << endl;

	// Postfix increment
	bob++;
	cout << "Operator ++ (postfix): Bob's age after increment is " << (int)bob << endl;

	// Prefix decrement
	--bob;
	cout << "Operator -- (prefix): Bob's age is now " << (int)bob << endl;

	// Postfix decrement
	bob--;
	cout << "Operator -- (postfix): Bob's age after decrement is " << (int)bob << endl;

	int age = (int)bob;
	cout << "Cast operator (int): Bob's age is " << age << endl;

	if (bob(18, 25)) {
		cout << "Operator (): Bob's age is within the valid range (18-25)." << endl;
	}
	else {
		cout << "Operator (): Bob's age is not within the valid range (18-25)." << endl;
	}

	// Index operator
	bob[0] = 10;
	cout << "Bob's first grade is " << bob[0] << endl;

	// Input/output stream operators
	cout << bob;

	cin >> bob;


}