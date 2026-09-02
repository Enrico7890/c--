#include <iostream>
using namespace std;
 
/* Presi in input due array di reali, della stessa dimensione N, determinare altri due array (anch'essi di dimensione N) 
i cui elementi sono in un caso il prodotto e nell'altro la media dei corrispondenti elementi degli array iniziali*/

int inputN();
void inputArray(double [], int);
void calcolaProdotto(double [], double [], double [], int);
void calcolaMedia(double [], double [], double [], int);
void output(double [], double [], double [], double [], int);
 
const int DIM = 100;
 
int main() {
    int N;
    double arr1[DIM], arr2[DIM];
    double prodotto[DIM], media[DIM];
    
    N = inputN();
    
    inputArray(arr1, N);
    
    inputArray(arr2, N);
    
    calcolaProdotto(arr1, arr2, prodotto, N);
    
    calcolaMedia(arr1, arr2, media, N);
    
    output(arr1, arr2, prodotto, media, N);
}
 
int inputN() {
    int n = 0;
    do {
        cout << "Inserisci la dimensione degli array " << endl;
        cin >> n;
    } while ((n <= 0) || (n > DIM));
    return n;
}
 
void inputArray(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Inserisci elemento dell'array ";
        cin >> arr[i];
    }
    cout << endl;
}
 
void calcolaProdotto(double arr1[], double arr2[], double prodotto[], int n) {
    for (int i = 0; i < n; i++) {
        prodotto[i] = arr1[i] * arr2[i];
    }
}
 
void calcolaMedia(double arr1[], double arr2[], double media[], int n) {
    for (int i = 0; i < n; i++) {
        media[i] = (arr1[i] + arr2[i]) / 2;
    }
}
 
void output(double arr1[], double arr2[], double prodotto[], double media[], int n) {

    cout << "Array iniziale 1 ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    cout << "Array iniziale 2 ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    cout << "Prodotto ";
    for (int i = 0; i < n; i++) {
        cout << prodotto[i] << " ";
    }
    cout << endl;
    
    cout << "Media ";
    for (int i = 0; i < n; i++) {
        cout << media[i] << " ";
    }
    cout << endl;
}