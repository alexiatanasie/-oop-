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
    Book(string ISBN,string title, string author, int totalPages, int chapters, int* pagesPerChapter) :ISBN(ISBN) {
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
    Book(const Book& b) : ISBN(b.ISBN){
        this->title = b.title;
        this->author = b.author;
        this->totalPages = b.totalPages;
        this->chapters = b.chapters;

        if (b.pagesPerChapter != nullptr) {
            this->pagesPerChapter = new int[chapters];
            for (int i = 0; i < this->chapters; i++) {
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
            for (int i = 0; i < this->chapters; i++) {
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
        cout << "book" << this->title << " " << this->author << " " << "has ISBN" << this->ISBN <<
            "totalpages: " << this->totalPages << " chapter: " << this->chapters << endl;
        if (this->pagesPerChapter != nullptr) {
            for (int i = 0; i < this->chapters; i++) {
                cout << "chapter" << i << "has " << this->pagesPerChapter[i] << endl;
            }
        }
    }
};
int Book::books = 0;
int main()
{
    int c[]{ 22,4,21,24,20 }, c1[]{ 20,11,14 };
   /* Book b1;
    Book b2("12345", "After", "Anna Todd", 567, 40, c);
    cout << b1.getISBN() << b1.getTitle() << b1.getAuthor() << " " << b1.getTotalPages() << " " <<
        b1.getChapters() << " " << b1.getPagesPerChapter()<<endl;
    cout << b2.getISBN() << b2.getTitle() << b2.getAuthor() << " " << b2.getTotalPages() << " " <<
        b2.getChapters() << " " << b2.getPagesPerChapter() << endl;*/
    Book bb;
    bb.showBook();
    Book b1("12345", "After", "Anna Todd", 567, 40, c);
    Book b2 = b1; //copy ctr
    b1.showBook();
    b2.showBook();

    Book b3("45454", "Tenerife", "Alexis", 789, 29,c1);
    b3.showBook();

    b2 = b3;
    b1.showBook();
    b2.showBook();
    b3.showBook();

}

