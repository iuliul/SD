#include "tranzactii.h"

class ATM{
private:
    Colectie bani;
    Tranzactie tranzactii[12];
    int nrtranzactii;
public:
    ATM();
    ATM(Colectie &c);
    //~ATM();
    void adaugatr(int suma, Colectie b);
    void greedy(int ches);
    void update(int ches);
    friend ostream& operator<<(ostream &os, ATM &a);
};

