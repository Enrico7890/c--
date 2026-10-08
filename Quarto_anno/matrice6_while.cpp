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
// Passaggio parametri: z per valore
int inputn(string z){
    int num = 0;
    while (num <= 0 || num > dim){
        cout << z;
        cin >> num;
    }
    return num;
}

// INPUTMATRICE
// Parametri attuali: mat, n, m
// Parametri formali: k, r, c
// Variabili locali: i, j
// Passaggio parametri: k per riferimento (array); r, c per valore
void inputmatrice(int k[][dim], int r, int c){
    int i = 0;
    while (i < r){
        int j = 0;
        while (j < c){
            cout << "inserisci componente " << i << " " << j << endl;
            cin >> k[i][j];
            j++;
        }
        i++;
    }
}

// TRAS
// Parametri attuali: mat, n, m, mat2
// Parametri formali: k, r, c, x
// Variabili locali: i, j
// Passaggio parametri: k, x per riferimento (array); r, c per valore
void tras(int k[][dim], int r, int c, int x[][dim]){
    int i = 0;
    while (i < r){
        int j = 0;
        while (j < c){
            x[j][i] = k[i][j];
            j++;
        }
        i++;
    }
}

// OUTPUT
// Parametri attuali: mat, n, m, mat2
// Parametri formali: k, r, c, x
// Variabili locali: i, j
// Passaggio parametri: k, x per riferimento (array); r, c per valore
void output(int k[][dim], int r, int c, int x[][dim]){
    cout << "matrice originale " << endl;
    int i = 0;
    while (i < r){
        int j = 0;
        while (j < c){
            cout << k[i][j] << " ";
            j++;
        }
        cout << endl;
        i++;
    }
    cout << "matrice trasposta " << endl;
    i = 0;
    while (i < c){
        int j = 0;
        while (j < r){
            cout << x[i][j] << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}