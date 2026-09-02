#include <iostream>
using namespace std;

int main(){
int N, N1, somma, prodotto;

somma = 0;
prodotto = 1;

cout << "inserisci quanto e' lunga la successione" << endl;
cin >> N;

for (int i=0; i<N; i++){

cout << "inserisci un numero" << endl;
cin >> N1;

somma = somma+N1;
prodotto = prodotto*N1;

}

    cout << "la somma e' " << somma << endl;
    cout << "il prodotto e' " << prodotto << endl;
}