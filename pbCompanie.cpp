#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;
enum institutie{ MULTINATIONALA, STARTUP,IMM};
class Companie {
    const institutie type;
    int nrIdentificare;
    string denumire;
    int nrDepartamente;
    float* bugetDepartament;

public:
    static int nrInstitutiiInregistrate;
   
    //ctr with 2 param
    Companie(institutie type, int nrIdentificare) :type(type) {
        this->nrIdentificare = nrIdentificare;
        this->denumire = "";
        this->nrDepartamente = 0;
        this->bugetDepartament = nullptr;
        nrInstitutiiInregistrate++;
    }
    //ctr with all param
    Companie(institutie type, int nrIdentificare, string denumire, int nrDepartamente, float* bugetDepartament) :type(type) {
        
        this->nrIdentificare = nrIdentificare;
        this->denumire = denumire;
        this->nrDepartamente = nrDepartamente;
        if (bugetDepartament != nullptr) {
            this->bugetDepartament = new float[nrDepartamente];
            for (int i = 0; i < nrDepartamente; i++) {
                this->bugetDepartament[i] = bugetDepartament[i];
            }
        }
        else {
            this->bugetDepartament = nullptr;
        }
        nrInstitutiiInregistrate++;
    }
    //copy ctr
    Companie(const Companie& c) :type(c.type) {
        this->nrIdentificare = c.nrIdentificare;
        this->denumire = c.denumire;
        this->nrDepartamente = c.nrDepartamente;
        if (c.bugetDepartament != nullptr) {
            this->bugetDepartament = new float[c.nrDepartamente];
            for (int i = 0; i < c.nrDepartamente; i++) {
                this->bugetDepartament[i] = c.bugetDepartament[i];
            }
        }
        else {
            this->bugetDepartament = nullptr;
        }
        nrInstitutiiInregistrate++;
    }
    // destructor
    ~Companie() {
        if (this->bugetDepartament != nullptr) {
            delete[]this->bugetDepartament;
            this->bugetDepartament = nullptr;
        }
        nrInstitutiiInregistrate--;
    }
    //operator=
    Companie& operator=(const Companie& c) {
        if (this != &c) {
            this->nrIdentificare = c.nrIdentificare;
            this->denumire = c.denumire;
            this->nrDepartamente = c.nrDepartamente;
            if (c.bugetDepartament != nullptr) {
                this->bugetDepartament = new float[c.nrDepartamente];
                for (int i = 0; i < c.nrDepartamente; i++) {
                    this->bugetDepartament[i] = c.bugetDepartament[i];
                }
            }
            else {
                this->bugetDepartament = nullptr;
            }
        }
        return *this;
    }
    //getters and setters
    static int getNrInstitutiiInregistrate() {
        return nrInstitutiiInregistrate;

    }
    static void setNrInstitutiiInregistrate(int nri) {
        Companie::nrInstitutiiInregistrate = nri;
    }
    int getNrIdentificare() {
        return nrIdentificare;
    }
    void setNrIdentificare(int nrI) {
        this->nrIdentificare = nrI;
    }
    string getDenumire() {
        return denumire;
    }
    void setDen(string denu) {
        this->denumire = denu;
    }
    float* intBugeteDepart() {
        float* copy;
        if (this->bugetDepartament != nullptr) {
            copy = new float[this->nrDepartamente];
            for (int i = 0; i < nrDepartamente; i++) {
                copy[i] = this->bugetDepartament[i];
            }
        }
        else {
            copy = nullptr;
        }
        return copy;
    }
    void setBugeteDepar( float* bugetDepartamente) {
        if (this->bugetDepartament != nullptr) {
            delete[]this->bugetDepartament;
        }
        if (bugetDepartament != nullptr) {
            this->bugetDepartament = new float[this->nrDepartamente];
        
        }
        else {
            this->bugetDepartament = nullptr;
        }
    }
    void prelungireDenumire(string s) {
        this->denumire = this->denumire + s;
            
    }
    float& operator[](int index) {
        if (this->bugetDepartament != nullptr && index >= 0 && index < nrDepartamente) {
            return this->bugetDepartament[index];
        }
    }
    Companie operator++(int i) {
        Companie copy = *this;
        if (this->bugetDepartament != nullptr && this->nrDepartamente >= 2) {
            this->bugetDepartament[1]++;
        }
            return copy;
        
    }
    friend istream& operator>>(istream&, Companie&);
};
int Companie::nrInstitutiiInregistrate = 0;
istream& operator>>(istream& in, Companie& c) {
    cout << endl << "denumire noua";
    in >> c.denumire;
    cout << "nr nou identificare";
    in >> c.nrIdentificare;
    return in;
}
int main()
{
    Companie c (IMM, 1);
    float buget[]  { 1000,1233,2222 };
    Companie c1 (IMM, 1, "Gepeto", 4, buget);
    c.setDen("Gepeto The best");
    cout << endl;
    c1.prelungireDenumire("BFF");
    cout << c1.getDenumire();
    cout << endl;

    Companie c2 = c1;
    cout << c2.getNrIdentificare()<<endl;

    Companie c5 = c2++;
    cout << c5.intBugeteDepart() << endl;

    //op []
    cout << c[0] << c[1]<<endl;
    c[0] = 2;
    cout << c[0]<<endl;

    cin >> c;
    cout << c.getDenumire()<<" "<<c1.getNrIdentificare();
}

