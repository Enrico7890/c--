#include <iostream>
using namespace std;

int main() {
    int numero;
    int somma = 0;
    int conteggio = 0;

    do {
        cout << "Inserisci un numero (0 per terminare): ";
        cin >> numero;

        if (numero != 0) {
            somma += numero;
            conteggio++;
        }

    } while (numero != 0);

    if (conteggio > 0) {
        double media = (double)somma / conteggio;
        cout << "La media è: " << media;
    } else {
        cout << "Nessun numero valido inserito.";
    }

    return 0;
}
