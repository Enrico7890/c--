#include <iostream>
using namespace std;

//Preso in input un array di N interi, rideterminare i valori dei suoi elementi secondo il seguente criterio:
// per ciascun elemento il nuovo valore sarà dato dal valore dell'elemento stesso sommato al valore Massimo e 
//sottratto del Minimo (precedentemente trovati)

 
int main() {
    const int dim = 100;
    int array[dim];
    int n;
    
    do {
        cout << "Inserisci il numero di elementi ";
        cin >> n;
        if (n <= 0 || n > dim) {
            cout << "Errore! Inserisci un numero tra 1 e " << dim;
        }
    } while (n <= 0 || n > dim);
    
    cout << "Inserisci gli elementi";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    
    int max_val = array[0];
    int min_val = array[0];
    
    for (int i = 1; i < n; i++) {
        if (array[i] > max_val) max_val = array[i];
        if (array[i] < min_val) min_val = array[i];
    }
    
    cout << "Max: " << max_val << ", Min: " << min_val;
    cout << "Array modificato";
    
    for (int i = 0; i < n; i++) {
        int vecchio = array[i];
        array[i] = array[i] + max_val - min_val;
        cout << "array" << i << vecchio << array[i];
    }
}