#include "colectie.h"

class Tranzactie{
private:
    int idTr;
    int suma;
    Colectie bani;
public:
    Tranzactie();
    Tranzactie(int id, int s, Colectie &b);
    //~Tranzactie();
    int getidTr();
    int getsuma();
    Tranzactie& operator=(const Tranzactie &t);
    friend ostream& operator<<(ostream &os, const Tranzactie &t);
};
