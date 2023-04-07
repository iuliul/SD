#include <iostream>
#include <cstring>

using namespace std;

#include "atm.h"

void print_meniu()
{
    cout<<"1. Despre ATM\n";
    cout<<"2. Scoate o suma de bani\n";
    cout<<"0. Iesire\n";
}

void meniu()
{
    int ok=1;
    Colectie c;
    c.adauga(1);
    c.adauga(1);
    c.adauga(1);
    c.adauga(1);
    c.adauga(1);
    c.adauga(5);
    c.adauga(5);
    c.adauga(10);
    c.adauga(10);
    c.adauga(10);
    c.adauga(10);
    ATM atm(c);
    while(ok==1)
    {
        print_meniu();
        cout<<"Dati optiunea: ";
        int optiune;
        cin>>optiune;
        if(optiune == 1) cout<<atm;
        else if(optiune == 2)
        {
            int ches;
            cout<<"Dati suma: ";
            cin>>ches;
            atm.greedy(ches);
            cout<<"Suma se va scoate astfel?\n";
            char op[3];
            cin>>op;
            int o;
            if(strcmp(op,"da")==0) atm.update(ches);
        }
        else if(optiune == 0) ok=0;
        else cout<<"Optiune gresita\n";
    }
}
