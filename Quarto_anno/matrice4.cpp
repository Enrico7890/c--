/* Utilizzando l'approccio TOP-DOWN, scrivere il codice nel linguaggio C++, che risolve il seguente problema che utilizza gli Array Bidimensionali:
Prendere in input un array bidimensionale (matrice) di interi di dimensione NxM (N.B.: N ed M sono due valori interi che vengono presi precedentemente in input)
Calcolare la somma e il prodotto di tutti i suoi elementi
Individuare l'indice della riga che ha la somma degli elementi minima
Individuare l'indice della colonna che ha il prodotto degli elementi massimo 
Successivamente visualizzare tutti gli elementi della matrice */

#include <iostream>
using namespace std;

// VARIABILI/COSTANTI GLOBALI:
// - dim (costante globale, int, vale 100): dimensione massima della matrice.
//   Non ci sono variabili globali.
const int dim = 100;

int inputn();
void inputmatrice(int [][dim], int, int);
void sommaprodotto(int [][dim], int, int, int&, int&);
int rigasomma(int [][dim], int, int);
int colonnaprodotto(int [][dim], int, int);
void output(int [][dim], int, int, int, int, int, int);

// MAIN
// Parametri formali: nessuno
// Parametri attuali: nessuno
// Variabili locali: a, s, p, n, m, rs, pc
// Passaggio parametri: non ce ne sono
int main(){
    int a[dim][dim];
    int s, p;
    int n = inputn();
    int m = inputn();
    inputmatrice(a, n, m);
    sommaprodotto(a, n, m, s, p);
    int rs = rigasomma(a, n, m);
    int pc = colonnaprodotto(a, n, m);
    output(a, n, m, s, p, rs, pc);
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
// - matrix: per riferimento
// - r, c: per valore
void inputmatrice(int matrix[][dim], int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << "inserisci elemento " << i << " " << j << " della matrice " << endl;
            cin >> matrix[i][j];
        }
    }
}

// Calcolare la somma e il prodotto di tutti i suoi elementi

// SOMMAPRODOTTO
// Parametri attuali: a, n, m, s, p
// Parametri formali: matrix, r, c, somma, prodotto
// Variabili locali: i, j
// Passaggio parametri:
// - matrix: per riferimento (array)
// - r, c: per valore
// - somma, prodotto: per riferimento
void sommaprodotto(int matrix[][dim], int r, int c, int& somma, int& prodotto){
    prodotto = 1;
    somma = 0;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            somma += matrix[i][j];
            prodotto *= matrix[i][j];
        }
    }
}

// Individuare l'indice della riga che ha la somma degli elementi minima

// RIGASOMMA
// Parametri attuali: a, n, m
// Parametri formali: matrix, r, c
// Variabili locali: indice1, minimo, temp, i, j
// Passaggio parametri:
// - matrix: per riferimento (array)
// - r, c: per valore
int rigasomma(int matrix[][dim], int r, int c){
    int indice1 = 0;
    int minimo = 0;

    for (int j = 0; j < c; j++){
        minimo += matrix[0][j];
    }

    for (int i = 0; i < r; i++){
        int temp = 0;
        for (int j = 0; j < c; j++){
            temp += matrix[i][j];
        }
        if (temp < minimo){
            minimo = temp;
            indice1 = i;
        }
    }
    return indice1;
}

// Individuare l'indice della colonna che ha il prodotto degli elementi massimo

// COLONNAPRODOTTO
// Parametri attuali: a, n, m
// Parametri formali: matrix, r, c
// Variabili locali: indice2, max, temp, i, j
// Passaggio parametri:
// - matrix: per riferimento (array)
// - r, c: per valore
int colonnaprodotto(int matrix[][dim], int r, int c){
    int indice2 = 0;
    int max = 1;

    for (int i = 0; i < r; i++){
        max *= matrix[i][0];
    }
    for (int j = 0; j < c; j++){
        int temp = 1;
        for (int i = 0; i < r; i++){
            temp *= matrix[i][j];
        }
        if (temp > max){
            max = temp;
            indice2 = j;
        }
    }
    return indice2;
}

// OUTPUT
// Parametri attuali: a, n, m, s, p, rs, pc
// Parametri formali: matrix, r, c, somma, prodotto, indicer, indicec
// Variabili locali: i, j
// Passaggio parametri:
// - matrix: per riferimento (array)
// - r, c, somma, prodotto, indicer, indicec: per valore
void output(int matrix[][dim], int r, int c, int somma, int prodotto, int indicer, int indicec){
    cout << "La matrice originale e' " << endl;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "la somma e' " << somma << endl;
    cout << "il prodotto e' " << prodotto << endl;
    cout << "la riga somma elementi minima e' " << indicer << endl;
    cout << "la colonna prodotto elementi massima e' " << indicec << endl;
}