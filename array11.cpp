#include <iostream>
using namespace std;

const int dim = 100;

int main() {

    char a[dim], b[dim], c[dim];
    int n, k = 0;

    do {
        cout << "Inserisci la dimensione degli array ";
        cin >> n;
    } while(n <= 0 || n > dim);

    cout << "Inserisci i caratteri del primo array " << endl;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << "Inserisci i caratteri del secondo array " << endl;
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    for(int i = 0; i < n; i++){
        c[k] = a[i];
        k++;
        c[k] = b[i];
        k++;
    }

    cout << "Terzo array alternato " << endl;
    for(int i = 0; i < 2*n; i++){
        cout << c[i];
    }
}