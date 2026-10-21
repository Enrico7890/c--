#include <iostream>
#include <string>
using namespace std;

/* Utilizzando l’approccio TOP-DOWN, scrivere il codice nel linguaggio C++, che risolve il seguente problema che utilizza gli Array Bidimensionali:
Preso in input un array bidimensionale di NxM interi, 
determinare la somma di tutti i suoi elementi e successivamente calcolarne la media (valore reale).
Rideterminare i valori degli elementi dell’array secondo il seguente criterio: 
se l’elemento è maggiore della media, il nuovo valore sarà dato dalla differenza tra l’elemento e il valore Minimo dell’array; 
altrimenti sarà dato dalla somma tra l’elemento e il valore Massimo dell’array.
Visualizzare la matrice originale e la matrice modificata. */

const int dim = 100;

int inputdim(string);
void inputmatrice(int [][dim], int, int);
double media(int [][dim], int, int);
void maxmin(int [][dim], int, int, int&, int&);
void nuovoarr(int [][dim], int, int, double, int, int);
void output(int [][dim], int, int, string);

int main(){
    int mat[dim][dim];
    int max, min;
    string u = "Inserisci righe ";
    int n = inputdim(u);
    u = "inserisci colonne ";
    int m = inputdim(u);
    inputmatrice(mat, n, m);
    double med = media(mat, n, m);
    maxmin(mat, n, m, min, max);
    u = "matrice originale ";
    output(mat, n, m, u);
    nuovoarr(mat, n, m, med, min, max);
    u = "nuova matrice";
    output(mat, n, m, u);
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
            cout << "Inserisci elemento " << i << " " << j << endl;
            cin >> matrix[i][j];
        }
    }
}

double media(int matrix[][dim], int r, int c){
    double medias = 0;
    int somma = 0;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            somma += matrix[i][j];
        }
    }
    return medias = somma / (r*c);
}

void maxmin(int matrix[][dim], int r, int c, int& minimo, int& massimo){
    minimo = matrix[0][0];
    massimo = matrix[0][0];
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (matrix[i][j] > massimo)
            massimo = matrix[i][j];
            if (matrix[i][j] < minimo)
            minimo = matrix[i][j];
        }
    }
}

// se l’elemento è maggiore della media, il nuovo valore sarà dato dalla differenza tra l’elemento e il valore Minimo dell’array; 
// altrimenti sarà dato dalla somma tra l’elemento e il valore Massimo dell’array.

void nuovoarr(int matrix[][dim], int r, int c, double medi, int minimo, int massimo){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (matrix [i][j] > medi)
            matrix[i][j]-=minimo; 
            else 
            matrix[i][j]+=massimo;
        }
    }
}

void output(int matrix[][dim], int r, int c, string o){
    cout << o << endl;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << matrix[i][j] << "\t";
        }
       cout << endl;
    }
}