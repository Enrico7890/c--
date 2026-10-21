#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int dim = 100;

int inputn(string);
void inputmatrice(int [][dim], int, int);
void minmax(int [][dim], int, int, int &, int &);
int casuale(int, int);
void modifica(int [][dim], int, int);
void output(int [][dim], int, int);

int main(){
    int mat[dim][dim];
    int n, m;
    string u;

    srand(time(NULL));
    u = "inserisci righe ";
    n = inputn(u);
    u = "inserisci colonne ";
    m = inputn(u);
    inputmatrice(mat, n, m);
    output(mat, n, m);
    modifica(mat, n, m);
    output(mat, n, m);
}

int inputn(string z){
    int num = 0;
    do{
        cout << z;
        cin >> num;
    }   while (num <= 0 || num > dim);
    return num;
}

void inputmatrice(int k[][dim], int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << "inserisci componente " << i << " " << j << endl;
            cin >> k[i][j];
        }
    }
}

void minmax(int k[][dim], int r, int c, int &mn, int &mx){
    mn = k[0][0];
    mx = k[0][0];
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (k[i][j] < mn)
                mn = k[i][j];
            if (k[i][j] > mx)
                mx = k[i][j];
        }
    }
}

int casuale(int mn, int mx){
    return mn + rand() % (mx - mn + 1);
}

void modifica(int k[][dim], int r, int c){
    int mn, mx, ran;

    minmax(k, r, c, mn, mx);

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            ran = casuale(mn, mx);
            k[i][j] = k[i][j] + ran + mx - mn;
        }
    }
}

void output(int k[][dim], int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << k[i][j] << " ";
        }
        cout << endl;
    }
}