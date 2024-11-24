#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;
//SEMINARS 7 & 8

//OVERLOADING - the first form of polymorphism
//we have at least 2 functions with the same name, but they differ in the number and/or type of parameters
            //we can only overload existing operators
            //we CANNOT overload the operators . *. ::(scope resolution operator) ?:(ternary operator) sizeof()
            // we must preserve the commutativity, cardinality, associativity of operators when overloading them

//ways to overload operators:
//through a member function - the first operand is of the class type
//through a global function -especially when the first operand is not of the class type
        //in this case, if we need to access private members, we use friend functions or accessor methods

//UNARY OPERATORS ex: ! ++ --
  //recommended to overload through member ftc

//BINARY OPERATORS ex: + -
        //they can be overloaded through either member or global fct
        //they are typically overloaded through global ftc when the first operand is not of the current class type
        //if overloaded through member fct, they will have a single parameter; otherwise, they will have 2

class Book {
    const string ISBN;
    string title;
    string author;
    int totalPages;
    int chapters;
    int* pagesPerChapter;

    static int books;

public:
    Book() :ISBN("12345") {
        title = "Anna Frank";
        author = "";
        totalPages = 0;
        chapters = 0;
        pagesPerChapter = nullptr;
        books++;
    }
    Book(string ISBN, string title, string author, int totalPages, int chapters, int* pagesPerChapter) :ISBN(ISBN) {
        this->title = title;
        this->author = author;
        this->totalPages = totalPages;
        this->chapters = chapters;

        if (pagesPerChapter != nullptr) {
            this->pagesPerChapter = new int[chapters];
            for (int i = 0; i < chapters; i++) {
                this->pagesPerChapter[i] = pagesPerChapter[i];
            }
        }
        else {
            this->pagesPerChapter = nullptr;
        }
        books++;
    }
    Book(const Book& b) : ISBN(b.ISBN) {
        this->title = b.title;
        this->author = b.author;
        this->totalPages = b.totalPages;
        this->chapters = b.chapters;

        if (b.pagesPerChapter != nullptr && b.chapters > 0) {
            this->pagesPerChapter = new int[b.chapters];
            for (int i = 0; i < b.chapters; i++) {
                this->pagesPerChapter[i] = b.pagesPerChapter[i];
            }
        }
        else {
            this->pagesPerChapter = nullptr;
        }
        books++;
    }
    ~Book() {
        if (pagesPerChapter != nullptr) {
            delete[]this->pagesPerChapter;
            this->pagesPerChapter = nullptr;
        }
    }
    static void doSomething() {
        cout << "did smth at class level\n";
    }
    //accessor methods
    //getters
    string getISBN()
    {
        return this->ISBN;
    }
    string getTitle() {
        return this->title;
    }
    string getAuthor() {
        return this->author;
    }
    int getChapters() {
        return this->chapters;
    }
    int getTotalPages() {
        return this->totalPages;
    }
    int* getPagesPerChapter() {
        int* copy;
        if (pagesPerChapter != nullptr) {
            copy = new int[this->chapters];
            for (int i = 0; i < this->chapters; i++) {
                copy[i] = this->pagesPerChapter[i];
            }
        }
        else {
            copy = nullptr;
        }
        return copy;
    }
    static int getBooks() {
        return books;
    }
    //setters
    static void setBooks(int nbBooks) {
        Book::books = nbBooks;
    }
    void setTitle(string title) {
        this->title = title;
    }
    void setAuthor(string author) {
        this->author = author;
    }
    void setTotalPages(int TotalPages) {
        this->totalPages = TotalPages;
    }
    void setChapters(int chap) {
        this->chapters = chap;
    }
    void setPagesPerChapter(int* pagesPerChapter) {
        if (this->pagesPerChapter != nullptr) {
            delete[]this->pagesPerChapter;
        }
        if (pagesPerChapter != nullptr) {
            this->pagesPerChapter = new int[this->chapters];
            for (int i = 0; i < this->chapters; i++) {
                this->pagesPerChapter[i] = pagesPerChapter[i];
            }
        }
        else {
            this->pagesPerChapter = nullptr;
        }
    }
    Book& operator=(const Book& b) {
                if(this!=&a){
        this->title = b.title;
        this->author = b.author;
        this->totalPages = b.totalPages;
        this->chapters = b.chapters;

        if (b.pagesPerChapter != nullptr) {
            this->pagesPerChapter = new int[b.chapters];
            for (int i = 0; i < b.chapters; i++) {
                this->pagesPerChapter[i] = b.pagesPerChapter[i];
            }
        }
        else {
            this->pagesPerChapter = nullptr;
        }
                }
        return *this;
    }
    void showBook() {
        cout << "book" << this->title << " " << this->author << " " << "has ISBN" << this->ISBN
            << " totalpages: " << this->totalPages << " chapters: " << this->chapters << endl;
        if (this->pagesPerChapter != nullptr) {
            for (int i = 0; i < this->chapters; i++) {
                cout << "chapter" << i << " has " << this->pagesPerChapter[i] << endl;
            }
        }
        else {
            cout << "No pages per chapter data available." << endl;
        }
    }

