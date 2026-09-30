//Preso in input un array bidimensionale di dimensioni NxM (N righe, M colonne) di caratteri, 
// ed altri due caratteri a parte x e y, sostituire nell’array tutte le occorrenze di x con y 
//ossia tutte gli elementi dell’array che contengono il valore di x dovranno contenere il valore di y)

#include <iostream>
using namespace std;

const int dim = 100;
// Variabile/costante globale: dim (costante globale).

// Parametri formali: nessuno. Variabile locale: nessuna.
int inputn();
// Parametri formali: matrice (array, passato come indirizzo), n e m (per valore).
// Variabili locali: i e j nei cicli.
void inputmatrice(char [][dim], int, int);
// Parametri formali: nessuno. Variabile locale: k.
char inputcaratteri();
// Parametri formali: matrice (array, passato come indirizzo), x, y, n e m (per valore).
// Variabili locali: i e j nei cicli.
void occorrenze(char [][dim], char, char, int, int);
// Parametri formali: matrice (array, passato come indirizzo), n e m (per valore).
// Variabili locali: i e j nei cicli.
void output(char[][dim], int, int);

int main(){
    // Parametri formali: nessuno. Parametri attuali nelle chiamate: mat, n1, m1;
    // mat, x, y, n1, m1; e mat, n1, m1 rispettivamente.
    // Variabili locali: mat, n1, m1, x e y. Gli array sono passati come indirizzo;
    // tutti gli altri parametri sono passati per valore.
    char mat[dim][dim];
    int n1 = inputn();
    int m1 = inputn();
    inputmatrice(mat, n1, m1);
    char x = inputcaratteri();
    char y = inputcaratteri();
    occorrenze(mat, x, y, n1, m1);
    output(mat, n1, m1);
}

int inputn(){
    // Parametri attuali/formali: nessuno. Variabile locale: num.
    int num = 0;
    do{
        cout << "inserisci la dimensione delle righe e poi delle colonne " << endl;
        cin >> num;
    }while (num <= 0 || num > dim);
    return num;
}

void inputmatrice(char matrice[][dim], int n, int m){
    // Parametri attuali: mat, n1, m1. Parametri formali: matrice, n, m.
    // matrice è passato come indirizzo (le modifiche agiscono sull'array originale);
    // n e m sono passati per valore. Variabili locali: i e j.
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << "inserisci elemento " << i << " " << j << " " << " della matrice " << endl;
            cin >> matrice[i][j];
        }
    }
}

char inputcaratteri(){
    // Parametri attuali/formali: nessuno. Variabile locale: k.
    char k;
    cout << "Inserisci carattere (prima x poi y) "  << endl;
    cin >> k;
    return k;
}

void occorrenze(char matrice[][dim], char x, char y, int n, int m){
    // Parametri attuali: mat, x, y, n1, m1. Parametri formali: matrice, x, y, n, m.
    // matrice è passato come indirizzo; x, y, n e m sono passati per valore.
    // Variabili locali: i e j.
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (matrice[i][j]==x)
            matrice[i][j] = y;
        }
    }
}

void output(char matrice[][dim], int n, int m){
    // Parametri attuali: mat, n1, m1. Parametri formali: matrice, n, m.
    // matrice è passato come indirizzo; n e m sono passati per valore.
    // Variabili locali: i e j.
    cout << " il nuovo array e' " << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << matrice[i][j] << " ";
        cout << endl;
    }
}