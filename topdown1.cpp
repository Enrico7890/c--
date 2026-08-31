#include <iostream>
using namespace std;

//Preso in input un Array di N interi, ed un altro intero a parte, 
//contare quante volte quest'ultimo viene ripetuto all'interno dell'array.
 
const int dim = 100;

void inputN(int &n);
void inputArray(int arr[], int n);
void inputValore(int &valore);
int conta(int arr[], int n, int valore, int i = 0);
void output(int risultato);

int main() {
    int n, valore, arr[dim];
    int risultato;
    
    inputN(n);
    inputarray(arr, n);
    inputvalore(valore);
    risultato = conta(arr, n, valore);
    output(risultato);
}

void inputN(int &n) {
    do {
        cout << "inserisci la lunghezza del tuo array " << endl;
        cin >> n;
    } while (n <= 0 || n > dim);
}

void inputarray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "inserisci un numero " << endl;
        cin >> arr[i];
    }
}

void inputvalore(int &valore) {
    cout << "valore da cercare ";
    cin >> valore;
}

int conta(int arr[], int n, int valore, int i = 0) {
    if (i >= n)
    return 0;
    if (arr[i] == valore) 
        return 1 + conta(arr, n, valore, i + 1);
    else 
        return conta(arr, n, valore, i + 1);
} 
void output(int risultato) {
    cout << "ripetizioni " << risultato << endl;
}