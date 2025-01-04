//copy constructor
//constant and static attributes
//static methods
//overloading operators (=, <, >, >=, ==, +, -, *, +=, ++, --, !, cast, [])

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>
using namespace std;

class Product {
private:
	char* name = nullptr;
	string description = "no description";
	float price = 0;

public:
	static int DESC_MIN_SIZE;
	static int NO_PRODUCTS;

private:
	//default ctr
	Product() {
		cout << endl << "def ctr";
		Product::NO_PRODUCTS += 1;
	}

public:
	Product(const char* name) {
		this->setName(name);
		Product:NO_PRODUCTS += 1;
	}
	Product(const char* name, string desc, float price) {
		this->setName(name);
		this->setDesc(desc);
		this->price = price;
		Product::NO_PRODUCTS += 1;
	}

	//destructor
	~Product() {
		delete[]this->name;
		this->name = nullptr;
		Product::NO_PRODUCTS -= 1;
	}

	//copy ctr
	Product(const Product& p) {
		this->price = p.price;
		this->setName(p.getName());
		this->setDesc(p.description);
		Product::NO_PRODUCTS += 1;
	}
	//overload op =
	void operator=(const Product& p) {
		if (this == &p) {
			return;
		}
		this->price = p.price;
		this->setName(p.getName());
		this->setDesc(p.description);
	}
	string getDescription() {
		return this->description;
	}
	void setDesc(string description) {
		if (description.empty() || description.size() < DESC_MIN_SIZE) {
			throw "invalid description";
		}
		this->description = description;
	}

	const char* getName() const { //Adaugă specificatorul const la metoda getName() pentru a indica faptul că aceasta nu modifică starea obiectului
		char* copy = new char[strlen(this->name) + 1];
		strcpy_s(copy, strlen(this->name) + 1, this->name);
		return copy;
	}
	void setName(const char* newName) {
		if (newName == nullptr || strlen(newName) < 3) {
			throw"invalid name";
		}
		int maxSize = strlen(newName) + 1;

		//avoid memory leak
		delete[]this->name;
		this->name = new char[maxSize];
		strcpy_s(this->name, maxSize, newName);
	}
	void printInfo() {
		if (this->name != nullptr) {
			cout << this->name;
		}
		else {
			cout << "no name";
		}
		cout << this->description << " " << this->price;
	}

	
};
int Product::DESC_MIN_SIZE = 3;
int Product::NO_PRODUCTS = 0;

//TEST DESTRUCTOR
void testDestructor() {
	Product p("test");
}
//USES COPY CTR
void doSmth(Product p){}
//SAU
Product createProduct() {
	Product t("test");
	return t;
}
int main() {
	Product laptop("lenovo");
	laptop.setName("new lenovo");

	//copy the laptop
	Product laptop2 = laptop;
	doSmth(laptop);

	laptop.printInfo();
	laptop2.printInfo();

	//TEST THE DESTR
	Product* p = new Product("test");
	delete p;

	string newDesc = "";
	if (newDesc.size() >= Product::DESC_MIN_SIZE) {
		laptop.setDesc(newDesc);
	}
	testDestructor();
	{
		Product test("test");
		int vb = 10;
	}

	cout << endl << "------------------";


	cout << endl << "Total products in memory " << Product::NO_PRODUCTS;
}