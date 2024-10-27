#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;
struct Person {
	string name;
	int age;
};
Person init(string name, int age)
{
	Person p;
	p.name = name;
	p.age = age;
	return p;
}
//create a class 
//it has one attribute that is an enum type
//ctr,default ctr, ctr with param
enum Animals{tigers,zebras,elephants};
class ZOO{
private:
	Animals animals;
public: 
	int age;
	string name;

	
	//default ctr
	ZOO() {
		this->age = 0;
		this->name = "default name";
		this->animals = tigers;
	}
	//ctr with param
	ZOO(int age, string name) {
		this->age=age;
		this->name=name;
		this->animals = zebras;

	}
	void listAnimals() {
		cout << "age of the animal:" << this->age << endl;
		cout << "name of the animal " << this->name << endl;
		cout << this->animals;
	}
};

class SoftwareCompany
{
public:
	int noEmployees;

	string name;
	string address;
//private:	
//	int noEmployees;

	void listCompanyDetails() {
		cout << "company:" << this->name << '\n';
		cout << "nb employees: " << this->noEmployees<<'\n';

	}
	//default ctr
	SoftwareCompany() {
		name = "default name";
		noEmployees = 3;
		address = "abc";
		
	}
	//ctr with param
	SoftwareCompany(string name, int nb, string address) {
		this->name = name;
		noEmployees = nb;
		this->address = address;
		
	}
	//ctr with one par
	SoftwareCompany(string name) {
		this->name = name;
		noEmployees = 10;
		this->address = "piata romana";

	}
	
};
int main()
{
	//Person p;
	//p.name = "gig";
	//cout << "the person i created is called " << p.name << " and has " << p.age << " years old ";
	//Person p1 = init("gig", 24);
	//cout << " the person i created is called " << p1.name << " and has " << p1.age << " years old ";

	//SoftwareCompany company1;
	//company1.name = "Soft INC";
	////company1.noEmployees = 33;
	//company1.listCompanyDetails();
	//cout << endl;

	//SoftwareCompany company2 = SoftwareCompany();
	//company2.listCompanyDetails();

	//cout << endl;
	//SoftwareCompany company3 = SoftwareCompany("development c",155,"calea dorobanti 109");
	//company3.listCompanyDetails();
	//cout << endl;

	//SoftwareCompany company4 = SoftwareCompany("dev soft");
	//company4.listCompanyDetails();

	ZOO z;
	z.listAnimals();

	ZOO z1(11, "ann");
	z1.listAnimals();
}

