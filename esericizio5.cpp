#include <iostream>
using namespace std;

int main() {
    double N, N1, somma, prodotto, i;

    i = 0;
    somma = 0;
    prodotto = 1;

    cout << "quanti numeri vuoi inserire" << endl;
    cin >> N;

    if (N!=-1){
        while (i<N) {
            cout << "inserisci un numero" << endl;
            cin >> N1;
        if (N1> 0) {
            somma = somma + N1;
        } 
        else if (N1< 0) {
            prodotto = prodotto * N1;
        }
        i++;
    }
    cout << "Il prodotto e' " << prodotto << endl;
    cout << "La somma e' " << somma << endl;
    }
}