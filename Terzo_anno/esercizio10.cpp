#include <iostream>
using namespace std;

int main() {
    int N, N1, prodotto;
    prodotto = 0;

    cout << "Inserisci il primo numero" << endl;
    cin >> N;

    cout << "Inserisci il secondo numero" << endl;
    cin >> N1;

    for (int i = 0; i < N1 ; i++){
     prodotto+=N; 
    }
    cout << il prodotto e' << prodotto;
}