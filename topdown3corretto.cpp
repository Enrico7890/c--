//Preso in input un array di N interi (N viene preso precedentemente in input), 
//determinare il numero dei suoi elementi positivi e dei suoi elementi negativi. 
//Determinare infine la somma di tutti gli elementi che si trovano in posizione dispari 
//e quella degli elementi che si trovano in posizione pari.

#include <iostream>
using namespace std;
 
const int dim = 100; 
 
int inputDim();
void inputVett(int [], int );
void conta(int [], int, int &, int &);      
int somma(int [], int, int &);              
void output(int , int , int , int );
 
int main() {
    int N;
    int positivi, negativi, sommaPari, sommaDispari;
    int vett[dim];
    
    cout << "Inserimento dimensione vettore " << endl;
    N = inputDim();
    
    cout << "Inserimento valori vettore " << endl;
    inputVett(vett, N);
    
    conta(vett, N, positivi, negativi);
 
    sommaPari = somma(vett, N, sommaDispari);  
 
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
        cout << "Inserisci il numero " << i + 1 << endl;
        cin >> arr[i];
    }
    cout << endl;
}
 
void conta(int arr[], int d, int &pos, int &neg){
    pos = 0;
    neg = 0;
    for (int i = 0; i < d; i++) {
        if (arr[i] > 0) {
            pos++;
        }
        else if (arr[i] < 0) {
            neg++;
        }
    }
}

int somma(int arr[], int d, int &sommadisp){
    int sommapos = 0;
    sommadisp = 0;
    for (int i = 0; i < d; i++) {
        if (i % 2 == 0)
            sommapos += arr[i];
        else
            sommadisp += arr[i];
    }
    return sommapos;
}
 
void output(int pos, int neg, int sommaPari, int sommaDispari){
    cout << "Numero di elementi positivi " << pos << endl;
    cout << "Numero di elementi negativi " << neg << endl;
    cout << "Somma elementi in posizioni pari " << sommaPari << endl;
    cout << "Somma elementi in posizioni dispari " << sommaDispari << endl;
}