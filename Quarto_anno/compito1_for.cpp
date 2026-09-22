// Preso in input un array di N interi, calcolare la somma di tutti i suoi elementi positivi e il prodotto dei suoi elementi negativi

#include <iostream>
using namespace std; 

const int dim = 100;

int inputn();
void inputarr(int numeri[dim], int n);
void somma(int numeri[dim], int n);
void prodotto(int numeri[dim], int n);


int main (){
    int numeri[dim];
    int n = inputn();
    inputarr(numeri, n);
    somma(numeri, n);
    prodotto(numeri, n);
}

// input dimensione

int inputn(){
    int n = 0;
    do{
        cout << "Inserisci la dimensione dell'array " << endl;
        cin >> n;
    }while (n <= 0 || n> dim);
    return n;
}

// input array

void inputarr(int numeri[dim], int n){
    for (int i = 0; i < n; i++){
        cout << "inserisci un numero " << endl;
        cin >> numeri[i];
    }
}

//calcolare la somma di tutti i suoi elementi positivi

void somma(int numeri[dim], int n){
    int somma = 0;
    for (int i = 0; i < n; i++){
        if (numeri[i] >= 0)
        somma+=numeri[i];
    }
    cout << "la somma e' " << somma << endl;
}

//il prodotto dei suoi elementi negativi

void prodotto(int numeri[dim], int n){
    int prodotto = 1;
    for (int i = 0; i < n; i++){
        if (numeri[i] < 0)
        prodotto*=numeri[i];
    }
    cout << "il prodotto e' " << prodotto << endl;
}