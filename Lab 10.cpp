#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

enum ApplianceType { KITCHEN, CARE, PORTABLE, LARGE };

//defining a personalized exception
class index_exception :public exception
{
public:
	index_exception() {

	}
	index_exception(const char* message) :exception(message) {

	}
};
class Appliance {
	const string ID;
	const ApplianceType applianceType;
	string name;
	string manufacturer;
	float price;
	int monthsInStore;
	float* monthlyPrice;

public:
	static int discountPercentage;

	//default ctr
	Appliance() :ID("12445AB"), applianceType(LARGE) {
		this->name = "";
		this->manufacturer = "";
		this->price = 0;
		this->monthsInStore = 0;
		this->monthlyPrice = nullptr;
	}
	Appliance(string ID, ApplianceType type, string name, string manufacturer, float price, int monthsInStore, float* monthlyPrice) :ID(ID), applianceType(type) {
		this->name = name;
		this->manufacturer = manufacturer;
		this->price = price;
		this->monthsInStore = monthsInStore;
		if (monthlyPrice != nullptr) {
			this->monthlyPrice = new float[this->monthsInStore];
			for (int i = 0; i < this->monthsInStore; i++) {
				this->monthlyPrice[i] = monthlyPrice[i];
			}

		}
		else {
			this->monthlyPrice = nullptr;
		}
	}

	Appliance(const Appliance& a) :ID(a.ID), applianceType(a.applianceType) {
		this->name = a.name;
		this->manufacturer = a.manufacturer;
		this->price = a.price;
		this->monthsInStore = a.monthsInStore;
		if (a.monthlyPrice != nullptr)
		{
			this->monthlyPrice = new float[this->monthsInStore];
			for (int i = 0; i < this->monthsInStore; i++)
			{
				this->monthlyPrice[i] = a.monthlyPrice[i];
			}
		}
		else
		{
			this->monthlyPrice = nullptr;
		}
	}
	~Appliance() {
		if (this->monthlyPrice != nullptr) {
			delete[]this->monthlyPrice;
		}
	}
	//getters adn setters
	string getId() {
		return this->ID;
	}
	string getName()
	{
		return this->name;
	}

	string getManufacturer()
	{
		return this->manufacturer;
	}

	float getPrice()
	{
		return this->price;
	}

	int getMonthsInStore()
	{
		return this->monthsInStore;
	}
	float* getMonthlyInPrice() {
		float* copy;
		if (this->monthlyPrice != nullptr) {
			copy= new float[this->monthsInStore];
			for (int i = 0; i < this->monthsInStore; i++) {
				copy[i] = this->monthlyPrice[i];
			}
		}
		else {
			copy = nullptr;
		}
		return copy;
	}
	static int getDiscountPercentage() {
		return discountPercentage;
	}

	//setters
	void setName(string name) {
		this->name = name;
	}
	void setManufacturer(string manufacturer)
	{
		this->manufacturer = manufacturer;
	}

	void setPrice(float price)
	{
		if (price > 0)
		{
			this->price = price;
		}
	}

	void setMonthsInStore(int months)
	{
		this->monthsInStore = months;
	}
	void setMonthlyInPrice(int months, float* monthlyPrice) {
		if (monthlyPrice != nullptr) {
			delete[]this->monthlyPrice;

		}
		this->monthsInStore = months;
		if (monthlyPrice != nullptr) {
			this->monthlyPrice = new float[this->monthsInStore];
			for (int i = 0; i < this->monthsInStore; i++) {
				this->monthlyPrice[i] = monthlyPrice[i];
			}

		}
		else {
			this->monthlyPrice = nullptr;
		}
	}

	void setSalePercentage(int discoutPercentage) {
		Appliance::discountPercentage = discoutPercentage;
	}

