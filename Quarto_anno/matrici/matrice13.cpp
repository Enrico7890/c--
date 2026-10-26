#include <iostream>
using namespace std;
/* Utilizzando l'approccio TOP-DOWN, scrivere il codice nel linguaggio C++, che risolve il seguente problema che utilizza insieme Array Bidimensionali e Array Monodimensionali:

❇️ Date due matrici A e B di dimensione N x M di numeri interi e due array monodimensionali R, di dimensione N,
e C di dimensione M: 
Prendere in input le matrici A e B.
Popolare l'array R inserendo in ciascuna posizione i il prodotto della somma di tutti gli elementi presenti nella riga i-ma della matrice A 
con la somma di tutti gli elementi presenti nella riga i-ma della matrice B.
Scorrendo nuovamente le matrici A e B, popolare l'array C inserendo in ciascuna posizione j quanti elementi della colonna j-ma della matrice A 
sono uguali ai corrispondenti elementi della colonna j-ma della matrice B (ovvero 
per ciascuna colonna j quante volte A[i][j] == B[i][j] al variare di i).
Stampare a schermo l'array R e l'array C. */

const int dim = 100;

int inputdim(string);
void inputmatrice(int [][dim], int , int, string);
void popolazioner(int [][dim], int b [][dim], int [dim], int , int );
void popolazionec(int [][dim], int  [][dim], int [dim], int , int );
void output(int [dim], int, string );

int main(){
    int mat[dim][dim];
    int mat2[dim][dim];
    int rarrmat[dim];
    int carrmat[dim];
    string u = "inserisci righe ";
    int n = inputdim(u);
    u = "inserisci colonne ";
    int m = inputdim(u);
    u = "prima matrice";
    inputmatrice(mat, n, m, u);
    u = "seconda matrice ";
    inputmatrice(mat2, n, m, u);
    popolazioner(mat, mat2, rarrmat, n, m);
    popolazionec(mat, mat2, carrmat, n, m);
    u = "output primo array r ";
    output(rarrmat, n, u);
    u = "output secondo array c";
    output(carrmat, m, u);
}

int inputdim(string z){
    int num = 0; 
    do{
        cout << z;
        cin >> num;
    } while (num <= 0 || num > dim);
    return num;
}

void inputmatrice(int a[][dim], int r, int c, string z){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << "inserisci elemento " << i << " " << j << " della " << z << endl;
            cin >> a[i][j];
        }
    }
}

// Popolare l'array R inserendo in ciascuna posizione i il prodotto della somma di tutti gli elementi presenti nella riga i-ma della matrice A 
// con la somma di tutti gli elementi presenti nella riga i-ma della matrice B.
void popolazioner(int a[][dim], int b[][dim],  int rar[dim], int r, int c){
    for (int i = 0; i < r; i++){
        int temp = 0;
        int temp2= 0;
        for (int j = 0; j < c; j++){
            temp += a[i][j];
            temp2 += b[i][j];
        }
        rar[i]=temp * temp2;
    }
}

// Scorrendo nuovamente le matrici A e B, popolare l'array C inserendo in ciascuna posizione j quanti elementi della colonna j-ma della matrice A 
//sono uguali ai corrispondenti elementi della colonna j-ma della matrice B (ovvero 
//per ciascuna colonna j quante volte A[i][j] == B[i][j] al variare di i).

void popolazionec(int a[][dim], int b[][dim], int carr[dim], int r, int c){
    for(int j = 0; j < c; j++){
        int k = 0;
        for (int i = 0; i < r ; i++){
            if (a[i][j]==b[i][j]){
                k++;
            }
        }
        carr[j] = k;
    }
}

// Stampare a schermo l'array R e l'array C. */

void output(int arr[dim], int r, string u){
    cout << u << endl;
    for (int i = 0; i < r; i++){
        cout << arr[i] << endl;
    }

}