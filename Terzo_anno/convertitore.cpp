#include <iostream>
using namespace std;

int main() {
    int numero;
    int binario[32];
    int i = 0;

    cout << "Inserisci un numero decimale: ";
    cin >> numero;

    if (numero == 0) {
        cout << "Il numero in binario è: 0";
        return 0;
    }

    while (numero > 0) {
        binario[i] = numero % 2;
        numero = numero / 2;
        i++;
    }

    cout << "Il numero in binario e': ";
    for (int j = i - 1; j >= 0; j--) {
        cout << binario[j];
    }

    return 0;
}
