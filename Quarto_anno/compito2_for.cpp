//Preso in input un array di N interi, aumentare ciascuno dei suoi elementi del valore di x. (Suggerimento: prima si prende in input il valore x, 
//poi si ricalcolano i valori di tutti gli elementi...)

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

// input dimensione;

int inputn(){
    int n = 0;
    do{
        cout << "Inserisci la dimensione dell'array " << endl;
        cin >> n;
    }while (n <= 0 || n> dim);
    return n;
}

// input array;

void inputarr(int numeri[dim], int n){
    for (int i = 0; i < n; i++){
        cout << "inserisci un numero " << endl;
        cin >> numeri[i];
    }
}

//aumentare ciascuno dei suoi elementi del valore di x;

void aumentox(int numeri[dim], int n){
    int x = 0;
    cout << "inserisci il valore di x " << endl;
    cin >> x;
    for (int i = 0; i < n; i++){
        numeri[i]+=x;
        cout << "il valore aumentato di x e' " << numeri[i] << endl;
    }
}