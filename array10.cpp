#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int dim = 100;

int main() {

    int array[dim], pari[dim], dispari[dim];
    int n, p = 0, d = 0;

    do {
        cout << "Quanto e' lungo il tuo array ";
        cin >> n;
    } while (n <= 0 || n > dim);
    
    srand(time(0));

    
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 101;
    }

    for (int i = 0; i < n; i++) {
        if (array[i] % 2 == 0) {
            pari[p] = array[i];
            p++;
        } else {
            dispari[d] = array[i];
            d++;
        }
    }

    cout << "Array originale" << endl;
    for (int i = 0; i < n; i++) {
        cout << array[i] << "" << endl;
    }

    cout << endl << "Numeri pari" << endl;
    for (int i = 0; i < p; i++) {
        cout << pari[i]<< "" << endl;;
    }

    cout << endl << "Numeri dispari" << endl;
    for (int i = 0; i < d; i++) {
        cout << dispari[i]<< "" << endl;;
    }
}