// Preso in input un array di N interi, aumentare ciascuno dei suoi elementi del valore di x.

#include <iostream>
using namespace std;

const int dim = 100;

int inputn();
void inputarr(int numeri[dim], int n);
void aumentox(int numeri[dim], int n);

int main(){
    int numeri[dim];
    int n = inputn();
    inputarr(numeri, n);
    aumentox(numeri, n);
}

int inputn(){
    int n = 0;
    do{
        cout << "Inserisci la dimensione dell'array " << endl;
        cin >> n;
    } while (n <= 0 || n > dim);
    return n;
}

void inputarr(int numeri[dim], int n){
    int i = 0;
    do{
        cout << "Inserisci un numero " << endl;
        cin >> numeri[i];
        i++;
    } while (i < n);
}

//aumentare ciascuno dei suoi elementi del valore di x;

void aumentox(int numeri[dim], int n){
    int x = 0;
    cout << "Inserisci il valore di x " << endl;
    cin >> x;
    int i = 0;
    do{
        numeri[i] += x;
        cout << "il valore aumentato di x e' " << numeri[i] << endl;
        i++;
    } while (i < n);
}