#include <iostream>
using namespace std;

//Presi in input due array di reali, della stessa dimensione N, determinare un altro array (anch'esso di dimensione N)
// i cui elementi sono la somma dei corrispondenti elementi degli array iniziali.

const int dim = 100;

int main (){
double array [dim], array2 [dim], array3 [dim];
int n = 0;

do{
    cout << "inserisci la lunghezza del tuo array " << endl;
    cin >> n;
}while (n<=0 || n > dim);

for (int i = 0; i < n; i++){

    cout << "Inserisci un numero per il primo array " << endl;
    cin >> array [i];
    cout << "Inserisci un numero per il secondo array " << endl;
    cin >> array2 [i];
}

for (int i = 0; i < n; i++){
    array3[i]=array[i]+ array2[i];
}

for (int i = 0; i < n; i++){

    cout << "L'array e' " << array3 [i];
    }
}