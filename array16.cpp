#include <iostream>
using namespace std;
//Preso in input un array di N interi, invertire l'ordine degli elementi e stampare l'array risultante.
const int dim = 100;

int main (){
int array [dim], array2 [dim], n = 0;
    do{

        cout << "Quanto è lungo il tuo array " << endl;
        cin >> n;   

    } while (n <= 0 || n > dim);

    for (int i = 0; i < n; i++){
        cout << "inserisci il " << i+1 << " numero" << endl;
        cin >> array [i];
    }

    for (int i = 0; i < n; i++){
        array2 [i]=array [n - 1 - i];   
    }
    for (int i = 0; i < n; i++){

        cout << "L'array finale e' " << array2 [i] << endl;
    }
}