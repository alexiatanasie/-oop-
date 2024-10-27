#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//through value 
void sum(int x, int y) {
	x += y;
}
void sumv(int* x, int y) {
	*x = *x + y;
}
void sumr(int& x, int y) {
	x = x + y;
}

void updateVar(int* k) {
	*k = *k + 10;
}

int main()
{
	
	cout << "an int will occupy" << sizeof(int) << "bytes" << '\n';
	cout << "an char will occupy" << sizeof(char) << "bytes" << '\n';
	cout << "an long will occupy" << sizeof(long) << "bytes" << '\n';

	//Pointer operations
	//	Defining
	//	Initialization
	//	Dereferentiation
	//	Increment/decrement
	//	Substraction of two pointers

	int* p = nullptr;
	int x = 5;

	int var = 2, var2 = 4;
	//cout << "the pointer px" << px << '/n';
	//constant pointer
	int* const pConst = &var;
	//pConst = &var2;

	//pointer to a constant mempory zone
	const int* c = &var2;
	//*c = 8;

	//constant pointer to a constant memory zone
	const int* const cp = &var;

	//complete the following fct to achieve the below
	//use the address of the value
	//will increment the value with 10


	int nn=2;
	cout << nn<<endl;
	updateVar(&nn);
	cout << nn;
	
	int v[5];
	v[0] = 1;
	v[1] = 7;

	int* vect = new int[5];
	vect[0] = 0;
	cout << "vector" << vect << endl;
	cout << "vector" << *vect << endl;


	for (int i = 0; i < 5; i++)
	{
		vect[i] = i;

	}

	//the adrress of the first element or the value? of the first element
	for (int i = 0; i < 5; i++)
	{
		cout<<vect[i] << endl;

	}
	cout << *(v + 1) << endl;

}


