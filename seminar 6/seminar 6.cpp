#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;
//if we have a pointer in the class
//it is MANDATORY to have:
//constructors
//destructor
//copy constructor
//operator = 


class Doctor {
	const string personelId; //constant attribute
	string name;
	int age;
	char* speciality;
	int nbShifts;

	static int nbDoctors;
public:
	Doctor() :personelId(to_string(nbDoctors + 5)) {
		name = "default name";
		age = 0;
		speciality = new char[strlen("valoare default") + 1];
		strcpy_s(this->speciality, strlen("valoare default") + 1, "valoare default");

		// nu poti sa ii dai valoarea lui speciality = nullptr de la inceput. 
		//atunci cand o sa vrei sa afisezi un obiect care apeleaza default constructorul, gen d1,
		//nu o sa aiba ce sa afiseze daca speciality = nullptr. nullptr nu este o variabila cum e stringul=" " sau int
		//e gen mai mult o adresa nula gen goala si nu are ce sa afiseze in cazul asta 
		nbShifts = 0;
		nbDoctors++;

	}
	Doctor(string name, int age, const char* speciality, int nbShifts) : personelId(to_string(nbDoctors + 5))
		//personelId(personelId)
	{
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
	Doctor(const Doctor& d) : personelId(d.personelId) { //copy ctr
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

	~Doctor() {
		if (this->speciality != nullptr) {
			delete[] this->speciality;
			this->speciality = nullptr;

		}
		nbDoctors--;
	}

	static void doSomething() {
		cout << "the class did smth\n";
	}

	//getters
	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}
	char* getSpeciality() {

		char* copy = new char[strlen(speciality) + 1];
		strcpy_s(copy, strlen(speciality) + 1, speciality);
		return copy;
	}


	int getNbshifts() {
		return nbShifts;
	}

	//setters
	void setName(string name) {
		if (name != "") {
			this->name = name;

		}
	}

	void setAge(int age) {
		if (age > 20) {
			this->age = age;
		}
	}

	void setNbShifts(int nb) {
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

	//static getter and setter(static attribute )
	static int getNbDcotors() {
		return nbDoctors;
	}
	static void setNbDoctors(int nb) {
		Doctor::nbDoctors = nb;

	}
	//d1=d2=d3=d4
	Doctor& operator=(const Doctor& d)
	{
		if (this != &d) {
			this->name = d.name;
			this->age = d.age;
			if (this->speciality != nullptr && d.speciality != nullptr) {
				delete[]this->speciality;
				this->speciality = new char[strlen(d.speciality) + 1];
				strcpy_s(this->speciality, strlen(d.speciality) + 1, d.speciality);
			}
			else if (d.speciality != nullptr)
			{
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
	Doctor d1;
	Doctor d2 = Doctor("Gigel", 35, "cardio", 7);

	cout << d2.getName() << " " << d2.getAge() << " " << d2.getSpeciality() << " " << d2.getNbshifts() << endl;

	d2.setName("gigel kook");
	d2.setAge(36);
	cout << d2.getName() << " " << d2.getAge() << " " << d2.getSpeciality() << " " << d2.getNbshifts() << endl;

	Doctor d3 = d2;
	Doctor d4(d2); //another way to copy constr
	cout << d3.getName() << " " << d3.getAge() << " " << d3.getSpeciality() << " " << d3.getNbshifts() << endl;
	cout << d4.getName() << " " << d4.getAge() << " " << d4.getSpeciality() << " " << d4.getNbshifts() << endl << endl << endl;


	//d1 este un obiect care apeleaza default constructorul . 
	//default constructorul nu initializeaza corect variabila speciality pentru ca ii da valoarea de nullptr , 
	//ceea ce inseamna ca niciodata nu vei putea sa afisezi un obiect care apeleaza default constructorul, gen d1
	cout << "nume neinitializat este: " << d1.getName() << endl << "varsta neinitializata este: " << d1.getAge() << endl << "specialitatea neinitializata este : " << d1.getSpeciality() << endl << "numarul de shifts neinitializat: " << d1.getNbshifts() << endl;

	d1 = d3;
	cout << endl << endl << d4.getName() << " " << d4.getAge() << " " << d4.getSpeciality() << " " << d4.getNbshifts() << endl;
}