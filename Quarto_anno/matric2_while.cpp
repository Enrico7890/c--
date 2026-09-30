//Preso in input un array bidimensionale di dimensioni NxM (N righe, M colonne) di caratteri, 
// ed altri due caratteri a parte x e y, sostituire nell’array tutte le occorrenze di x con y 
//ossia tutte gli elementi dell’array che contengono il valore di x dovranno contenere il valore di y)

#include <iostream>
using namespace std;

const int dim = 100;
// Costante globale: dim.

// Parametri formali dei prototipi: inputn e inputcaratteri non ne hanno;
// inputmatrice(char[][dim], int, int), occorrenze(char[][dim], char, char, int, int)
// e output(char[][dim], int, int). I parametri array sono accessibili/modificabili
// tramite l'array passato; tutti i parametri scalari sono passati per valore.
int inputn();
void inputmatrice(char [][dim], int, int);
char inputcaratteri();
void occorrenze(char [][dim], char, char, int, int);
void output(char[][dim], int, int);

int main(){
    // main non ha parametri formali. Variabili locali: mat, n1, m1, x, y.
    char mat[dim][dim];
    int n1 = inputn();
    int m1 = inputn();
    // Parametri attuali di inputmatrice: mat, n1, m1; formali: matrice, n, m.
    inputmatrice(mat, n1, m1);
    char x = inputcaratteri();
    char y = inputcaratteri();
    // inputcaratteri: nessun parametro attuale o formale.
    // Parametri attuali di occorrenze: mat, x, y, n1, m1; formali: matrice, x, y, n, m.
    occorrenze(mat, x, y, n1, m1);
    // Parametri attuali di output: mat, n1, m1; formali: matrice, n, m.
    output(mat, n1, m1);
}

int inputn(){
    // Nessun parametro attuale/formale; variabile locale: num.
    int num = 0;
    do{
        cout << "inserisci la dimensione delle righe e poi delle colonne " << endl;
        cin >> num;
    }while (num <= 0 || num > dim);
    return num;
}

void inputmatrice(char matrice[][dim], int n, int m){
    // Formali: matrice, n, m; nessun attuale in questa definizione; locali: i, j.
    // matrice è un parametro array; n e m sono passati per valore.
    int i = 0;
    while (i < n){
        int j = 0;
        while (j < m){
            cout << "inserisci elemento " << i << " " << j << " " << " della matrice " << endl;
            cin >> matrice[i][j];
            j++;
        }
        i++;
    }
}

char inputcaratteri(){
    // Nessun parametro attuale/formale; variabile locale: k.
    char k;
    cout << "Inserisci carattere (prima x poi y) "  << endl;
    cin >> k;
    return k;
}

void occorrenze(char matrice[][dim], char x, char y, int n, int m){
    // Formali: matrice, x, y, n, m; nessun attuale in questa definizione; locali: i, j.
    // matrice è un parametro array; x, y, n e m sono passati per valore.
    int i = 0;
    while (i < n){
        int j = 0;
        while (j < m){
            if (matrice[i][j]==x)
            matrice[i][j] = y;
            j++;
        }
        i++;
    }
}

void output(char matrice[][dim], int n, int m){
    // Formali: matrice, n, m; nessun attuale in questa definizione; locali: i, j.
    // matrice è un parametro array; n e m sono passati per valore.
    cout << " il nuovo array e' " << endl;
    int i = 0;
    while (i < n){
        int j = 0;
        while (j < m){
            cout << matrice[i][j] << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}