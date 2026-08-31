#include <iostream>
using namespace std;
//Preso in input un array di N interi, creare un secondo array contenente solo gli elementi che si trovano in posizione pari
// (indice 0, 2, 4...) e stamparlo.
const int dim = 100;

int main (){
int array [dim], array2 [dim], n = 0, c = 0;

do{
    cout << "quanto e' lungo il tuo array " << endl;
    cin >> n;
} while (n <= 0 || n > dim);

for (int i = 0; i < n; i++){
    cout << "inserisci un numero per l'array " << endl;
    cin >> array [i];
}

for (int i = 0; i < n; i++){
    if (i % 2 == 0){
        array2[c++]=array[i];
    }
} 
    cout << "I numeri in posizione pari sono " << endl;
for (int i = 0 ; i < c ; i++){
    cout << array2 [i] << endl;
    } 
}