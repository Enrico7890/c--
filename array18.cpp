#include <iostream>
using namespace std;
//Preso in input un array di N interi, contare quanti elementi sono pari e quanti sono dispari e stampare i due conteggi.

const int dim = 100;    
int main (){
    int array [dim], n, pari = 0, dispari = 0;

    do {
        cout << "quanto e' lungo il tuo array" << endl;
        cin >> n;
    } while (n <= 0 || n > dim);

    for (int i = 0; i < n; i++){
        cout << "Inserisci un valore per l'array " << endl;
        cin >> array [i];
    }
    for (int i = 0; i< n; i++){
        if (array [i] % 2 == 0){
            pari++;
        }
        else if (array [i] % 2 != 0){
            dispari++;
        }
    }
    cout << "I numeri pari sono " << pari << endl;
    cout << "i numeri dispari sono " << dispari << endl; 
}