#include <iostream>
#include <cstdlib>
using namespace std;

/* Preso in input un array di N interi, rideterminare i valori dei suoi elementi secondo il seguente criterio: 
per ciascun elemento determinare prima di tutto un numero casuale compreso tra il valore Minimo e il valore Massimo
di tutti gli elementi dell'array. Successivamente il nuovo valore sarà dato dal valore dell'elemento dell'array 
sommato al valore casuale trovato e al Massimo e sottratto del Minimo.  */

const int dim = 100;

int inputN();
void inputarr(int [], int);
void maxmin (int [], int, int&, int&);
void casuale(int, int&, int&, int&);
void nuovoval (int [], int [], int, int, int, int);
void output (int [], int );

int main (){
    int n = 0, max, min, numero;
    int arr[dim], arr2[dim];

    n = inputN();

    inputarr(arr, n);

    maxmin (arr, n, max, min);

    casuale (n, numero, max, min);

    nuovoval(arr, arr2, n, numero, max, min);

    output (arr2, n);

    return 0;
}

int inputN(){
    int n = 0;
    do{
        cout << "inserisci dimensione dell'array " << endl;
        cin >> n;
    } while (n <= 0 || n > dim);
    return n;
}

void inputarr (int arr[], int n){
    for (int i = 0; i < n; i++){
    cout << "inserisci elemento dell'array " << endl;
    cin >> arr[i];
    }
}

void maxmin (int arr[], int n, int& max, int& min){
    max = arr[0];
    min = arr[0];

    for (int i = 0; i < n; i++){
        if (arr[i] > max)
        max = arr[i];
        if (arr[i] < min)
        min = arr[i];
    }
}

void casuale (int n, int& numero, int& max, int& min){
    srand(1);
    numero = min + (rand() % (max - min + 1));
}

void nuovoval (int arr[], int arr2[], int n, int numero, int max, int min){
    for (int i = 0; i < n; i++){
        arr2[i]=arr[i]+numero + (max - min);
    }
}

void output (int arr2[], int n){

    cout << "il nuovo array e' " << endl;
    for (int i = 0; i < n; i++){
        cout << arr2[i] << endl;
    }
}