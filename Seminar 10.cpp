#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

enum typeOfAppliance{Kitchen,Personal,Travel};

class Appliance {
	const string ID;
	string name;
	string manufacturer;
	float price;
	int monthsInStore;
	float* pricePerMonth;
	typeOfAppliance applianceType;
	

	public:
		static int discountPercentage;
	Appliance() :ID("1234567"){
		this->name = "def";
		this->manufacturer = "def";
		this->price = 0;
		this->monthsInStore = 0;
		this->pricePerMonth = nullptr;
		this->applianceType = Kitchen;
		//this->applianceType = (typeOfAppliance); sau asa

	}
	Appliance(string ID, string name, string man, float price, int mis, float* ppm, typeOfAppliance at) : ID(ID){
		this->name = name;
		this->manufacturer = man;
		this->price = price;
		this->monthsInStore = mis;
		if (ppm != nullptr) {
			this->pricePerMonth = new float[this->monthsInStore];
			for (int i = 0; i < this->monthsInStore; i++) {
				this->pricePerMonth[i] = ppm[i];
			}
		}
		else {
			this->pricePerMonth = nullptr;
		}
		this->applianceType = at;
	}
	//copy ctr
	Appliance(const Appliance& a) : ID(a.ID){
		this->name = a.name;
		this->manufacturer = a.manufacturer;
		this->price = a.price;
		this->monthsInStore = a.monthsInStore;
		this->pricePerMonth = nullptr;
		if (a.pricePerMonth != nullptr) {
			this->pricePerMonth = new float[this->monthsInStore];
			for (int i = 0; i < this->monthsInStore; i++) {
				this->pricePerMonth[i] = a.pricePerMonth[i];
			}
		}
		this->applianceType =a.applianceType;

	}
	~Appliance() {
		if (this->pricePerMonth != nullptr) {
			delete[] this->pricePerMonth;
			this->pricePerMonth = nullptr;

		}
	}
	Appliance operator=(const Appliance& a) {
		if (this != &a) {
			this->name = a.name;
			this->manufacturer = a.manufacturer;
			this->price = a.price;
			this->monthsInStore = a.monthsInStore;
			this->pricePerMonth = nullptr;
			if (a.pricePerMonth != nullptr) {
				this->pricePerMonth = new float[this->monthsInStore];
				for (int i = 0; i < this->monthsInStore; i++) {
					this->pricePerMonth[i] = a.pricePerMonth[i];
				}
			}
			this->applianceType = a.applianceType;
		}
		return *this;
		
		
	}
	friend istream& operator>>(istream&, Appliance&);
	friend ostream& operator<<(ostream&, Appliance);
};

int Appliance::discountPercentage = 0;
//read a new price
istream& operator >>(istream& in, Appliance& a) {
	cout << "write the new price for the appliance with id" << a.ID << ":";
	float newPrice;
	in >> newPrice;
	//a.setPrice(newPrice); daca am fi facut setter-ul
	if (newPrice > 0) a.price = newPrice;
	return in;

}
ostream& operator<<(ostream& out, Appliance a) {
	out << a.ID<<"->"<<a.name << "-" << a.manufacturer << '\n';
	out << "a new price:" << a.price << '\n';
	return out;
}
//inheritance
class WashingMachine :public Appliance {
private:
	int capacity;
	int nrOfRotations;
	bool hasDryer;
public:
	WashingMachine() : Appliance() {
		this->capacity = 0;
		this->nrOfRotations = 0;
		this->hasDryer = 0;
	}
	WashingMachine(string ID, string name, string man, float price, int mis, float* ppm, typeOfAppliance at, int capacity
		, int nbRotations, int hasDryer) :Appliance(ID, name, man, price, mis, ppm, at) {
		this->capacity = capacity;
		this->nrOfRotations = nbRotations;
		this->hasDryer = hasDryer;
	}
};
int main() {

	float p1[]{ 120,110,200,170 }, p2[]{ 1000,1250,1110 };
	Appliance a1("123FGG", "Fridge", "LG", 1110, 3, p2, Kitchen);
	Appliance a2("F2DDR2", "Toaster", "Philips", 185, 4, p1, Kitchen);

	Appliance a3 = a2;
	a3 = a1;

	cout << a1;
	cout << a2;
	cout << a3;

	cin >> a1;
	cout << a1;

	WashingMachine wm1("1234ff", "Washing", "Samsung",330, 4, p1, Kitchen, 9, 1400, true);
	

	return 0;

}
