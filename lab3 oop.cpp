#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int sum(int a, int b)
{
	return a + b;
}

int dif(int a, int b)
{
	return a - b;
}

//Struct type
struct car {
	string model;
	int HP;
	string color;
};

//a function that will initialize a struct object
car initCar(string m, int h, string cl)
{
	car c;
	c.model = m;
	c.HP = h;
	c.color = cl;
	return c;
}

//Exercise from class
//Create a struct with an ENUM 
//Then a function to initialize it and one to show it
enum faculty { CSIE, MK, FABIZ };

struct student {
	string name;
	faculty f;
	int age;
};

student initStudent(string na, faculty fac, int a)
{
	student S;
	S.name = na;
	S.f = fac;
	S.age = a;
	return S;
}

void showStud(student s)
{
	cout << "Student " + s.name + " is " << s.age << " and is studying at " + s.f << '\n';
}


int main()
{
	//C string recap
	char sir[40]; 						//C string static allocated
	char* sir_dinamic = new char[10]; 	//C string dinamically allocated

	strlen(sir); 						//string lenght
	strcpy(sir, "sir de caractere"); 	//copies the C string from the right into the one in the left strcpy(destination,source)
	cout << sir << '\n';
	strcpy_s(sir, "sir de caractere safe"); //safe option
	cout << sir << '\n';
	strcpy(sir_dinamic, "dinamic");

	int cmp = strcmp(sir, sir_dinamic); //compares two strings
	//will return -1, 0 sau 1
	// -1 if the first character from the first string that is different has an asci value smaller that the one in the second string
	// 0 if they are equal
	// 1 if the first character from the first string that is different has an asci value bigger that the one in the second string
	cout << cmp << '\n';

	strcat(sir, sir_dinamic); 			//concatenates sir_dinamic at the end of sir
	cout << sir << '\n';

	delete[] sir_dinamic;

	//String type
	string sir1;
	string sir2 = "string";

	int dim = sir2.length(); 			//string length
	cout << '\n' << dim << '\n';
	cout << sir2 << '\n';
	sir1 = sir2; 						//copied the right string into the left string
	cout << sir1 << " " << sir2 << '\n';

	int comp = (sir1 == sir2) ? 1 : 0; 	//we compare the two strings
	cout << comp << '\n';
	if (sir1 == sir2)
	{
		cout << "Strings are equal - 1" << '\n';
	}
	else
	{
		cout << "Strings are different - 0" << '\n';
	}

	string sir3 = sir1 + sir2; 			//merge the two strings
	cout << sir3 << '\n';
	sir3 = sir3 + " plus ceva";
	cout << sir3 << "\n \n";


	//Pointer to function
	int (*pf)(int, int); 				//it's very important to not miss the ()
										//if we miss them, the program will believe that pf is the definition of a function that will return a value of type int*
	pf = sum;
	int rez_s = pf(7, 3);
	cout << rez_s << '\n';
	pf = dif;
	int rez_d = pf(12, 5);
	cout << rez_d << '\n';
	cout << '\n';

	//ENUM type (enumeration)
	//it is a user defined data type that will only let the user assigned one of the predefined values
	enum daysOfWeek { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
	//By default Monday will have the value 0, Tuesday 1 and so on
	//We can change the walues if we want 
	enum culors { Red = 5, Yellow = 7, Blue = 1 };

	daysOfWeek day;
	day = Wednesday;
	cout << "Today is " << day << '\n';
	//cout << "Today is " << (daysOfWeek)2 << '\n';

	switch (day)
	{
	case 0:
		cout << "Today is Monday";
		break;
	case 1:
		cout << "Today is Tuesay";
		break;
	case 2:
		cout << "Today is Wednesday";
		break;
	case 3:
		cout << "Today is Thursday";
		break;
	case 4:
		cout << "Today is Friday";
		break;
	case 5:
		cout << "Today is Saturday";
		break;
	case 6:
		cout << "Today is Sunday";
		break;
	}


	car c1;
	c1.model = "BMW";
	c1.HP = 200;
	c1.color = "Black";
	cout << "\nThe car is " << c1.model << " and has " << c1.HP << " HP and is color " << c1.color << '\n';

	//We can make the initialization process easier by using a function
	car c2 = initCar("A", 100, "Blue");
	cout << "\nThe car is " << c2.model << " and has " << c2.HP << " HP and is color " << c2.color << '\n';

	student stud = initStudent("Ionel", CSIE, 20);
	showStud(stud);
}