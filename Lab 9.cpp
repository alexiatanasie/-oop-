#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

enum ApplianceType{KITCHEN,CARE,PORTABLE,LARGE};

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
			copy - new float[this->monthsInStore];
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
int Appliance::discountPercentage = 0;

//INHERITANCE
//it's a way to create new classes that share the same attributes as an existing class
//it helps us write less code

//types of inheritance
//public,protected,private

//PUBLIC->public members in the base class remain public in the derived class
//		->protected members in the base class remain protected in the derived class
			//-> private members in the base class remain private in the derived class(we only have access to them via getters and setters)
//PRIVATE->public members in the base class become private in the derived class
		//->protected members in the base class become private in the derived class
        //->private members remain private
//PROTECTED->public members in the base class become protected in the derived class
		//->protected members in the base class remain protected in the derived class
		//->private members remain private
//this mode maintains access to the public area for derived class

//publicizing
//we explicitly make members public
	//the derived class has its own constructors called base constructors
	//these base ctrs will initialize the inherited attributes
//order of calls:first the constructor of the base class and then the one derived

//the order of destructors is the reverse, first destrcutor of the derived class and then the one of the base class


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
	WashingMachine(string ID,ApplianceType type,string name, string manufacturer,float price,int months,float* monthlyPrice,int capacity,int rotations,bool isDrying,const char* model) :Appliance(ID,type,name,manufacturer,price,months,monthlyPrice)
		{
		this->capacity = capacity;
		this->rotations = rotations;
		this->hasDryer = hasDryer;
		if (model != nullptr) {
			this->model = new char[strlen(model) + 1];
			strcpy_s(this->model, strlen(model) + 1,model);

		}
		else {
			this->model = nullptr;

		}
	}
	//copy ctr
	WashingMachine(const WashingMachine& wm):Appliance(wm) {
		this->capacity = wm.capacity;
		this->rotations = wm.rotations;
		this->hasDryer = wm.hasDryer;
		if (wm.model != nullptr) {
			this->model = new char[strlen(wm.model) + 1];
			strcpy_s(this->model, strlen(wm.model) + 1,wm.model);

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
}
