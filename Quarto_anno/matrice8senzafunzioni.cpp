/* Preso in input un array bidimensionale di NxM caratteri, 
determinare il carattere che precede tutti gli altri in ordine alfabetico 
e quello che invece li segue tutti. */

#include <iostream>
#include <string>
#include "matrice8.hpp"
using namespace std;

// Globali definite in questo file: nessuna (dim è fornita da matrice8.hpp).
// main: nessun parametro formale/attuale; variabili locali: mat, n, m, mn, mx, u.
int main(){
    char mat[dim][dim];
    int n, m;
    char mn, mx;
    string u;

    u = "inserisci righe ";
    // inputn: attuale u; formale z, passato per valore.
    n = inputn(u);
    u = "inserisci colonne ";
    // inputn: attuale u; formale z, passato per valore.
    m = inputn(u);
    // inputmatrice: attuali mat, n, m; formali k, r, c.
    // k è l'indirizzo dell'array, passato per valore; r e c sono passati per valore.
    inputmatrice(mat, n, m);
    u = "matrice ";
    // output: attuali mat, n, m, u; formali k, r, c, p.
    // k è l'indirizzo dell'array, passato per valore; r, c e p sono per valore.
    output(mat, n, m, u);
    // minmax: attuali mat, n, m, mn, mx; formali k, r, c, mn, mx.
    // k è l'indirizzo dell'array, passato per valore; r e c per valore, mn e mx per riferimento.
    minmax(mat, n, m, mn, mx);
    cout << "carattere che precede tutti: " << mn << endl;
    cout << "carattere che segue tutti: " << mx << endl;
}

// inputn: formale z, passato per valore; attuali dal main: u (due chiamate).
// Variabile locale: num.
int inputn(string z){
    int num = 0;
    do{
        cout << z;
        cin >> num;
    }   while (num <= 0 || num > dim);
    return num;
}

// inputmatrice: formali k, r, c; attuali dal main: mat, n, m.
// k è un puntatore passato per valore (accede all'array originale); r e c per valore.
// Variabili locali: i, j.
void inputmatrice(char k[][dim], int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << "inserisci componente " << i << " " << j << endl;
            cin >> k[i][j];
        }
    }
}

// minuscola: formale x, passato per valore; attuali in minmax: k[i][j], mn o mx.
// Variabili locali: nessuna.
char minuscola(char x){
    if (x >= 'A' && x <= 'Z')
        x = x + 32;
    return x;
}

// minmax: formali k, r, c, mn, mx; attuali dal main: mat, n, m, mn, mx.
// k è un puntatore passato per valore; r e c per valore; mn e mx per riferimento.
// Variabili locali: i, j. Gli argomenti delle chiamate a minuscola sono passati per valore.
void minmax(char k[][dim], int r, int c, char &mn, char &mx){
    mn = k[0][0];
    mx = k[0][0];
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (minuscola(k[i][j]) < minuscola(mn))
                mn = k[i][j];
            if (minuscola(k[i][j]) > minuscola(mx))
                mx = k[i][j];
        }
    }
}

// output: formali k, r, c, p; attuali dal main: mat, n, m, u.
// k è un puntatore passato per valore; r, c e p sono passati per valore.
// Variabili locali: i, j.
void output(char k[][dim], int r, int c, string p){
    cout << p << endl;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << k[i][j] << " ";
        }
        cout << endl;
    }
}