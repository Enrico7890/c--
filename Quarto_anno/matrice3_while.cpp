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
    int i = 0;
    while (i < n){
        int j = 0;
        while (j < m){
            cout << "elemento " << i << " " << j << ": ";
            cin >> mat[i][j];
            j++;
        }
        i++;
    }
}

double media(double mat[][dim], int n, int m){
    double somma = 0;
    int i = 0;
    while (i < n){
        int j = 0;
        while (j < m){
            somma += mat[i][j];
            j++;
        }
        i++;
    }
    return somma / (n * m);
}

void creazionearr(double mat[][dim], int n, int m, double med, double min[], double mag[], int &cmin, int &cmag){
    int i = 0;
    while (i < n){
        int j = 0;
        while (j < m){
            if (mat[i][j] < med)
                min[cmin++] = mat[i][j];
            if (mat[i][j] > med)
                mag[cmag++] = mat[i][j];
            j++;
        }
        i++;
    }
}

void output(double min[], double mag[], int cmin, int cmag){
    int i = 0;
    while (i < cmin){
        cout << min[i] << " ";
        i++;
    }
    cout << endl;
    i = 0;
    while (i < cmag){
        cout << mag[i] << " ";
        i++;
    }
    cout << endl;
}