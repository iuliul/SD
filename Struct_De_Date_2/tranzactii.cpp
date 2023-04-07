#include "tranzactii.h"

Tranzactie::Tranzactie(){
    this -> idTr = 0;
    this -> suma = 0;
}

Tranzactie::Tranzactie(int id, int s, Colectie &b){
    this -> idTr = id;
    this -> suma = s;
    this -> bani = b;
}

Tranzactie& Tranzactie::operator = (const Tranzactie& t){
    this->idTr = t.idTr;
    this->suma = t.suma;
    this->bani = t.bani;
    return *this;
}

ostream& operator << (ostream &os, const Tranzactie &t){
    os << "Id-ul tranzactiei: " << t.idTr << "\n";
    os << "Suma tranzactiei: " << t.suma << "\n";
    os << "Pentru realizarea platii s-a folosit urmatoarea colectie: \n";
    os << t.bani;
    return os;
}