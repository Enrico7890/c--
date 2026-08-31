//Preso in input un array di N interi (N viene preso precedentemente in input), determinare il numero dei suoi elementi positivi e dei suoi elementi negativi. 
//Determinare infine la somma di tutti gli elementi che si trovano in posizione dispari e quella degli elementi che si trovano in posizione pari.

#include <iostream>
using namespace std;
 
const int dim = 100;
 
int inputDim();
void inputVett(int arr[], int d);
int contaPositivi(int arr[], int d);
int contaNegative(int arr[], int d);
int sommaPosizioniDispari(int arr[], int d);
int sommaPosizioniPari(int arr[], int d);
void output(int pos, int neg, int sommaPari, int sommaDispari);
 
int main() {
    int N;
    int positivi, negativi, sommaPari, sommaDispari;
    int vett[dim];
    
    cout << "Inserimento dimensione vettore " << endl;
    N = inputDim();
    
    cout << "Inserimento valori vettore " << endl;
    inputVett(vett, N);
    
    positivi = contaPositivi(vett, N);
    negativi = contaNegative(vett, N);
    sommaPari = sommaPosizioniPari(vett, N);
    sommaDispari = sommaPosizioniDispari(vett, N);
    
    cout << "Risultati dell'analisi del vettore " << endl;
    output(positivi, negativi, sommaPari, sommaDispari);
}
 
int inputDim(){
    int d;
    do {
        cout << "Inserisci il numero di elementi " << endl;
        cin >> d;
    } while((d <= 0) || (d > dim));
    return d;
}
 
void inputVett(int arr[], int d){
    for (int i = 0; i < d; i++) {
        cout << "Inserisci vettore ";
        cin >> arr[i];
    }
    cout << endl;
}
 
int contaPositivi(int arr[], int d){
    int conta = 0;
    for (int i = 0; i < d; i++) {
        if (arr[i] > 0) {
            conta++;
        }
    }
    return conta;
}
 
int contaNegative(int arr[], int d){
    int conta = 0;
    for (int i = 0; i < d; i++) {
        if (arr[i] < 0) {
            conta++;
        }
    }
    return conta;
}
 
int sommaPosizioniPari(int arr[], int d){
    int somma = 0;
    for (int i = 0; i < d; i += 2) {  
        somma += arr[i];
    }
    return somma;
}
 
int sommaPosizioniDispari(int arr[], int d){
    int somma = 0;
    for (int i = 1; i < d; i += 2) {  
        somma += arr[i];
    }
    return somma;
}
 
void output(int pos, int neg, int sommaPari, int sommaDispari){
    cout << "Numero di elementi positivi " << pos << endl;
    cout << "Numero di elementi negativi " << neg << endl;
    cout << "Somma elementi in posizioni pari " << sommaPari << endl;
    cout << "Somma elementi in posizioni dispari " << sommaDispari << endl;
}