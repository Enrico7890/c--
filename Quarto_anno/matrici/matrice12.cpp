#include <iostream>
using namespace std;
/* ❇️ Data una matrice M di dimensione R x C di numeri reali e un array monodimensionale di reali V di dimensione R un array monodimensionale di interi Z di dimensione R: 
Prendere in input la matrice M.
Popolare l'array V inserendo in ciascuna posizione i la media aritmetica degli elementi presenti nella riga i-ma della matrice M.
Scorrendo nuovamente la matrice M, popolare l'array Z inserendo in ciascuna posizione i quanti elementi della riga i-ma della matrice sono strettamente maggiori del valore memorizzato nell'array V alla posizione i.
Stampare a schermo l'array V (valori medi di ciascuna riga della matrice) e l'array Z (numero totale di elementi di ciascuna riga della matrice che superano il valore medio). */

const int dim = 100;

int inputdim(string);
void inputmatrice(double [][dim], int, int);
void popolazionev(double [][dim], double[dim], int, int);
void popolazionez(double [][dim], double [dim], int[dim], int, int);
void output(double [dim], int [dim], int);

int main(){
    double mat [dim][dim];
    double vmain [dim];
    int zmain[dim];
    string u = "Inserisci righe ";
    int n = inputdim(u);
    u = "inserisci colonne";
    int m = inputdim(u);
    inputmatrice(mat, n, m);
    popolazionev(mat, vmain, n, m);
    popolazionez(mat, vmain, zmain, n, m);
    output(vmain, zmain, n);
}

int inputdim(string z){
    int num = 0;
    do{
        cout << z;
        cin >> num;
    }while (num <= 0|| num >dim);
    return num;
}

void inputmatrice(double matrice[][dim], int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << "inserisci elemento " << i << " " << j << endl;
            cin >> matrice[i][j];
        }
    }
}

// Popolare l'array V inserendo in ciascuna posizione i la media aritmetica degli elementi presenti nella riga i-ma della matrice M.

void popolazionev(double matrice [][dim], double v[dim], int r, int c){
    for (int i = 0; i < r; i++){
        double temp = 0;
        for (int j = 0; j < c; j++){
            temp += matrice[i][j];
        }
        v[i]=temp / c;
    }
}

// Scorrendo nuovamente la matrice M, popolare l'array Z inserendo in ciascuna posizione i quanti elementi della 
//riga i-ma della matrice sono strettamente maggiori del valore memorizzato nell'array V alla posizione i.


void popolazionez(double matrice [][dim], double v [dim], int z[dim], int r, int c){
    for (int i = 0; i < r; i++){
        int k = 0;
        for (int j = 0; j < c; j++){
            if(matrice[i][j]>v[i]){
                k++;
            }
        }
        z[i] = k;
    }
}

// Stampare a schermo l'array V (valori medi di ciascuna riga della matrice) e l'array Z (numero totale di elementi di ciascuna riga della matrice che superano il valore medio). */


void output(double v [dim], int z [dim], int r){
    cout << "valori medi di ciascuna riga della matrice" << endl;
    for (int i = 0; i < r; i++){
        cout << v[i] << endl;
    }
    cout << "numero totale di elementi di ciascuna riga della matrice che superano il valore medio" << endl;
    for (int i = 0; i < r; i++){
        cout << z[i] << endl;
    }
}   