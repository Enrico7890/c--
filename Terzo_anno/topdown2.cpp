#include <iostream>
using namespace std;
//Preso in input un array di N interi, determinare il valore Minimo e il valore Massimo dei suoi elementi.
 
const int dim = 100;

void inputN(int &n);
void inputArray(int arr[], int n);
int trovaminimo(int arr[], int n, int i = 0);
int trovamassimo(int arr[], int n, int i = 0);
void output(int minimo, int massimo);

int main() {
    int n, arr[dim];
    int minimo, massimo;
    
    inputN(n);
    inputArray(arr, n);
    minimo = trovaminimo(arr, n);
    massimo = trovamassimo(arr, n);
    output(minimo, massimo);
}

void inputN(int &n) {
    do {
        cout << "Inserisci la lunghezza del tuo array ";
        cin >> n;
    } while (n <= 0 || n > dim);
}

void inputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Inserisci un numero ";
        cin >> arr[i];
    }
}

int trovaminimo(int arr[], int n, int i = 0) {
    if (i == n - 1) 
        return arr[i];
    int min = trovaminimo(arr, n, i + 1);
    if (arr[i] < min) 
        return arr[i];
    else 
        return min;
}
 
int trovamassimo(int arr[], int n, int i = 0) {
    if (i == n - 1) 
        return arr[i];
    int max = trovamassimo(arr, n, i + 1);
    if (arr[i] > max) 
        return arr[i];
    else 
        return max;
}
 
void output(int minimo, int massimo) {
    cout << "valore minimo " << minimo << endl;
    cout << "valore massimo " << massimo << endl;
}