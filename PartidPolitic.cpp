// (2p) Sa se realizeze o aplicatie orientata obiect pentru modelarea activitatilor unei asociatii de persoane, ca vector dinamic de persoane (CNP, nume).
// Definiti clasa PartidPolitic in care persoanele au in plus cotizatie.
// Studiati implicatiile pe care le au doua variante de modelare:
// derivare Membru din clasa Persoana, partidul fiind asociatie de membri;
// derivare PartidPolitic din clasa Asociatie, deoarece cotizatiile sunt aceleasi pentru toti membrii.
// (1p) Sa se implementeze o modalitate de afisare a obiectelor de baza si derivate.
// (2p) Pentru clasa ce modeleaza asociatia de persoane, sa se supraincarce:
// operator += pentru primirea unui nou membru;
// operator pentru excluderea unui membru din asociatie.
// (2p) Precizati si testati conversiile implicite care sunt acceptate intre diferitele obiecte, intre pointeri si intre referinte de obiecte . Convertiti prin operator cast un simpatizant in membru plin.
// (1p) Declarati in clasa de baza metoda virtuala care in clasa de baza returneaza 0, iar in clasele derivate returneaza valori dupa cum urmeaza:
// pentru un membru plin, 100 lei,
// pentru un membru simpatizant 50 lei.
// (1p) Explicati conceptul de late binding si apeland implementarile metodei getCotizatie() si calculati valoarea totala adunata la nivel de partid, din cotizatii.
// (1p) Folositi o clasa STL pentru a da o alta implementare a asociatiei si parcurgand structura aleasa, verificati daca functioneaza si in acest caz conceptul de late binding.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Persoana //clasa pentru reprezentarea unei persoane
{
protected:
    string CNP;
    string nume;

public:
    Persoana(string CNP, string nume) : CNP(CNP), nume(nume) {}

    virtual int getCotizatie() {
        return 0;
    }

    virtual ~Persoana() {}

    virtual void afisare() {
        cout << "Persoana: " << nume << " CNP: " << CNP << endl;
    }
};

class Membru : public Persoana {
private:
    int cotizatie;

public:
    Membru(string CNP, string nume, int cotizatie) : Persoana(CNP, nume), cotizatie(cotizatie) {}

    int getCotizatie()  {
        return cotizatie;
    }

    void afisare()  {
        cout << "Membru: " << nume << " CNP: " << CNP << " Cotizatie: " << cotizatie << endl;
    }
};

class Asociatie //reprezinta o asociatie de persoane (posibil si membri ai partidului politic).
{
public:
    vector<Persoana*> membri;

    Asociatie() {}

    void operator+=(Persoana* persoana) {
        membri.push_back(persoana);
    }

    void operator-=(Persoana* persoana) {
    for (vector<Persoana*>::iterator it = membri.begin(); it != membri.end(); ++it) {
        if (*it == persoana) {
            membri.erase(it);
            break;
        }
    }
}


    void afisare()  {
        for (const auto& persoana : membri) {
            persoana->afisare();
        }
        cout << endl;
    }


    int calculValoareaTotalaAdunata() {
        int suma = 0;
        for (const auto& persoana : membri) {
            suma += persoana->getCotizatie();
        }
        return suma;
    }
};

class PartidPolitic : public Asociatie //reprezinta un partid politic, care este o asociatie de persoane
{
public:
    PartidPolitic() : Asociatie() {}

    void operator+=(Persoana* persoana) {
        membri.push_back(persoana);
    }

    void operator-=(Persoana* persoana) {
        for (auto it = membri.begin(); it != membri.end(); ++it) {
            if (*it == persoana) {
                membri.erase(it);
                break;
            }
        }
    }
    void afisare()  {
        for (const auto& persoana : membri) {
            persoana->afisare();
        }
        cout << endl;
    }

};

int main() {
    PartidPolitic partid;
    partid += new Membru("567533490209", "John", 100);
    partid += new Membru("2345678901234", "Gigel", 100);
    partid += new Membru("3456789012345", "Anca", 50);

    partid.afisare();
    cout << "Valoarea totala adunata la nivel de partid este: " << partid.calculValoareaTotalaAdunata() << endl;

    partid -= partid.membri[1]; //sterge un membru
    partid.afisare();
    cout << endl;

    Asociatie asociatie;
    asociatie += new Persoana("4567890123456", "Marta"); //se adauga o noua persoana
    asociatie += new Membru("567533490209", "John", 100); //se adauga in asociatie un nou membru

    asociatie.afisare();
    cout << "Valoarea totala adunata la nivel de asociatie este: " << asociatie.calculValoareaTotalaAdunata() << endl;

    asociatie -= asociatie.membri[0];
    asociatie.afisare();

    return 0;
}
