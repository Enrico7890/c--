#include <iostream>
#include <string>
using namespace std;

const int dim = 100;

struct Lista{
    string articolo;
    string descrizione;
    double prezzo;
};

int inputn();
void inputlista(Lista nozze[], int n);
void menu(Lista nozze[], int n);
void articolocostoso(Lista nozze[], int n);
void detdescrizione(Lista nozze[], int n);
void detprezzo(Lista nozze[], int n);
void prezzomedio(Lista nozze[], int n);