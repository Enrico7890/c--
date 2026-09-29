// Presa in input una matrice di N x M interi, ed un altro intero a parte,
// contare quante volte quest'ultimo viene ripetuto all'interno della matrice.
#include <iostream>
using namespace std;

const int dim = 100;

int inputn();
void inputmatrice(int [][dim], int, int );
int inputnumero();
int ripetere(int [][dim], int, int, int );
void output(int);

int main() {
    int k[dim][dim];
    int n = inputn();
    int m = inputn();
    inputmatrice(k, n, m);
    int num = inputnumero();
    int conteggio = ripetere(k, num, n, m);
    output(conteggio);
}

int inputn() {
    int n = 0;
    do {
        cout << "Inserisci la dimensione (righe e poi colonne) ";
        cin >> n;
    } while (n <= 0 || n > dim);
    return n;
}

void inputmatrice(int matrice[][dim], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Inserisci l'elemento " << i << " " << j << " ";
            cin >> matrice[i][j];
        }
    }
}

int inputnumero(){
    cout << "Inserisci un numero da cercare " << endl;
    int num = 0;
    cin >> num;
    return num;
}

int ripetere(int matrice[][dim], int num, int n, int m) {
    int conteggio = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrice[i][j] == num)
                conteggio++;
        }
    }
    return conteggio;
}

void output(int conteggio) {
    cout << "Il numero viene ripetuto nella matrice " << conteggio << " volta" << endl;
}