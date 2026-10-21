/* Utilizzando l’approccio TOP-DOWN, 
scrivere il codice nel linguaggio C++, che risolve il seguente problema che utilizza gli Array Bidimensionali:
Preso in input un array bidimensionale di NxM interi (matrice di interi), 
determinare il valore massimo e il valore minimo di tutti i suoi elementi e successivamente visualizzare la matrice insieme ai valori trovati */

#include <iostream>
using namespace std;

const int dim = 100;

int inputdim(string);
void inputmatrice(int [][dim], int, int);
int valoremax(int [][dim], int, int);
int valoremin(int [][dim], int, int);
void output(int [][dim], int, int, int, int);

int main(){
    int mat[dim][dim];
    int max, min;
    string u = "inserisci righe ";
    int n = inputdim(u);
    u = "inserisci colonne ";
    int m = inputdim(u);    
    inputmatrice(mat, n, m);
    max = valoremax(mat, n, m);
    min = valoremin(mat, n, m);
    output(mat, n, m, min, max);
}

int inputdim(string z){
    int num = 0;
    do{
        cout << z;
        cin >> num;
    }while (num <= 0 || num > dim);
    return num;
}

void inputmatrice(int matrix[][dim], int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << "inserisci l'elemento " << i << " " << j << endl;
            cin >> matrix[i][j];
        }
    }
}

int valoremax(int matrix[][dim], int r, int c){
    int massimo = matrix[0][0];
    for(int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (matrix[i][j] > massimo)
            massimo = matrix[i][j];
        }
    }
    return massimo;
}

int valoremin(int matrix[][dim], int r, int c){
    int minimo = matrix[0][0];
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (matrix[i][j] < minimo)
            minimo = matrix[i][j];
        }
    }
    return minimo;
}

void output(int matrix[][dim], int r, int c, int min, int max){
    cout << "matrice originale " << endl;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++)
        cout << matrix[i][j] << "\t";
    }
    cout << "valore minimo " << min << endl;
    cout << "valore massimo " << max;
}