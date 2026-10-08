/* Preso in input un array bidimensionale (matrice) di interi di dimensione NxM 
(N.B.: N ed M sono due valori interi che vengono presi precedentemente in input), 
determinare la matrice trasposta di dimensione MxN, in cui le righe della prima matrice diventano le colonne della seconda matrice, 
e parallelamente le colonne della prima matrice diventano le righe della seconda. */

#include <iostream>
#include <string>
using namespace std;

// VARIABILI/COSTANTI GLOBALI:
// - dim (costante globale, int, vale 100): dimensione massima della matrice.
//   Non ci sono variabili globali.
const int dim = 100;

int inputn(string);
void inputmatrice(int [][dim], int, int);
void tras(int [][dim], int, int, int [][dim]);
void output(int [][dim], int, int, int [][dim]);

// MAIN
// Parametri formali: nessuno
// Parametri attuali: nessuno
// Variabili locali: mat, mat2, n, m, u
// Passaggio parametri: non ce ne sono
int main(){
    int mat[dim][dim];
    int mat2[dim][dim];
    int n, m;
    string u;

    u = "inserisci righe ";
    n = inputn(u);
    u = "inserisci colonne ";
    m = inputn(u);
    inputmatrice(mat, n, m);
    tras(mat, n, m, mat2);
    output(mat, n, m, mat2);
}

// INPUTN
// Parametri attuali: u
// Parametri formali: z
// Variabili locali: num
// Passaggio parametri:
// - z: per valore
int inputn(string z){
    int num = 0;
    do{
        cout << z;
        cin >> num;
    }   while (num <= 0 || num > dim);
    return num;
}

// INPUTMATRICE
// Parametri attuali: mat, n, m
// Parametri formali: k, r, c
// Variabili locali: i, j
// Passaggio parametri:
// - k: per riferimento (array)
// - r, c: per valore
void inputmatrice(int k[][dim], int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << "inserisci componente " << i << " " << j << endl;
            cin >> k[i][j];
        }
    }
}

// Determinare la matrice trasposta di dimensione MxN

// TRAS
// Parametri attuali: mat, n, m, mat2
// Parametri formali: k, r, c, x
// Variabili locali: i, j
// Passaggio parametri:
// - k, x: per riferimento (array)
// - r, c: per valore
void tras(int k[][dim], int r, int c, int x [][dim]){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            x[j][i]=k[i][j];
        }
    }
}

// OUTPUT
// Parametri attuali: mat, n, m, mat2
// Parametri formali: k, r, c, x
// Variabili locali: i, j
// Passaggio parametri:
// - k, x: per riferimento (array)
// - r, c: per valore
void output(int k[][dim], int r, int c, int x[][dim]){
    cout << "matrice originale " << endl;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << k[i][j] << " ";
        }
        cout << endl;
    }
    cout << "matrice trasposta " << endl;
    for (int i = 0; i < c; i++){
        for (int j = 0; j < r; j++){
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}