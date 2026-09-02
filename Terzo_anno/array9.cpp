// Preso in input un array di N interi, rideterminare il valore di ciascun suo elemento in questo modo: se pari esso assumerà il quadrato del valore iniziale, se dispari invece conterrà il cubo del valore iniziale.
#include <iostream>
using namespace std;

const int dim = 100;

int main (){
int array [dim], n, cubo, quadrato;

do  {
        cout << "Inserisci quanti numeri vuoi nell'array" << endl;
        cin >> n;
    }while(n <= 0 || n > dim);

for (int i = 0; i < n; i++){

    cout << "Inserisci un valore" << endl;
    cin >> array [i];
}
for (int i = 0; i < n; i++){
    if (array [i] % 2 == 0){
        quadrato=array[i]*array [i]; 
        array [i]=quadrato;  
    } 
    else if (array [i] % 2 != 0){
        cubo=array[i]*array[i]*array[i];
        array [i]=cubo;  

        }
    }
for (int i = 0; i < n; i++){

    cout << array [i] << endl;
    }
}