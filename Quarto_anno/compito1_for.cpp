// Preso in input un array di N interi, calcolare la somma di tutti i suoi elementi positivi e il prodotto dei suoi elementi negativi

#include <iostream>
using namespace std; 

const int dim = 100;

int inputn();
void inputarr(int [], int);
void sommaprodotto(int [], int&, int&, int);
void output(int&, int&);


int main (){
    int banane[dim];
    int somma1, prodotto1;
    int k = inputn();
    inputarr(banane, k);
    sommaprodotto(banane,somma1, prodotto1, k);
    output(somma1, prodotto1);
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

void sommaprodotto(int numeri[dim], int &somma, int &prodotto, int n){
    somma = 0;
    prodotto = 1;
    for (int i = 0; i < n; i++){
        if (numeri[i] >= 0)
        somma+=numeri[i];
        else if (numeri[i] < 0)
        prodotto*=numeri[i];
    } 
}

void output (int &somma, int &prodotto){
    cout << "la somma e' " << somma << endl;
    cout << "il prodotto e' " << prodotto << endl;
}