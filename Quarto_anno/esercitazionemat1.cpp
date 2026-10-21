#include <iostream>
using namespace std;

/* Utilizzando l’approccio TOP-DOWN, scrivere il codice nel linguaggio C++, 
che risolve il seguente problema che utilizza gli Array Bidimensionali:
Preso in input un array bidimensionale di NxM interi (matrice di interi), 
determinare il valore massimo di ciascuna colonna e successivamente visualizzare la matrice insieme ai valori trovati. */

const int dim = 100;

int inputdim(string);
void inputmatrice(int [][dim], int, int);
void valmax(int [][dim], int, int, int []);
void output(int [][dim], int, int, int);

int main(){
    int mat[dim][dim];
    string u = "Inserisci righe";
    int n = inputdim(u);
    u = "inserisci colonne ";
    int m = inputdim(u);
    inputmatrice(mat, n, m);
    int max[dim];
    valmax(mat, n, m, max);
    output(mat, n, m, max);
}

int inputdim(string z){
    int num = 0;
    do{
        cout << z;
        cin >> num;
    } while (num <= 0 || num > dim);
    return num;
}

void inputmatrice(int matrix[][dim], int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << "inserisci elemento " << i << " " << j << endl;
            cin >> matrix[i][j];
        }
    }
}

void valmax(int matrix[][dim], int r, int c, int colmax[]){
    for (int j = 0; j < c; j++){
        colmax[j] = matrix[0][j];
        for (int i = 1; i < r; i++){
            if (matrix[i][j] > colmax[j]){
                colmax[j] = matrix[i][j];
            }
        }
    }
}

void output(int matrix[][dim], int r, int c, int colmax[]){
    cout << "Matrice" << endl;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Massimo di ciascuna colonna:" << endl;
    for (int j = 0; j < c; j++){
        cout << colmax[j] << "\t";
    }
    cout << endl;
}