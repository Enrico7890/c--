#include <iostream>
using namespace std;

//Preso in input un array di N numeri reali e altri tre numeri a parte, 
//modificare ciascun elemento dell'array coincidente con il primo valore inserito in modo tale che esso contenga un nuovo valore 
//uguale a sé stesso, sommato al secondo e sottratto del terzo

 
int main() {
    const int dim = 100;
    double array[dim];
    int n;
    
    do {
        cout << "Inserisci il numero di elementi: ";
        cin >> n;
        if (n <= 0 || n > dim) {
            cout << "Errore! Inserisci un numero tra 1 e " << dim ;
        }
    } while (n <= 0 || n > dim);
    
    cout << "Inserisci gli elementi";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    
    double valore, somma, sottrai;
    cout << "Valore da cercare: ";
    cin >> valore;
    cout << "Valore da sommare: ";
    cin >> somma;
    cout << "Valore da sottrarre: ";
    cin >> sottrai;
    
    cout << "\nModifiche:\n";
    for (int i = 0; i < n; i++) {
        if (array[i] == valore) {
            cout << "Posizione " << i << ": " << array[i];
            array[i] = array[i] + somma - sottrai;
            cout << " -> " << array[i];
        }
    }
    
    cout << "Array finale "<< endl;
    for (int i = 0; i < n; i++) {
        cout << "array" << i << " = " << array[i];
    }   
}