    //Unary operators: ++ -- !  ->recommended to overload with a member function
    //Binary operators: = + - <
    // we can do this through member function or global function

    //Cannot be overloaded: . *. :: ?: sizeof()

    //overloading operator! ( op unar de negatie)
    bool operator!() {
        /*   if (this->totalPages > 200) {
               return true;
           }
           else {
               return false; }*/
        return this->totalPages > 200;
    }

    //x++ post incrementation
    Book operator++(int i) {
        Book copy = *this;
        this->totalPages++;
        return copy;
    }

    //++x pre-incrementation
    Book& operator++() {
        this->totalPages++;
        return *this;
    }

    //OVERLOADING OPERATOR+
    //b1+b2
    //sum the number of total pages

    //MEMBER FUNCTION
   /* Book operator+(Book b) {
        Book copy = *this;
        copy.totalPages = this->totalPages + b.totalPages;
        return copy;
    }*/

    //b1.totalPages+x
    Book operator+(int x) {
        Book copy = *this;
        this->totalPages += x;
        return copy;
    }

    //global/ friend fct
    friend Book operator+(Book, Book);
    //x+b1
    friend Book operator+(int, Book);

    //OVERLOADING []
    //only through MEMBER FCT
    //getter or getter +setter
    //give me the nr of pages from a certain chapter

    int& operator[](int index) {
        if (this->pagesPerChapter != nullptr && index >= 0 && index < chapters) {
            return this->pagesPerChapter[index];
        }
    }

    //operator cast
    operator int() {
        return this->totalPages;
    }

    //function operator
    //only through member fct
    //return a string message
    //message tells us if the object has a different author than the one received through parameter and if the total nr of pages is > that the one received

    string operator()(string a, int nbp) {
        if (this->author == a) {
            if (this->totalPages > nbp) {
                return "same author, greater nr of pages";
            }
            else {
                return "same author, lower nr of pages";
            }
        }
        else {
            if (this->totalPages > nbp) {
                return "different author, greater nr of pages";
            }
            else {
                return "different author, lower nr of pages";
            }
        }

    }

    //OVERLOADING of readinf=g adn writing op
    //>>(cin-reading istream) - << (cout-writing=ostream)
    //global friend fct
    //we use a reference to use the op in cascade

    //ostream <<
    friend ostream& operator<<(ostream&, Book);

    //istream>>
    friend istream& operator>>(istream&, Book&);
};
Book operator+(int x, Book b)
{
    b.totalPages += x;

    return b;
}
Book operator+(Book b1, Book b2) {
    b1.totalPages += b2.totalPages;
    return b1;

}
ostream& operator<<(ostream& out, Book b) {
    out << b.getTitle() << " " << b.getAuthor();
    return out;
}
istream& operator>>(istream& in, Book& b) {
    cout << "add a new title";
    in >> b.title;
    return in;
}
int Book::books = 0;
int main()
{
    int c[]{ 22,4,21,24,20 }, c1[]{ 20,11,14 };
    /* Book b1;
     Book b2("12345", "After", "Anna Todd", 567, 40, c);
     cout << b1.getISBN() << b1.getTitle() << b1.getAuthor() << " " << b1.getTotalPages() << " " <<
         b1.getChapters() << " " << b1.getPacgedPerChapter()<<endl;
     cout << b2.getISBN() << b2.getTitle() << b2.getAuthor() << " " << b2.getTotalPages() << " " <<
         b2.getChapters() << " " << b2.getPacgedPerChapter() << endl;*/
    Book bb;
    bb.showBook();
    Book b1("12345", "After", "Anna Todd", 567, 5, c);
    Book b2 = b1; //copy ctr
    b1.showBook();
    b2.showBook();

    Book b3("45454", "Tenerife", "Alexis", 789, 3, c1);
    b3.showBook();

    b2 = b3;
    b1.showBook();
    b2.showBook();
    b3.showBook();

    if (!b3 == 1) {
        cout << "greater than 200: ";
    }
    else {
        cout << "lower than 200";
    }
    cout << endl;

    Book b4 = ++b2;
    cout << b4.getTotalPages() << " " << b2.getTotalPages() << endl;

    Book b5 = b2++;
    cout << b5.getTotalPages() << " " << b2.getTotalPages() << endl;

    b3 = b2++;
    cout << b3.getTotalPages() << " " << b2.getTotalPages() << endl;


    Book b6 = b1 + b5;
    cout << b1.getTotalPages() << '\n' << b5.getTotalPages() << endl;
    cout << b6.getTotalPages(); //it is also the same if I use member ftc

    Book b7 = b5 + 10;
    cout << b7.getTotalPages() << '\n';
    cout << b5.getTotalPages() << '\n';

    b7 = 5 + b7;
    cout << b7.getTotalPages() << '\n';

    //index op
    cout << b1[1] << endl;
    b1[1] = 200;
    cout << b1[1] << endl;

    //explicit cast op
    int pages = (int)b7;
    cout << pages << endl;

    //op()
    string result = b7("Ion", 390);
    cout << result << endl;

    //op << >> 
    cout << b7;
    cin >> b7;
    cout << b7;
}

