#include <iostream>
using namespace std;

const int R = 3;
const int C = 3;

void leggi(int m[][C]);
void stampa(int m[][C]);
void massimo(int m[][C]);
void sommaRighe(int m[][C]);

int main() {
    int m[R][C];
    leggi(m);
    stampa(m);
    massimo(m);
    sommaRighe(m);
}

void leggi(int m[][C]) {
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            cout << "m[" << i << "][" << j << "]: ";
            cin >> m[i][j];
        }
}

void stampa(int m[][C]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cout << m[i][j] << "\t";
        cout << endl;
    }
}

void massimo(int m[][C]) {
    int max = m[0][0];
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (m[i][j] > max)
                max = m[i][j];
    cout << "Massimo: " << max << endl;
}

void sommaRighe(int m[][C]) {
    for (int i = 0; i < R; i++) {
        int s = 0;
        for (int j = 0; j < C; j++)
            s += m[i][j];
        cout << "Riga " << i << ": " << s << endl;
    }
}