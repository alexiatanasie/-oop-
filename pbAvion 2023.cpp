#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

enum tipAvion { AIRBUS, BOEING, DOUGLAS };
class Avion
{
    const int nrAvion;
    float pretBilet;
    char* destinatie;
    int nrLocuri;
    tipAvion type=AIRBUS;
public:

    static int nrTotalBileteVandute;

    // default constr
    Avion() :nrAvion(122),type(AIRBUS)
    {
        pretBilet = 0.0f;
        destinatie = nullptr;
        nrLocuri = 0;
        nrTotalBileteVandute++;
    }
    //constructors 

    Avion(int nrAvion, float pretBilet, const char* destinatie, int nrLocuri,tipAvion type) :nrAvion(nrAvion)/*, type(AIRBUS)*/
    {
        this->pretBilet = pretBilet;
        if (destinatie != nullptr)
        {
            this->destinatie = new char[strlen(destinatie) + 1];
            strcpy_s(this->destinatie, strlen(destinatie) + 1, destinatie);
        }
        else {
            this->destinatie = nullptr;
        }
        this->nrLocuri = nrLocuri;
        this->type = type;
        nrTotalBileteVandute++;
    }
    //copy constructor
    Avion(const Avion& a) :nrAvion(a.nrAvion)/*, type(AIRBUS)*/
    {
        this->pretBilet = a.pretBilet;
        if (a.destinatie != nullptr)
        {
            this->destinatie = new char[strlen(a.destinatie) + 1];
            strcpy_s(this->destinatie, strlen(a.destinatie) + 1, a.destinatie);
        }
        else {
            this->destinatie = nullptr;
        }
        this->type = a.type;
        this->nrLocuri = a.nrLocuri;
        nrTotalBileteVandute++;
    }
    Avion& operator=(const Avion& a) {
        if (this!=&a) {
            this->pretBilet = a.pretBilet;
            if (a.destinatie != nullptr)
            {
                this->destinatie = new char[strlen(a.destinatie) + 1];
                strcpy_s(this->destinatie, strlen(a.destinatie) + 1, a.destinatie);
            }
            else {
                this->destinatie = nullptr;
            }
            this->nrLocuri = a.nrLocuri;
        }

        return *this;
    }
    void adaugaLocuri(int y)
    {
        this->nrLocuri += y;
        
    }
        //setters and getters
    char* getDestinatie()
    {
       
        char* copy;
        copy = new char[strlen(this->destinatie) + 1];
        strcpy_s(copy, strlen(this->destinatie) + 1, this->destinatie);
        return copy;
        
    }
    void setDestinatie(const char* dest) {
        if (dest != nullptr) {
            if (this->destinatie != nullptr) {
                delete[] this->destinatie;
                this->destinatie = new char[strlen(dest) + 1];
                strcpy_s(this->destinatie, strlen(dest) + 1, dest);
            }
            else {
                this->destinatie = new char[strlen(dest) + 1];
                strcpy_s(this->destinatie, strlen(dest) + 1, dest);
            }
        }
    }
    static int getnrTotalBileteVandute() {
        return nrTotalBileteVandute;
    }
    static void setnrTotalBileteVandute(int NrAv)
    {
        Avion::nrTotalBileteVandute  =NrAv;
    }
    float getPretBilet()
    {
        return pretBilet;
    }
    int getNrAvion()
    {
        return nrAvion;
    }
   //nu are setter const int nrAvion
    void setNrLocuri(int nrLocuri)
    {
        this->nrLocuri=nrLocuri;
    }
    void setPret(float pretBilet)
    {
        if (pretBilet > 1) {
            this->pretBilet = pretBilet;
        }
    }
    int getNrLocuri()
    {
        return nrLocuri;
    }
    //destructor
    ~Avion()
    {
        if (destinatie != nullptr) {
            delete[]this->destinatie;
            this->destinatie = nullptr;
        }
        nrTotalBileteVandute--;
    }
    Avion operator+(int x) {
        Avion copy = *this;
        copy.pretBilet = this->pretBilet + x;
        return copy;
    }
   friend ostream& operator<<(ostream&, Avion a);
};
ostream& operator<<(ostream& out, const Avion a) {
    out << a.nrAvion << " " << a.type<<endl;
    out << a.pretBilet << "$";
    return out;
}
int Avion::nrTotalBileteVandute = 23;

int main()
{
    
    Avion a1(12273, 555, "Timisoara", 100,DOUGLAS);
    cout << a1.getNrAvion() << " " << a1.getPretBilet() << " " << a1.getDestinatie() << " " << a1.getNrLocuri() << endl;


    a1.setPret(25);
    cout << a1.getPretBilet() << endl;
    a1.setNrLocuri(200);
    cout << a1.getNrLocuri();
    cout << endl;
    a1.adaugaLocuri(15);
    cout << a1.getNrLocuri() << endl;

    Avion a2=a1;
    cout << a2.getNrAvion() << " " << a2.getPretBilet() << " " << a2.getDestinatie() << " " << a2.getNrLocuri() << endl;

    Avion a3 = a2 + 110;
    cout << a3.getPretBilet()<<endl;
    
    cout << a1; //ostream
}

