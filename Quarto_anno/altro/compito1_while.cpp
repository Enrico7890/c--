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
    while (n <= 0 || n> dim){
        cout << "Inserisci la dimensione dell'array " << endl;
        cin >> n;
    }
    return n;
}

// input array

void inputarr(int numeri[dim], int n){
    int i = 0;
    while (i < n){
        cout << "inserisci un numero " << endl;
        cin >> numeri[i];
        i++;
    }
}

//calcolare la somma di tutti i suoi elementi positivi

void somma(int numeri[dim], int n){
    int somma = 0;
    int i = 0;
    while(i < n){
        if (numeri[i] >= 0)
        somma+=numeri[i];
        i++;
    }
    cout << "la somma e' " << somma << endl;
}

//il prodotto dei suoi elementi negativi

void prodotto(int numeri[dim], int n){
    int prodotto = 1;
    int i = 0;
    while(i < n){
        if (numeri[i] < 0)
        prodotto*=numeri[i];
        i++;
    }
    cout << "il prodotto e' " << prodotto << endl;
}