#include <iostream>

/* Preso in input un array di N caratteri, sostituire nell’array tutte le occorrenze 
   di una vocale con il carattere numerico "1". Generare poi un altro array che contenga 
   tutti gli elementi del primo array tranne gli "1". Infine visualizzare entrambi gli array. */

using namespace std;
 
const int dim = 100;

int inputN();
void inputArray(char arr[], int N);
void contaVocali(char arr[], int N);
int inputArray2(char arr[], char y[], int N);
void output(char arr[], char y[], int N, int k);

int main(){ 
    int N, k;
    char arr[dim], y[dim];

    N = inputN();
    inputArray(arr, N);
    contaVocali(arr, N);
    k = inputArray2(arr, y, N);
    output(arr, y, N, k);
}

int inputN(){  
    int N = 0;
    do {
        cout << "Inserisci la lunghezza del tuo array: ";
        cin >> N;
    } while (N <= 0 || N > dim); 
    return N;
}

void inputArray(char arr[], int N){
    for (int i = 0; i < N; i++) {
        cout << "Inserisci un carattere: ";
        cin >> arr[i];
    }
}

void contaVocali(char arr[], int N){
    for (int i = 0; i < N; i++) {
        if(arr[i]=='a' || arr[i]=='A' ||
           arr[i]=='e' || arr[i]=='E' ||
           arr[i]=='i' || arr[i]=='I' ||
           arr[i]=='o' || arr[i]=='O' ||
           arr[i]=='u' || arr[i]=='U'){
            arr[i] = '1';
        }
    }
}

int inputArray2(char arr[], char y[], int N){
    int k = 0;
    for (int i = 0; i < N; i++) {
        if(arr[i] != '1'){
            y[k] = arr[i];
            k++;
        }
    }
    return k;
}

void output(char arr[], char y[], int N, int k){
    cout << "Primo array ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] ;
}
    cout << "Secondo array ";
    for (int i = 0; i < k; i++) {
        cout << y[i];
    }
}