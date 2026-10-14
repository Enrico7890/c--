/* presa in inuput una matrice di dimensione n×m, 
determinare a partire da essa gli n array mododimensionali di dimensione m, 
i cui elementi sono gli elementi di ciascuna riga della matrice moltiplicati per un numero casuale 
(compreso tra il valore minimo e il valore massimo dell'array) generato all'inizio di tutto il procedimento */

#include "matrice10.hpp"
// MAIN
// Parametri formali: nessuno
// Parametri attuali: nessuno
// Variabili locali: k, o, min, max, p, u, n, m
// Passaggio parametri: non ce ne sono
int main(){
    int k[dim][dim];
    int o[dim][dim];
    int min, max, p;
    srand(time(NULL));

    string u = "inserisci righe ";
    int n = inputdim(u);
    u = "inserisci colonne ";
    int m = inputdim(u);

    inputmatrice(k, n, m);
    minmax(k, min, max, n, m);
    p = casuale(min, max);
    nuovoarr(k, o, p, n, m);
    output(k, o, p, n, m);
}

// INPUTDIM
// Parametri attuali: u
// Parametri formali: d
// Variabili locali: num
// Passaggio parametri:
// - d: per valore
int inputdim(string d) {
    int num = 0;
    do {
        cout << d;
        cin >> num;
    } while (num <= 0 || num > dim);
    return num;
}

// INPUTMATRICE
// Parametri attuali: k, n, m
// Parametri formali: mat, r, c
// Variabili locali: i, j
// Passaggio parametri:
// - mat: per riferimento (array)
// - r, c: per valore
void inputmatrice(int mat[][dim], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << "inserisci elemento " << i << " " << j << endl;
            cin >> mat[i][j];
        }
    }
}

// Determinare il valore minimo e il valore massimo di tutti gli elementi della matrice

// MINMAX
// Parametri attuali: k, min, max, n, m
// Parametri formali: mat, min, max, r, c
// Variabili locali: i, j
// Passaggio parametri:
// - mat: per riferimento (array)
// - min, max: per riferimento (&)
// - r, c: per valore
void minmax(int mat[][dim], int& min, int& max, int r, int c){
    min = mat[0][0];
    max = mat[0][0];
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (mat[i][j] < min)
                min = mat[i][j];
            if (mat[i][j] > max)
                max = mat[i][j];
        }
    }
}

// Determinare un numero casuale compreso tra il minimo e il massimo

// CASUALE
// Parametri attuali: min, max
// Parametri formali: e, x
// Variabili locali: t
// Passaggio parametri:
// - e, x: per valore
int casuale(int e, int x){
    int t = 0;
    t = e + rand() % (x - e + 1);
    return t;
}

// Determinare gli n array di dimensione m: ogni elemento di una riga della matrice
// viene moltiplicato per il numero casuale

// NUOVOARR
// Parametri attuali: k, o, p, n, m
// Parametri formali: mat, arr, p, r, c
// Variabili locali: i, j
// Passaggio parametri:
// - mat, arr: per riferimento (array)
// - p, r, c: per valore
void nuovoarr(int mat[][dim], int arr[][dim], int p, int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            arr[i][j] = mat[i][j] * p;
        }
    }
}

// OUTPUT
// Parametri attuali: k, o, p, n, m
// Parametri formali: mat, arr, p, r, c
// Variabili locali: i, j
// Passaggio parametri:
// - mat, arr: per riferimento (array)
// - p, r, c: per valore
void output(int mat[][dim], int arr[][dim], int p, int r, int c){
    cout << "matrice originale " << endl;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << "numero casuale: " << p << endl;
    for (int i = 0; i < r; i++){
        cout << "array " << i << ": ";
        for (int j = 0; j < c; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}