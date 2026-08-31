#include <iostream>
using namespace std;

int main() {
    int N, array[100];
    int somma = 0;
    int prodotto = 1;

    cout << "Quanti numeri ";
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> array [i];

        if(array[i] > 0){
            somma = somma + array[i];
        }

        if(array[i] < 0){
            prodotto = prodotto * array[i];
        }
    }

    cout << "Somma positivi " << somma << endl;
    cout << "Prodotto negativi " << prodotto << endl;
}