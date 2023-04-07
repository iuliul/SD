#include <iostream>

using namespace std;

#include "atm.h"

ATM::ATM()
{
    this -> nrtranzactii = 0;
}

ATM::ATM(Colectie &c)
{
    this -> bani = c;
    this -> nrtranzactii = 0;
}

ostream& operator<<(ostream &os, ATM &a)
{
    os << "In ATM exista urmatoarea colectie de bani: \n";
    os<<a.bani;
    os<<"\n";
    os << "S-a efectuat un numar de "<<a.nrtranzactii<<" tranzactii.";
    if(a.nrtranzactii>0)
    {
        os<<" Acestea sunt: \n";
        for(int i=0; i<a.nrtranzactii; i++)
            os<<"\n"<<a.tranzactii[i];
    }
    os<<"\n";
    return os;
}

int n=4;

int x[11]; ///frecventa bacnotelor
int a[11]; ///pozitia bancnotelor in colectie

int cont=0;
Colectie c[10]; ///vectorul care va contine solutiile

void afisare(int k)
{
    for(int i = 0 ; i <= k  ; i++)
        c[cont].setfrelem(a[i],x[i]);
    cout<<c[cont];
    cont++;
}

//
void ATM::greedy(int ches)//suma introdusa de la tastatura
{
    int rez=0, ok=0;//rez suma generata pe parcurs
    int k=-1;
    for(int i=7; i>=0 && ok==0; i--)//parcurgerea bacnotelor in sens invers
    {
        int c =(ches-rez)/this->bani.getelem(i);//catul verifica daca suma curenta se imparte la bacnota
        if(c<=this->bani.getfrelem(i)&&c>0)//cand catul e 0 si se imparte la suma, nu i bine
        {
            rez=rez+c*this->bani.getelem(i);//se formeaza suma partiala
            k++;
            x[k]=c;
            a[k]=i;
        }

        if(rez==ches) ok=1;
    }
    if(ok==1) afisare(k);
    else cout<<"Nu s-a gasit solutie\n";
}

void ATM::update(int ches)
{
    int op=cont-1;
    Tranzactie t(this->nrtranzactii,ches,c[op]);
    this->tranzactii[this->nrtranzactii] = t;
    this->nrtranzactii++;
    for(int i=0; i<this->bani.getcap(); i++)
    {

        int dif=this->bani.getfrelem(i)-c[op].getfrelem(i);
        this->bani.setfrelem(i,dif);
    }
}

