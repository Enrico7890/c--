#include <iostream>
using namespace std;
// Preso in input un array di N caratteri, trasformare tutti i caratteri alfabetici Minuscoli nei corrispondenti caratteri Maiuscoli e, 
//viceversa, tutti i caratteri alfabetici Maiuscoli in Minuscoli (Es.: se vet[i]='d' allora sarà vet[i] = 'D'; se vet[i]='B' allora sarà vet[i]='b'; se vet[i]='@' nulla deve accadere)

const int dim = 100;
int main(){
char array [dim];
int n;

do {
    cout << "Inserisci la lunghezza del tuo array " << endl;
    cin >> n;
} while (n <= 0 || n > dim);

for (int i = 0; i < n; i++){

    cout << "insersci un carattere " << endl;
    cin >> array [i];
}

    for (int i = 0; i < n; i++){
        if (array[i] >= 'a' && array[i] <= 'z') {
        array[i] = array[i] - 32;
    }
    else if (array[i] >= 'A' && array[i] <= 'Z') {
    array[i] = array[i] + 32;
        }
    }
for (int i = 0; i < n; i++){
    cout << "L'array finale e' " << array [i] << endl;
    }
}