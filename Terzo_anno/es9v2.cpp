#include <iostream>
using namespace std;

int main() {
    int N, N1, negativo, positivo;
    positivo = 0;
    negativo = 0;

    cout << "Inserisci un numero" << endl;
    cin >> N;

    do {
     if (N != 0){
        if (N > 0){
                positivo++;
            }
            else if (N < 0){
                negativo++;
                
            }
        }
        cout << "inserisci un numero" << endl;
        cin >> N;
    } while (N != -1);

    cout << "Positivi " << positivo << endl;
    cout << "Negativi " << negativo << endl;


}