#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;

//type of constructors
//default constructor(without parameters)
//constructor with parameters
//copy ctr ->autocalled when we pass an object as a paramater in a function
//they will be public in 99% of the cases
//they need to be visible outside the class because they construct objects


class Book {
private:
	char* title;
	int nrPages;
	double price;
public:
	static int nrOfBookSold; //shared by all objects
	//static attributes are at class level
	//non-static attributes are at object kevel

	//default ctr
	Book() {
		title = nullptr;
		nrPages = 0;
		price = 0;
		nrOfBookSold++;
	}

	//ctr with all param
	Book(const char* title, int nrPages, double price) {


		this->title = new char[strlen(title) + 1]; //aloca memorie pe heap pentru a stoca titlul, creand un nou sir de caractere de lungime strlen(title) + 1
		strcpy_s(this->title, strlen(title) + 1, title);
		this->nrPages = nrPages;
		this->price = price;
		nrOfBookSold++;
	}

	//un ctr care sa fie implicit(default ctr), dar foloseste si param
	/*Book(const char* _title = "", int _nbPages = 0, double _price = 0) {
		this->title = new char[strlen(_title) + 1];
		strcpy_s(this->title, strlen(_title) + 1, _title);
		nrPages = _nbPages;
		price = _price;

	}*/

	//copy ctr 
	//use it to copy objects
	//automatically used when we send an object as a parameter in a fucntion through value
	//or when the function returns an object through value

	Book(const Book& book) //we need reference because we cannot call the copy ctr
		//when we are creating it
	{
		if (book.title != nullptr) {
			title = new char[strlen(book.title) + 1];
			strcpy_s(title, strlen(book.title) + 1, book.title);
			//copiaza sirul book.title in title
			//se asigura ca title are suficient spatiu pt a evita erori de copiere si pt a include caract de terminare \0:strlen(book.title) + 1

		}
		else {
			this->title = nullptr;
		}
		nrPages = book.nrPages;
		price = book.price;
	}

	//destructor
	//it is the opposite of the ctr
	//it is pnly one
	~Book() {
		if (title != nullptr) {
			delete[]this->title;
		}
	}

	//access functions
	//getters and setters
	//they allow us to have controled access over the attributes
	//they are defined in public zone so they can be accessed in main

	//getters
	int getNrPages() {
		return nrPages;
	}
	double getPrice() {
		return price;
	}
	//setter
	void setPrice(double price) {
		if (price > 0) {
			this->price = price;
		}
	}

};
void centraliseBook(Book book) { //copy ctr call

}
//initialize static attributes
//we use resolution operator
int Book::nrOfBookSold = 0;
int main()
{
	Book b1; //default ctr is called
	Book b2 = Book("After", 406, 70);
	Book b3 = b2; //copy ctr is called
	cout << "price:" << " " << b2.getPrice() << " " << "nr of pages: " << b2.getNrPages() << endl;
	b2.setPrice(-66);
	cout << "price:" << " " << b2.getPrice() << " " << "nr of pages: " << b2.getNrPages() << endl;
	b2.setPrice(79);
	cout << "price:" << " " << b2.getPrice() << " " << "nr of pages: " << b2.getNrPages() << endl;

	//Book* bp = new Book(); //pointer that keeps the address of a new object created in heap with the help of the default constructor
	//cout << "Price:" << bp->getPrice() << " " << "nr of pages:" << bp->getNrPages() << endl;
	//delete bp;
	//bp = nullptr;

}