	//operator overloading=
	Appliance& operator=(const Appliance& a) {
		if (this != &a) {
			this->name = a.name;
			this->manufacturer = a.manufacturer;
			this->price = a.price;
			this->monthsInStore = a.monthsInStore;
			if (this->monthlyPrice != nullptr)
			{
				delete[] this->monthlyPrice;
			}

			if (a.monthlyPrice != nullptr)
			{
				this->monthlyPrice = new float[this->monthsInStore];
				for (int i = 0; i < this->monthsInStore; i++)
				{
					this->monthlyPrice[i] = a.monthlyPrice[i];
				}
			}
			else
			{
				this->monthlyPrice = nullptr;
			}
		}
		return *this;
	}

	//check if the price is>200
	bool operator!() {
		return this->price > 200;
	}
	//pre-increment
	Appliance& operator++() {
		this->price++;
		return *this;
	}
	//post-increment
	Appliance operator++(int i) {
		Appliance copy = *this;
		this->price++;
		return copy;
	}
	friend ostream& operator<<(ostream&, Appliance);
	friend istream& operator>>(istream&, Appliance&);

	friend ofstream& operator<<(ofstream&, Appliance);
	friend ifstream& operator>>(ifstream&, Appliance&);

	void serialize() {
		//1. open the file
		ofstream f("appliances.bin", ios::binary);

		//2. write in the file
		//name 
		//first we need to write length of the name in order to know how much we need to write and read afterwards

		unsigned length = name.length();
		//we convert the string in a char array
		const char* n = name.c_str();
		//we write the lenght
		f.write((char*)&length, sizeof(length));

		//write the name
		f.write(n, length + 1);

		//price
		//we write the price , first we do a cast for the number to char
		f.write((char*)&price, sizeof(price));

		//3. close the file
		f.close();
	}
	void deserialize() {
		//1. open the file
		ifstream f("electrocasnic.bin", ios::binary);

		//2 read the file

		//name
		unsigned length = 0;
		//read the name lenght
		f.read((char*)&length, sizeof(length));

		//allocate memory to a local variable so we can read the name through it

		char* n = new char[length + 1];

		//read the name
		f.read(n, length + 1);

		//save the name in the string attribute
		name = n;
		//free the memory as we no longer need the local array n
		delete[]n;

		//price
		//read the price
		f.read((char*)&price, sizeof(price));

		//3 close the file
		f.close();
	}

};
ostream& operator<<(ostream& out, Appliance a) {
	out << a.ID << " " << a.name << " " << a.manufacturer << '\n';
	out << "price: " << a.price << "$";
	return out;
}
istream& operator>>(istream& in, Appliance& a) {
	cout << "change the price for the appliance with id" << a.ID << ":";
	float newPrice;
	in >> newPrice;
	a.setPrice(newPrice);
	return in;
}
ofstream& operator<<(ofstream& fout, Appliance a) {
	fout << a.name << endl << a.price;
	return fout;
}
ifstream& operator>>(ifstream& fin, Appliance& a) {
	getline(fin, a.name);
	fin >> a.price;
	return fin;
}
int Appliance::discountPercentage = 0;

//INHERITANCE
//public inheritance
class WashingMachine :public Appliance {
private:
	int capacity;
	int rotations;
	bool hasDryer;
	char* model;

public:
	WashingMachine() :Appliance() {
		capacity = 0;
		rotations = 0;
		hasDryer = 0;
		model = nullptr;
	}
	WashingMachine(string ID, ApplianceType type, string name, string manufacturer, float price, int months, float* monthlyPrice, int capacity, int rotations, bool isDrying, const char* model) :Appliance(ID, type, name, manufacturer, price, months, monthlyPrice)
	{
		this->capacity = capacity;
		this->rotations = rotations;
		this->hasDryer = hasDryer;
		if (model != nullptr) {
			this->model = new char[strlen(model) + 1];
			strcpy_s(this->model, strlen(model) + 1, model);

		}
		else {
			this->model = nullptr;

		}
	}
	//copy ctr
	WashingMachine(const WashingMachine& wm) :Appliance(wm) {
		this->capacity = wm.capacity;
		this->rotations = wm.rotations;
		this->hasDryer = wm.hasDryer;
		if (wm.model != nullptr) {
			this->model = new char[strlen(wm.model) + 1];
			strcpy_s(this->model, strlen(wm.model) + 1, wm.model);

		}
		else {
			this->model = nullptr;

		}

	}
	~WashingMachine() {
		if (this->model != nullptr) {
			delete[]this->model;
		}
	}

