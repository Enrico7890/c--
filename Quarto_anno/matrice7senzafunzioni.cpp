/* Preso in input un array bidimensionale di NxM interi,
rideterminare i valori dei suoi elementi secondo il seguente criterio: 
per ciascun elemento determinare prima di tutto un numero casuale compreso tra il valore Minimo e il valore Massimo di tutti gli elementi
dell'array. 
Successivamente il nuovo valore sarà dato dal valore dell'elemento dell'array 
sommato al valore casuale trovato e al Massimo e sottratto del Minimo.
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "matrice7funzioni.hpp"
using namespace std;

// Costante globale: dim.

int main(){
    // Parametri formali e attuali di main: nessuno.
    // Variabili locali: mat, n, m, u.
    int mat[dim][dim];
    int n, m;
    string u;

    srand(time(NULL));
    u = "inserisci righe ";
    n = inputn(u);
    u = "inserisci colonne ";
    m = inputn(u);
    inputmatrice(mat, n, m);
    u = "matrice originale ";
    output(mat, n, m, u);
    modifica(mat, n, m);
    u = "matrice modificata ";
    output(mat, n, m, u);
}

// inputn: attuale z <- u (chiamate da main); formale z, passato per valore.
// Variabile locale: num.
int inputn(string z){
    int num = 0;
    do{
        cout << z;
        cin >> num;
    }   while (num <= 0 || num > dim);
    return num;
}

// inputmatrice: attuali <- mat, n, m (da main); formali k, r, c.
// k e' passato per valore come puntatore alla prima riga (si copia l'indirizzo);
// r e c sono passati per valore. Variabili locali: i, j.
void inputmatrice(int k[][dim], int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << "inserisci componente " << i << " " << j << endl;
            cin >> k[i][j];
        }
    }
}

// casuale: attuali mn, mx <- mn, mx di modifica; formali mn, mx, passati
// entrambi per valore. Variabili locali: nessuna.
int casuale(int mn, int mx){
    return mn + rand() % (mx - mn + 1);
}

// modifica: attuali <- mat, n, m (da main); formali k, r, c.
// k e' passato per valore come puntatore alla prima riga (si copia l'indirizzo);
// r e c sono passati per valore. Per casuale gli attuali mn e mx sono passati
// per valore. Variabili locali: mn, mx, ran, i, j.
void modifica(int k[][dim], int r, int c){
    int mn = k[0][0];
    int mx = k[0][0];
    int ran;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (k[i][j] < mn)
                mn = k[i][j];
            if (k[i][j] > mx)
                mx = k[i][j];
        }
    }
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            ran = casuale(mn, mx);
            k[i][j] = k[i][j] + ran + mx - mn;
        }
    }
}

// output: attuali <- mat, n, m, u (da main); formali k, r, c, p.
// k e' passato per valore come puntatore alla prima riga (si copia l'indirizzo);
// r, c e p sono passati per valore. Variabili locali: i, j.
void output(int k[][dim], int r, int c, string p){
    cout << p << endl;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << k[i][j] << " ";
        }
        cout << endl;
    }
}