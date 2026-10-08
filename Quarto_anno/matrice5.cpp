/* Utilizzando l'approccio TOP-DOWN, scrivere il codice nel linguaggio C++, che risolve il seguente problema che utilizza gli Array Bidimensionali:
Prendere in input un array bidimensionale (matrice) di caratteri di dimensione NxM (N.B.: N ed M sono due valori interi che vengono presi precedentemente in input)
Prendere in input altri due caratteri
Sostituire in tutta la matrice il primo carattere con il secondo
Successivamente visualizzare tutti gli elementi della matrice */

#include <iostream>
using namespace std;

// VARIABILI/COSTANTI GLOBALI:
// - dim (costante globale, int, vale 100): dimensione massima della matrice.
//   Non ci sono variabili globali.
const int dim = 100;

int inputn();
void inputmatrice(char [][dim], int, int);
void inputcaratteri(char&, char&);
void sostituisci(char [][dim], int, int, char, char);
void output(char [][dim], int, int);

// MAIN
// Parametri formali: nessuno
// Parametri attuali: nessuno
// Variabili locali: a, n, m, c1, c2
// Passaggio parametri: non ce ne sono
int main(){
    char a[dim][dim];
    char c1, c2;
    int n = inputn();
    int m = inputn();
    inputmatrice(a, n, m);
    inputcaratteri(c1, c2);
    sostituisci(a, n, m, c1, c2);
    output(a, n, m);
}

// INPUTN
// Parametri attuali: nessuno
// Parametri formali: nessuno
// Variabili locali: num
// Passaggio parametri: non ce ne sono
int inputn(){
    int num = 0;
    do{
        cout << "Inserisci righe e poi colonne " << endl;
        cin >> num;
    } while (num <= 0 || num > dim);
    return num;
}

// INPUTMATRICE
// Parametri attuali: a, n, m
// Parametri formali: matrix, r, c
// Variabili locali: i, j
// Passaggio parametri:
// - matrix: per riferimento (array)
// - r, c: per valore
void inputmatrice(char matrix[][dim], int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << "inserisci elemento " << i << " " << j << " della matrice " << endl;
            cin >> matrix[i][j];
        }
    }
}

// Prendere in input altri due caratteri

// INPUTCARATTERI
// Parametri attuali: c1, c2
// Parametri formali: primo, secondo
// Variabili locali: nessuna
// Passaggio parametri:
// - primo, secondo: per riferimento
void inputcaratteri(char& primo, char& secondo){
    cout << "Inserisci il carattere da sostituire " << endl;
    cin >> primo;
    cout << "Inserisci il carattere sostitutivo " << endl;
    cin >> secondo;
}

// Sostituire il primo carattere con il secondo

// SOSTITUISCI
// Parametri attuali: a, n, m, c1, c2
// Parametri formali: matrix, r, c, vecchio, nuovo
// Variabili locali: i, j
// Passaggio parametri:
// - matrix: per riferimento (array)
// - r, c, vecchio, nuovo: per valore
void sostituisci(char matrix[][dim], int r, int c, char vecchio, char nuovo){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (matrix[i][j] == vecchio){
                matrix[i][j] = nuovo;
            }
        }
    }
}

// OUTPUT
// Parametri attuali: a, n, m
// Parametri formali: matrix, r, c
// Variabili locali: i, j
// Passaggio parametri:
// - matrix: per riferimento (array)
// - r, c: per valore
void output(char matrix[][dim], int r, int c){
    cout << "La matrice modificata e' " << endl;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}