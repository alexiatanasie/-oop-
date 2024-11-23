#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//if we have a pointer in the class:
//MANDATORY: 
//CONSTRUCTORS
//DESTRUCTOR
//COPY CONSTRUCTOR
//OPERATOR=

//if the pointer cannot have its dimension calculated(ex char) we need ti have another attribute that will keep the dimension of the pointer attribute

class Doctor {
	const string personelID; //const attribute

	string name;
	int age;
	char* speciality;
	int nbShifts;

	static int nbDoctors;

public:
	//default ctr
	Doctor() : personelID(to_string(nbDoctors + 5)) {
		name = "default name";
		age = 0;
		speciality = nullptr;
		nbShifts = 0;
		nbDoctors++;
	}
	//ctr with param
	Doctor(string name, int age, const char* speciality, int nbShifts) :personelID(to_string(nbDoctors + 5)) {
		this->name = name;
		this->age = age;
		if (speciality != nullptr) {
			this->speciality = new char[strlen(speciality) + 1];
			strcpy_s(this->speciality, strlen(speciality) + 1, speciality);

		}
		else {
			this->speciality = nullptr;
		}
		this->nbShifts = nbShifts;
		nbDoctors++;
	}
	//copy ctr
	Doctor(const Doctor& d) :personelID(d.personelID) {
		this->name = d.name;
		this->age = d.age;
		if (d.speciality != nullptr) {
			this->speciality = new char[strlen(d.speciality) + 1];
			strcpy_s(this->speciality, strlen(d.speciality) + 1, d.speciality);

		}
		else {
			this->speciality = nullptr;
		}
		this->nbShifts = d.nbShifts;
		nbDoctors++;


	}
	//destructor
	~Doctor() {
		if (this->speciality != nullptr) {
			delete[]this->speciality;
			this->speciality = nullptr;
		}
		nbDoctors--;
	}
	//getters 
	string getName() {
		return name;
	}
	int getAge() {
		return age;

	}
	char* getSpeciality() {
		char* copy;
		copy = new char[strlen(this->speciality) + 1];
		strcpy_s(copy, strlen(speciality) + 1, speciality);
		return copy;
	}
	int getnbShifts() {
		return nbShifts;
	}
	//setters
	void setname(string name) {
		if (name != "") {
			this->name = name;
		}
	}
	void setage(int age) {
		if (age > 20) {
			this->age = age;
		}
	}
	
	void setnbShifts(int nb)
	{
		this->nbShifts = nb;
	}
	void setSpeciality(const char* sp) {
		if (sp != nullptr) {
			if (this->speciality != nullptr) {
				delete[]this->speciality;
				this->speciality = new char[strlen(sp) + 1];
				strcpy_s(this->speciality, strlen(sp) + 1, sp);

			}
			else {
				this->speciality = new char[strlen(sp) + 1];
				strcpy_s(this->speciality, strlen(sp) + 1, sp);
			}
		}
	}
	//static getter and setter (static attribute)
	static int getNbDoctors() {
		return nbDoctors;
	}
	static void setNbDoctors(int nb) {
		Doctor::nbDoctors = nb;
	}
	//operator= 
	Doctor& operator=(const Doctor& d) {
		if (this != &d) {
			this->name = d.name;
			this->age = d.age;
			if (this->speciality!=nullptr && d.speciality != nullptr) {
				delete[]this->speciality;
				this->speciality = new char[strlen(d.speciality) + 1];
				strcpy_s(this->speciality, strlen(d.speciality) + 1, d.speciality);

			}
			else if (d.speciality != nullptr) {
				this->speciality = new char[strlen(d.speciality) + 1];
				strcpy_s(this->speciality, strlen(d.speciality) + 1, d.speciality);
			}
			else {
				this->speciality = nullptr;
			}
			this->nbShifts = d.nbShifts;

			
		}
		return *this;
	}
};
int Doctor::nbDoctors = 0;
int main()
{
	
	Doctor d1; //creare obiect doctor fol ctr default
	Doctor d2 ("Dominic", 53, "Chirurg", 5); //creare obiect doctor fol ctr 
	cout << d2.getName() << " " << d2.getAge() << " " << d2.getSpeciality() << " " << d2.getnbShifts() << endl;
	
	//modificare atribute pt nume si varsta
	d2.setname("Iosif");
	d2.setage(51);
	cout << d2.getName() << " " << d2.getAge() << " " << d2.getSpeciality() << " " << d2.getnbShifts() << endl;


	Doctor d3 = d2;//copy ctr
	Doctor d4(d2); //another way to call the copy ctr
	cout << d3.getName() << " " << d3.getAge() << " " << d3.getSpeciality() << " " << d3.getnbShifts() << endl;
	cout << d4.getName() << " " << d4.getAge() << " " << d4.getSpeciality() << " " << d4.getnbShifts() << endl;

	//afisare atribute pt default ctr
	cout << d1.getName() << " " << d1.getAge() << " " << d1.getnbShifts() << endl;
	d1 = d3; //copiaza d3 in d1 
	cout << d1.getName() << " " << d1.getAge() << " " << d1.getSpeciality() << " " << d1.getnbShifts() << '\n';


}

