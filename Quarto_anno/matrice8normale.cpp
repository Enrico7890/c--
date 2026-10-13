/* Preso in input un array bidimensionale di NxM caratteri, 
determinare il carattere che precede tutti gli altri in ordine alfabetico 
e quello che invece li segue tutti. */

#include <iostream>
#include <string>
using namespace std;

const int dim = 100;
// Costante globale: dim.

int inputn(string);
void inputmatrice(char [][dim], int, int);
char minuscola(char);
void minmax(char [][dim], int, int, char &, char &);
void output(char [][dim], int, int, string);

// main: nessun parametro formale o attuale. Variabili locali: mat, n, m, mn, mx, u.
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
    // k (puntatore alle righe dell'array), r e c sono passati per valore.
    inputmatrice(mat, n, m);
    u = "matrice ";
    // output: attuali mat, n, m, u; formali k, r, c, p.
    // k (puntatore alle righe dell'array), r, c e p sono passati per valore.
    output(mat, n, m, u);
    // minmax: attuali mat, n, m, mn, mx; formali k, r, c, mn, mx.
    // k (puntatore alle righe dell'array), r e c per valore; mn e mx per riferimento.
    minmax(mat, n, m, mn, mx);
    cout << "carattere che precede tutti: " << mn << endl;
    cout << "carattere che segue tutti: " << mx << endl;
}

// inputn: formale z passato per valore; attuale u (nei richiami da main).
// Variabile locale: num.
int inputn(string z){
    int num = 0;
    do{
        cout << z;
        cin >> num;
    }   while (num <= 0 || num > dim);
    return num;
}

// inputmatrice: formali k, r, c; attuali mat, n, m da main.
// k (puntatore alle righe dell'array), r e c sono passati per valore.
// Variabili locali: i, j.
void inputmatrice(char k[][dim], int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << "inserisci componente " << i << " " << j << endl;
            cin >> k[i][j];
        }
    }
}

// minuscola: formale x passato per valore; attuali k[i][j], mn o mx in minmax.
// Variabile locale: x (parametro formale).
char minuscola(char x){
    if (x >= 'A' && x <= 'Z')
        x = x + 32;
    return x;
}

// minmax: formali k, r, c, mn, mx; attuali mat, n, m, mn, mx da main.
// k (puntatore alle righe dell'array), r e c sono passati per valore;
// mn e mx sono passati per riferimento. Variabili locali: i, j.
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

// output: formali k, r, c, p; attuali mat, n, m, u da main.
// k (puntatore alle righe dell'array), r, c e p sono passati per valore.
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