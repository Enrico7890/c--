// preso in input un array bidimensionale di dimensioni n x m di reali,
// calcolare la media dei suoi elementi e creare due array monodimensionali:
// il primo con i valori minori della media, il secondo con i valori maggiori.

#include <iostream>
using namespace std;

const int dim = 100;

int inputn();
void inputmatrice(double [][dim], int, int);
double media(double [][dim], int, int);
void creazionearr(double [][dim], int, int, double, double[], double[], int&, int&);
void output(double[], double[], int, int);

int main(){
    double k[dim][dim];
    double minori[dim*dim], maggiori[dim*dim];
    int cmin = 0, cmag = 0;
    int n = inputn();
    int m = inputn();
    inputmatrice(k, n, m);
    double med = media(k, n, m);
    creazionearr(k, n, m, med, minori, maggiori, cmin, cmag);
    output(minori, maggiori, cmin, cmag);
}

int inputn(){
    int num;
    do {
        cout << "inserisci dimensione di righe prima e poi colonne" << endl;
        cin >> num;
    } while (num <= 0 || num > dim);
    return num;
}

void inputmatrice(double mat[][dim], int n, int m){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cout << "elemento " << i << " " << j << ": ";
            cin >> mat[i][j];
        }
}

double media(double mat[][dim], int n, int m){
    double somma = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            somma += mat[i][j];
    return somma / (n * m);
}

void creazionearr(double mat[][dim], int n, int m, double med, double min[], double mag[], int &cmin, int &cmag){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            if (mat[i][j] < med)
                min[cmin++] = mat[i][j];
            if (mat[i][j] > med)
                mag[cmag++] = mat[i][j];
        }
}

void output(double min[], double mag[], int cmin, int cmag){
    for (int i = 0; i < cmin; i++)
        cout << min[i] << " ";
    cout << endl;
    for (int i = 0; i < cmag; i++)
        cout << mag[i] << " ";
    cout << endl;
}