	//operator =
	WashingMachine& operator=(const WashingMachine& wm) {
		if (this != &wm) {
			//call the operator= from the base class
			Appliance::operator=(wm);
			this->capacity = wm.capacity;
			this->rotations = wm.rotations;
			this->hasDryer = wm.hasDryer;
			if (this->model != nullptr)
			{
				delete[] this->model;
			}
			if (wm.model != nullptr)
			{
				this->model = new char[strlen(wm.model) + 1];
				strcpy_s(this->model, strlen(wm.model) + 1, wm.model);
			}
			else
			{
				this->model = nullptr;
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream&, WashingMachine);
	friend istream& operator>>(istream&, WashingMachine&);

};
ostream& operator<<(ostream& out, WashingMachine wm) {
	//call the operator from the base class
	out << (Appliance)wm << '\n';
	if (wm.hasDryer) {
		out << "the washing machine comes with a dryer" << '\n';

	}
	else {
		out << "the washing machine doesn't comes with a dryer" << '\n';
	}
	return out;
}
istream& operator>>(istream& in, WashingMachine& wm) {
	//call the operator from the base class
	in >> (Appliance&)wm;
	cout << "does the machine have a dryer?(1 for YES.0 for NO";
	in >> wm.hasDryer;
	return in;
}
int main() {
	float p1[]{ 120,190,124,210,100 }, p2[]{ 600,550,607 }, p3[]{ 1200,1900 };
	Appliance a1("ABH1561", KITCHEN, "FRIDGE", "LG", 550, 3, p2);
	Appliance a2("NN1W292UB", KITCHEN, "Toaster", "Philips", 210, 5, p1);
	Appliance a3 = a1;
	a3 = a2;
	cout << a1 << endl << a3 << endl;
	cin >> a3;
	cout << endl << a3;

	WashingMachine wm1("BUHB2U", LARGE, "Washing machine", "Bosch", 800, 0, nullptr, 9, 1800, false, "Series 989");
	WashingMachine wm2("BE373NRD", LARGE, "Washing machine with dryer", "Samsung", 1900, 2, p3, 6, 1800, true, "Series 99");

	cout << wm1 << endl;
	cout << wm2 << endl;
	WashingMachine wm3 = wm1;
	cout << wm3 << endl;
	wm3 = wm2;
	cout << wm3 << endl;
	cin >> wm3;
	cout << wm3 << endl;


	//UPCASTING = the conversion from the derived class to the base class
	//it works implicitly
	a1 = wm1;

	//DOWNCASTING doesnt work (because not all appliances are washing machines)
	//wm1=a1;

	//EXCEPTIONS
	//in some case we can throw exceptions
	//throwing exceptions is equivalent to returning a value from a function
	//if the exceptions are not handled, they can stop the normal execution of the program
	try{
		cout << a2;
	}
	catch (index_exception e) {
		cout << e.what();
	}
	catch (exception e) {
		cout << e.what();
	}
	catch (...)// will catch anything
	{
		cout << "we caught the exception";
			
	}

	//we can have multiple catch block in a single try catch structure
	//we can even throw an int or string, not just exceptions
	//personalized exceptions can be defined by deriving from the class exception
	//if we want to specify the error message, then we can use a constructor with a char parameter
	//exceptions can slow down the program and create memory leaks

	a1.serialize();
	a2.deserialize();

	//1 open the file
	ofstream f("file.txt");

	//2. write in the file
	f << a1;

	//3.close the file
	f.close();

	//1. open the file
	ifstream f2("file.txt");

	//2 read from the file
	f2 >> a1;

	//3 close the file
	f2.close();
}