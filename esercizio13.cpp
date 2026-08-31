#include <iostream>
using namespace std;

int main() {
    int x, y;
    int prodotto = 1;

    cout << "Inserisci x: ";
    cin >> x;

    cout << "Inserisci y: ";
    cin >> y;

    for (int i = 1; i <= y; i++) {
        prodotto = prodotto * x;
    }

    cout << "Il risultato è: " << prodotto;
}