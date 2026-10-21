/* Preso in input un array bidimensionale di NxN interi (matrice quadrata di dimensione N), 
determinare il valore minimo tra la somma di tutti gli elementi della diagonale principale 
e il prodotto di tutti gli elementi della diagonale secondaria. */

#include <iostream>
#include <string>
#include "matrice9.hpp"
using namespace std;

// main non ha parametri formali né parametri attuali.
// Variabili locali: mat, n, s, p, mn, u.
// Parametri attuali delle chiamate: inputn(u); inputmatrice(mat, n);
// somma(mat, n); prodotto(mat, n); minimo(s, p); output(mat, n, s, p, mn, u).
// I parametri array k sono puntatori passati per valore; gli altri parametri
// sono passati per valore (nessuna funzione usa parametri per riferimento).
int main(){
    int mat[dim][dim];
    int n;
    int s, p, mn;
    string u;

    u = "inserisci dimensione ";
    n = inputn(u);
    inputmatrice(mat, n);
    s = somma(mat, n);
    p = prodotto(mat, n);
    mn = minimo(s, p);
    u = "matrice ";
    output(mat, n, s, p, mn, u);
}

// inputn: parametro formale z, parametro attuale u in main, passato per valore.
// Variabile locale: num.
int inputn(string z){
    int num = 0;
    do{
        cout << z;
        cin >> num;
    }   while (num <= 0 || num > dim);
    return num;
}

// inputmatrice: parametri formali k e r; attuali mat e n da main.
// k è un puntatore all'array passato per valore (non per riferimento);
// r è passato per valore. Variabili locali: i, j.
void inputmatrice(int k[][dim], int r){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < r; j++){
            cout << "inserisci componente " << i << " " << j << endl;
            cin >> k[i][j];
        }
    }
}

// somma: parametri formali k e r; attuali mat e n da main.
// k è un puntatore all'array passato per valore; r è passato per valore.
// Variabili locali: s, i.
int somma(int k[][dim], int r){
    int s = 0;
    for (int i = 0; i < r; i++){
        s = s + k[i][i];
    }
    return s;
}

// prodotto: parametri formali k e r; attuali mat e n da main.
// k è un puntatore all'array passato per valore; r è passato per valore.
// Variabili locali: p, i.
int prodotto(int k[][dim], int r){
    int p = 1;
    for (int i = 0; i < r; i++){
        p = p * k[i][r - 1 - i];
    }
    return p;
}

// minimo: parametri formali a e b; attuali s e p da main.
// Entrambi sono passati per valore. Nessuna variabile locale.
int minimo(int a, int b){
    if (a < b)
        return a;
    return b;
}

// output: parametri formali k, r, s, p, mn, t; attuali mat, n, s, p,
// mn, u da main. k è un puntatore all'array passato per valore; r, s, p,
// mn e t sono passati per valore. Variabili locali: i, j.
void output(int k[][dim], int r, int s, int p, int mn, string t){
    cout << t << endl;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < r; j++){
            cout << k[i][j] << " ";
        }
        cout << endl;
    }
    cout << "somma diagonale principale: " << s << endl;
    cout << "prodotto diagonale secondaria: " << p << endl;
    cout << "minimo: " << mn << endl;
}