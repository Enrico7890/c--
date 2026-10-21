
// Preso in input un array di N interi, rideterminare il valore di ciascun suo elemento in questo modo: 
// se pari esso assumerà il quadrato del valore iniziale, se dispari invece conterrà il cubo del valore iniziale.

#include <iostream>
using namespace std;

const int dim = 100;

int inputn();
void inputarr(int numeri[dim], int n);
void quadratopari(int numeri[dim], int n);
void cubodispari(int numeri[dim], int n);

int main(){
    int numeri[dim];
    int n = inputn();
    inputarr(numeri, n);
    quadratopari(numeri, n);
    cubodispari(numeri, n);
}

int inputn(){
    int n = 0;
    do{
        cout << "Inserisci la dimensione dell'array " << endl;
        cin >> n;
    } while (n <= 0 || n > dim);
    return n;
}

void inputarr(int numeri[dim], int n){
    int i = 0;
    do{
        cout << "Inserisci un numero " << endl;
        cin >> numeri[i];
        i++;
    } while (i < n);
}

//se pari esso assumerà il quadrato del valore iniziale;

void quadratopari(int numeri[dim], int n){
    int i = 0;
    do{
        if(numeri[i] % 2 == 0){
            numeri[i]*=numeri[i];
            cout << "i nuovi valori sono " << numeri[i] << endl;
        }
        i++;
    } while (i < n);
}

//se dispari invece conterrà il cubo del valore iniziale;

void cubodispari(int numeri[dim], int n){
    int i = 0;
    do{
        if(numeri[i] % 2 != 0){
            numeri[i]=numeri[i]*numeri[i]*numeri[i];
            cout << "il nuovo array e' " << numeri[i] << endl;
        }
        i++;
    } while (i < n);
}